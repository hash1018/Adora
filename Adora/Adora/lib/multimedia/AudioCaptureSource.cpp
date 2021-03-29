
#include "AudioCaptureSource.h"
#include <qdebug.h>
#include "Base/Time.h"

#ifdef Q_OS_WIN

#include <Functiondiscoverykeys_devpkey.h>
#include <combaseapi.h>

#define REFTIMES_PER_SEC  10000000
#define REFTIMES_PER_MILLISEC  10000

const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
const IID IID_IAudioClient = __uuidof(IAudioClient);
const IID IID_IAudioCaptureClient = __uuidof(IAudioCaptureClient);


#endif


AudioCaptureSource::AudioCaptureSource(Time *mainTime, const AudioCodecInfo &codecInfo, const AudioParameter &parameter, QObject *parent)
	:QThread(parent), mainTime(mainTime), codecInfo(codecInfo), parameter(parameter) {

	this->hnsRequestedDuration = REFTIMES_PER_SEC;

	this->totalPushedtoQueueCount = 0;


	this->audioFrameQueue = new AudioFrameQueue;

}

AudioCaptureSource::~AudioCaptureSource() {

	qDebug() << "AudioCaptureSource::~AudioCaptureSource";
	this->clear();

	if (this->audioFrameQueue != nullptr)
		delete this->audioFrameQueue;
}

void AudioCaptureSource::run() {

	qDebug() << "AudioCaptureSource run " << this->currentThreadId();


	this->requestToFinish = false;
	this->noNeedToPushQueueMore = false;

	this->cycleTimeByOneFrame = (this->getFrameSize()*1.00000) / (this->codecInfo.sampleRate / 1.00000);

	qDebug() << "cycleTimeByOneFrame " << this->cycleTimeByOneFrame;

#ifdef Q_OS_WIN

	int second = 0;
	int totalPacketLength = 0;
	this->bitsIndex = 0;

	emit this->captureReady();

	HANDLE handle = CreateEventEx(NULL, NULL, 0, EVENT_MODIFY_STATE | SYNCHRONIZE);

	HRESULT result2 = this->audioClient->Start();
	
	if (FAILED(result2) == true) {

		qDebug() << "Start Failed";
		return;
	}

	uint8_t *totalBuffer = new uint8_t[this->waveFormat->nSamplesPerSec * this->waveFormat->nBlockAlign];
	int totalBufferIndex = 0;
	uint8_t muteBuffer[OneFrameBufferSize];
	
	
	
	while (1) {

		WaitForSingleObject(handle, this->hnsActualDuration / REFTIMES_PER_MILLISEC / 2);
		
		this->captureClient->GetNextPacketSize(&packetLength);
		
		if (packetLength != 0) {

			while (packetLength != 0) {
				
				this->captureClient->GetBuffer(&this->data, &numFramesAvailable, &flags, NULL, NULL);
				
				totalPacketLength += numFramesAvailable;

				if (totalPacketLength >= this->waveFormat->nSamplesPerSec) {

					second++;
					totalPacketLength -= this->waveFormat->nSamplesPerSec;
				}

				if (this->requestToFinish == false) {
					this->append(totalBuffer, totalBufferIndex, this->data, numFramesAvailable);
				}
				else {

					this->appendLast(totalBuffer, totalBufferIndex, this->data, numFramesAvailable);
				}

				this->captureClient->ReleaseBuffer(numFramesAvailable);
				this->captureClient->GetNextPacketSize(&packetLength);
			}

		}
		else {

			this->totalCountToBePushedQueue = this->convertTotalPushedToQueueCount(*this->mainTime);
			int diff = this->totalCountToBePushedQueue - this->totalPushedtoQueueCount;

			for (int i = 0; i < diff; i++) {
				
				totalPacketLength += 1024;

				if (totalPacketLength >= this->waveFormat->nSamplesPerSec) {

					second++;
					totalPacketLength -= this->waveFormat->nSamplesPerSec;
				}

				if (this->requestToFinish == false) {
					this->append(totalBuffer, totalBufferIndex, muteBuffer, 1024);
				}
				else {

					this->appendLast(totalBuffer, totalBufferIndex, muteBuffer, 1024);
				}
			}
		}

		if (this->noNeedToPushQueueMore == true)
			break;
			
	}



	this->audioClient->Stop();

	delete[] totalBuffer;
	

#endif 
}

void AudioCaptureSource::quit() {
	qDebug() << "asdasd";
	this->requestToFinish = true;
	this->totalCountToBePushedQueue = this->convertTotalPushedToQueueCount(*this->mainTime);
}

void AudioCaptureSource::append(uint8_t *totalBuffer, int &totalBufferIndex, uint8_t *buffer, int length) {

	int maxBufferSize = this->waveFormat->nSamplesPerSec * this->waveFormat->nBlockAlign;
	int bufferSize = length * this->waveFormat->nBlockAlign;

	if (totalBufferIndex + bufferSize < maxBufferSize) {

		memcpy(totalBuffer + totalBufferIndex, buffer, bufferSize);
		totalBufferIndex += bufferSize;
	}
	else {

		int difference = (totalBufferIndex + bufferSize) - maxBufferSize;

		if (difference == 0) {

			memcpy(totalBuffer + totalBufferIndex, buffer, bufferSize);
			this->resampleAndPush(totalBuffer, this->waveFormat->nSamplesPerSec);
			totalBufferIndex = 0;
		}
		else {

			memcpy(totalBuffer + totalBufferIndex, buffer, (bufferSize - difference));
			this->resampleAndPush(totalBuffer, this->waveFormat->nSamplesPerSec);
			totalBufferIndex = 0;
			memcpy(totalBuffer + totalBufferIndex, buffer + (bufferSize - difference), difference);
			totalBufferIndex += difference;
		}
	}
}


void AudioCaptureSource::resampleAndPush(uint8_t *buffer, int length) {

	const uint8_t *out = NULL;
	int outBufferIndex = 0;

	this->totalCountToBePushedQueue = this->convertTotalPushedToQueueCount(*this->mainTime);


	int bufferSize;

	if (this->resampler.resample(buffer, length, &out, bufferSize) == true) {

		int remainder = bufferSize % OneFrameBufferSize;
		int quotient = bufferSize / OneFrameBufferSize;

		for (int i = 0; i < quotient; i++) {

			const uint8_t *oneFrameBuffer = out + (i * OneFrameBufferSize);

			if (this->bitsIndex == 0) {

				memcpy(this->bits, oneFrameBuffer, OneFrameBufferSize);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {
					
						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();
					


					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;
				}
				else {

					//qDebug() << "audioDrop";
				}
			}
			else {

				int difference = OneFrameBufferSize - this->bitsIndex;

				memcpy(this->bits + this->bitsIndex, oneFrameBuffer, difference);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();


					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;
				}
				else {

					//qDebug() << "audioDrop";
				}

				this->bitsIndex = 0;
				memcpy(this->bits + this->bitsIndex, oneFrameBuffer + difference, OneFrameBufferSize - difference);
				this->bitsIndex += OneFrameBufferSize - difference;
			}
		}

		const uint8_t *remainderFrameBuffer = out + (OneFrameBufferSize*quotient);

		if (this->bitsIndex + remainder < OneFrameBufferSize) {

			memcpy(this->bits + this->bitsIndex, remainderFrameBuffer, remainder);
			this->bitsIndex += remainder;
		}
		else {

			int difference = (this->bitsIndex + remainder) - OneFrameBufferSize;

			if (difference == 0) {

				memcpy(this->bits + this->bitsIndex, remainderFrameBuffer, remainder);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();



					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;
				}
				else {

					//qDebug() << "audioDrop";
				}

				this->bitsIndex = 0;
			}
			else {

				memcpy(this->bits + this->bitsIndex, remainderFrameBuffer, remainder - difference);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();



					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;
				}
				else {

					//qDebug() << "audioDrop";
				}

				this->bitsIndex = 0;
				memcpy(this->bits + this->bitsIndex, remainderFrameBuffer + remainder - difference, difference);
				this->bitsIndex += difference;
			}
		}
	}
}


void AudioCaptureSource::appendLast(uint8_t *totalBuffer, int &totalBufferIndex, uint8_t *buffer, int length) {

	int maxBufferSize = this->waveFormat->nSamplesPerSec * this->waveFormat->nBlockAlign;
	int bufferSize = length * this->waveFormat->nBlockAlign;

	if (totalBufferIndex + bufferSize < maxBufferSize) {

		memcpy(totalBuffer + totalBufferIndex, buffer, bufferSize);
		totalBufferIndex += bufferSize;
	}
	else {

		int difference = (totalBufferIndex + bufferSize) - maxBufferSize;

		if (difference == 0) {

			memcpy(totalBuffer + totalBufferIndex, buffer, bufferSize);
			this->resampleAndPushLast(totalBuffer, this->waveFormat->nSamplesPerSec);
			totalBufferIndex = 0;
		}
		else {

			memcpy(totalBuffer + totalBufferIndex, buffer, (bufferSize - difference));
			this->resampleAndPushLast(totalBuffer, this->waveFormat->nSamplesPerSec);
			totalBufferIndex = 0;
			memcpy(totalBuffer + totalBufferIndex, buffer + (bufferSize - difference), difference);
			totalBufferIndex += difference;
		}
	}

}



void AudioCaptureSource::resampleAndPushLast(uint8_t *buffer, int length) {

	const uint8_t *out = NULL;
	int outBufferIndex = 0;

	int bufferSize;

	if (this->resampler.resample(buffer, length, &out, bufferSize) == true) {

		int remainder = bufferSize % OneFrameBufferSize;
		int quotient = bufferSize / OneFrameBufferSize;

		for (int i = 0; i < quotient; i++) {

			const uint8_t *oneFrameBuffer = out + (i * OneFrameBufferSize);

			if (this->bitsIndex == 0) {

				memcpy(this->bits, oneFrameBuffer, OneFrameBufferSize);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();



					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;
				}
			}
			else {

				int difference = OneFrameBufferSize - this->bitsIndex;

				memcpy(this->bits + this->bitsIndex, oneFrameBuffer, difference);


				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();



					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;
				}

				this->bitsIndex = 0;
				memcpy(this->bits + this->bitsIndex, oneFrameBuffer + difference, OneFrameBufferSize - difference);
				this->bitsIndex += OneFrameBufferSize - difference;
			}
		}

		const uint8_t *remainderFrameBuffer = out + (OneFrameBufferSize*quotient);

		if (this->bitsIndex + remainder < OneFrameBufferSize) {

			memcpy(this->bits + this->bitsIndex, remainderFrameBuffer, remainder);
			this->bitsIndex += remainder;
		}
		else {

			int difference = (this->bitsIndex + remainder) - OneFrameBufferSize;

			if (difference == 0) {

				memcpy(this->bits + this->bitsIndex, remainderFrameBuffer, remainder);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();


					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;

				}

				this->bitsIndex = 0;
			}
			else {

				memcpy(this->bits + this->bitsIndex, remainderFrameBuffer, remainder - difference);

				if (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {


					this->muteMutex.lock();

					if (this->parameter.muted == true) {

						this->setMuteData(this->bits, OneFrameBufferSize);
					}

					this->muteMutex.unlock();



					this->audioFrameQueue->push(new Capture_AudioFrame(this->bits, OneFrameBufferSize, this->totalPushedtoQueueCount));

					this->totalPushedtoQueueCount++;

				}

				this->bitsIndex = 0;
				memcpy(this->bits + this->bitsIndex, remainderFrameBuffer + remainder - difference, difference);
				this->bitsIndex += difference;
			}
		}


		if (this->totalPushedtoQueueCount >= this->totalCountToBePushedQueue) {

			this->noNeedToPushQueueMore = true;
		}
	}
}

int AudioCaptureSource::getFrameSize() {

	return 1024;
}


void AudioCaptureSource::getDevice(IMMDeviceEnumerator *deviceEnumerator, __MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 eType,
	const QString &deviceName, IMMDevice **device) {

	if (deviceEnumerator == NULL)
		return;

	IMMDeviceCollection *deviceCollection;
	deviceEnumerator->EnumAudioEndpoints(eType, DEVICE_STATE_ACTIVE, &deviceCollection);

	qDebug() << "selected device Name" << deviceName;

	UINT devicesCount;
	deviceCollection->GetCount(&devicesCount);
	qDebug() << "AudioCaptureSource::getDeviceIndex  count  " << devicesCount;


	for (int i = 0; i < devicesCount; i++) {

		QString name = AudioCaptureSource::getDeviceName(deviceCollection, i);

		qDebug() << name;

		if (name.contains(deviceName) == true) {

			qDebug() << "AudioCaptureSource::getDeviceIndex  mathched device Name " << name;
			deviceCollection->Item(i, device);
			break;
		}
	}

	deviceCollection->Release();
}


QString AudioCaptureSource::getDeviceName(IMMDeviceCollection *deviceCollection, UINT deviceIndex) {

	IMMDevice *device;
	LPWSTR deviceId;
	HRESULT hr;
	hr = deviceCollection->Item(deviceIndex, &device);
	hr = device->GetId(&deviceId);
	IPropertyStore *propertyStore;
	hr = device->OpenPropertyStore(STGM_READ, &propertyStore);

	PROPVARIANT friendlyName;
	PropVariantInit(&friendlyName);

	hr = propertyStore->GetValue(PKEY_Device_FriendlyName,
		&friendlyName);

	device->Release();
	propertyStore->Release();

	return QString::fromStdWString(friendlyName.pwszVal);
}


#define SafeRelease(p) \
                  if(p!=NULL) {\
                     p->Release();\
                     p=NULL;}


void AudioCaptureSource::clear() {

#ifdef Q_OS_WIN
	CoTaskMemFree(this->waveFormat);
	SafeRelease(this->deviceEnumerator);
	SafeRelease(this->device);
	SafeRelease(this->audioClient);
	SafeRelease(this->captureClient);
	this->waveFormat = NULL;
	this->waveFormatExtensible = NULL;

	CoUninitialize();
#endif 

	this->resampler.finish();

}


#ifdef Q_OS_WIN
bool AudioCaptureSource::initWinOS() {

	this->deviceEnumerator = NULL;
	this->device = NULL;
	this->audioClient = NULL;
	this->captureClient = NULL;
	this->waveFormat = NULL;
	this->waveFormatExtensible = NULL;

	HRESULT result;


	CoInitialize(NULL);

	result = CoCreateInstance(
		CLSID_MMDeviceEnumerator, NULL,
		CLSCTX_ALL, IID_IMMDeviceEnumerator,
		(void**)&this->deviceEnumerator);

	if (FAILED(result) == true) {

		qDebug() << "createInstance failed";
		this->clear();
		return false;
	}

	AudioCaptureSource::getDevice(this->deviceEnumerator, this->parameter.type, this->parameter.deviceName, &this->device);

	if (this->device == NULL) {

		qDebug() << "no deviceName matched";
		this->clear();
		return false;
	}

	result = this->device->Activate(IID_IAudioClient, CLSCTX_ALL,
		NULL, (void**)&this->audioClient);

	if (FAILED(result) == true) {

		qDebug() << "device Activate failed";
		this->clear();
		return false;
	}

	result = this->audioClient->GetMixFormat(&this->waveFormat);
	this->waveFormatExtensible = (WAVEFORMATEXTENSIBLE*)this->waveFormat;



	if (FAILED(result) == true) {

		qDebug() << "audioClient GetMixFormat failed";
		this->clear();
		return false;
	}

	switch (this->waveFormat->wFormatTag)
	{
	case WAVE_FORMAT_PCM:
		qDebug() << "WAVE_FORMAT_PCM";

		// nothing to do
		break;

	case WAVE_FORMAT_IEEE_FLOAT:

		qDebug() << "WAVE_FORMAT_IEEE_FLOAT";

		waveFormat->wFormatTag = WAVE_FORMAT_PCM;
		waveFormat->wBitsPerSample = 16;
		waveFormat->nBlockAlign = waveFormat->nChannels * waveFormat->wBitsPerSample / 8;
		waveFormat->nAvgBytesPerSec = waveFormat->nSamplesPerSec * waveFormat->nBlockAlign;
		break;

	case WAVE_FORMAT_EXTENSIBLE:
	{
		qDebug() << "WAVE_FORMAT_EXTENSIBLE";
		WAVEFORMATEXTENSIBLE *pWaveFormatExtensible = reinterpret_cast<WAVEFORMATEXTENSIBLE *>(waveFormat);
		if (pWaveFormatExtensible->SubFormat == KSDATAFORMAT_SUBTYPE_PCM)
		{

			qDebug() << "SUBTYPE_PCM";
			// nothing to do
		}
		else if (pWaveFormatExtensible->SubFormat == KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
		{
			qDebug() << "IEEE_FLOAT";

			pWaveFormatExtensible->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
			pWaveFormatExtensible->Format.wBitsPerSample = 16;
			pWaveFormatExtensible->Format.nBlockAlign =
				pWaveFormatExtensible->Format.nChannels *
				pWaveFormatExtensible->Format.wBitsPerSample /
				8;
			pWaveFormatExtensible->Format.nAvgBytesPerSec =
				pWaveFormatExtensible->Format.nSamplesPerSec *
				pWaveFormatExtensible->Format.nBlockAlign;
			pWaveFormatExtensible->Samples.wValidBitsPerSample =
				pWaveFormatExtensible->Format.wBitsPerSample;

			// leave the channel mask as-is
		}
		else
		{
			// we can only handle float or PCM
			result = HRESULT_FROM_WIN32(ERROR_NOT_FOUND);
		}
		break;
	}

	default:
		// we can only handle float or PCM
		result = HRESULT_FROM_WIN32(ERROR_NOT_FOUND);
		break;
	}

	if (FAILED(result) == true) {

		qDebug() << " change format failed";
		return false;
	}

	qDebug() << "audioClient -> Initialize";

	if (this->parameter.type == eCapture) {

		result = this->audioClient->Initialize(
			AUDCLNT_SHAREMODE_SHARED,
			AUDCLNT_STREAMFLAGS_NOPERSIST,
			hnsRequestedDuration,
			0,
			waveFormat,
			NULL);
	}
	else {

		result = this->audioClient->Initialize(
			AUDCLNT_SHAREMODE_SHARED,
			AUDCLNT_STREAMFLAGS_LOOPBACK,
			hnsRequestedDuration,
			0,
			waveFormat,
			NULL);
	}

	if (FAILED(result) == true) {

		//qDebug() << result;

		qDebug() << "audioClient Initialize failed";

		this->clear();
		return false;
	}

	result = this->audioClient->GetBufferSize(&bufferFrameCount);

	if (FAILED(result) == true) {

		qDebug() << "audioClient GetBufferSize failed";
		this->clear();
		return false;
	}

	result = this->audioClient->GetService(
		IID_IAudioCaptureClient,
		(void**)&this->captureClient);

	if (FAILED(result) == true) {

		qDebug() << "audioClient GetService failed";
		this->clear();
		return false;
	}

	this->hnsActualDuration = (double)REFTIMES_PER_SEC *
		bufferFrameCount / this->waveFormat->nSamplesPerSec;

	return true;
}
#endif


bool AudioCaptureSource::init() {

#ifdef Q_OS_WIN

	qDebug() << "AudioCaptureSource::init";
	if (this->initWinOS() == false)
		return false;

	qDebug() << "waveFormat->wFormatTag " << waveFormat->wFormatTag;
	qDebug() << " waveFormat->nAvgBytesPerSec " << waveFormat->nAvgBytesPerSec;
	qDebug() << "waveFormat->nBlockAlign " << waveFormat->nBlockAlign;
	qDebug() << "waveFormat->nChannels " << waveFormat->nChannels;
	qDebug() << "waveFormat->nSamplesPerSec " << waveFormat->nSamplesPerSec;
	qDebug() << "waveFormat->wBitsPerSample " << waveFormat->wBitsPerSample;
	qDebug() << "waveFormat->cbSize " << waveFormat->cbSize;

#endif 


	if (this->resampler.init(this->waveFormat->nChannels, this->waveFormat->nSamplesPerSec, this->waveFormat->wBitsPerSample,
		this->codecInfo.channels, this->codecInfo.sampleRate, AV_SAMPLE_FMT_S16) == false) {

		qDebug() << "failed to init Resampler";
		return false;
	}


	return true;
}



uint64_t AudioCaptureSource::convertTotalPushedToQueueCount(Time &mainTime) {

	Time time = mainTime;
	uint64_t milliseconds = time.getMilliseconds();
	uint64_t seconds = time.getSeconds();
	uint64_t minutes = time.getMinutes();
	uint64_t hours = time.getHours();

	minutes += hours * 60;
	seconds += minutes * 60;
	milliseconds += seconds * 1000;

	double cycleTimeByOneFrame = (this->cycleTimeByOneFrame * 1000);

	return (milliseconds / cycleTimeByOneFrame);
}


void AudioCaptureSource::clearFrameQueue() {

	this->audioFrameQueue->clear();
}

Capture_AudioFrame* AudioCaptureSource::popAudioFrame() {

	return this->audioFrameQueue->pop();
}


void AudioCaptureSource::setMuteData(uint8_t *buffer, int size) {
	/*
	for (int i = 0; i < size; i++) {
	
		buffer[i] = 0;
	}
	*/

	memset(buffer, 0, size);
}


//////////////////////////////////////////////////////////////////////////////////////////




Capture_AudioFrame::Capture_AudioFrame(uint8_t *buffer, int bufferSize, int frameIndex)
	:frameIndex(frameIndex) {

	memcpy(this->buffer, buffer, bufferSize);

}


Capture_AudioFrame::~Capture_AudioFrame() {

	
}

AudioFrameQueue::AudioFrameQueue() {

}

AudioFrameQueue::~AudioFrameQueue() {

}

void AudioFrameQueue::push(Capture_AudioFrame *frame) {
	
	this->mutex.lock();

	this->queue.append(frame);

	this->mutex.unlock();
}

Capture_AudioFrame* AudioFrameQueue::pop() {

	Capture_AudioFrame *frame;

	this->mutex.lock();

	if (this->queue.size() == 0)
		frame = nullptr;
	else
		frame = this->queue.takeFirst();

	this->mutex.unlock();


	return frame;
}

void AudioFrameQueue::clear() {

	this->mutex.lock();


	while (this->queue.isEmpty() == false) {
	
		delete this->queue.takeFirst();
	}

	this->mutex.unlock();
}
