
#include "VolumeLevelGetter.h"
#include <qdebug.h>

#define REFTIMES_PER_SEC  10000000
#define REFTIMES_PER_MILLISEC  10000

VolumeLevelGetter::VolumeLevelGetter(QObject *parent)
	:QThread(parent) {

	this->hnsRequestedDuration = REFTIMES_PER_SEC;
}

VolumeLevelGetter::~VolumeLevelGetter() {

	this->clear();
}

#ifdef Q_OS_WIN
bool VolumeLevelGetter::init(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 type, const QString &deviceName) {

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

	this->getDevice(this->deviceEnumerator, type, deviceName, &this->device);

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

	if (type == eCapture) {

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


void VolumeLevelGetter::quit() {

	qDebug() << " quit";
	this->requestToFinish = true;
}

float VolumeLevelGetter::getAmplitude(uint8_t *buffer, int length) {

	int maxAmplitude;

	if (this->waveFormat->wBitsPerSample == 16) {
	
		maxAmplitude = 32767;
	}
	else if (this->waveFormat->wBitsPerSample == 8) {
	
		maxAmplitude = 127;
	}
	else if (this->waveFormat->wBitsPerSample == 32) {
	
		maxAmplitude = 0x7fffffff;
	}

	const int8_t *ptr = reinterpret_cast<const signed char *>(buffer);
	int32_t max = 0;
	int32_t value;

	for (int i = 0; i < length * this->waveFormat->nChannels; i++) {

		if (this->waveFormat->wBitsPerSample == 8) {
			value= *reinterpret_cast<const qint8*>(ptr);
		}
		else if (this->waveFormat->wBitsPerSample == 16) {
			value = *reinterpret_cast<const qint16*>(ptr);
		}
		else if (this->waveFormat->wBitsPerSample == 32) {
			value = *reinterpret_cast<const qint32*>(ptr);
		}

		if (value > max)
			max = value;

		ptr += this->waveFormat->wBitsPerSample / 8;
	}

	if (max > maxAmplitude)
		max = maxAmplitude;

	return max / (maxAmplitude * 1.f);

}

void VolumeLevelGetter::run() {

	qDebug() << "VolumeLevelGetter run " << this->currentThreadId();

	this->requestToFinish = false;
	
#ifdef Q_OS_WIN

	int second = 0;
	int totalPacketLength = 0;
	
	HANDLE handle = CreateEventEx(NULL, NULL, 0, EVENT_MODIFY_STATE | SYNCHRONIZE);

	HRESULT result2 = this->audioClient->Start();

	if (FAILED(result2) == true) {

		qDebug() << "Start Failed";
		return;
	}

	while (1) {

		WaitForSingleObject(handle, 100);

		this->captureClient->GetNextPacketSize(&packetLength);

		if (packetLength != 0) {

			while (packetLength != 0) {

				this->captureClient->GetBuffer(&this->data, &numFramesAvailable, &flags, NULL, NULL);

				totalPacketLength += numFramesAvailable;

				if (totalPacketLength >= this->waveFormat->nSamplesPerSec) {

					second++;
					totalPacketLength -= this->waveFormat->nSamplesPerSec;
				}

				
				//qDebug() << this->getAmplitude(this->data, numFramesAvailable);

				emit this->amplitudeChanged(this->getAmplitude(this->data, numFramesAvailable));

				this->captureClient->ReleaseBuffer(numFramesAvailable);
				this->captureClient->GetNextPacketSize(&packetLength);
			}

		}
		else {

			//qDebug() << " 0";
			emit this->amplitudeChanged(0);
		}

		if (this->requestToFinish == true)
			break;
	}



	this->audioClient->Stop();

#endif 
}


#ifdef Q_OS_WIN
void VolumeLevelGetter::getDevice(IMMDeviceEnumerator *deviceEnumerator,
	__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 eType,
	const QString &deviceName, IMMDevice **device) {

	if (deviceEnumerator == NULL)
		return;

	IMMDeviceCollection *deviceCollection;
	deviceEnumerator->EnumAudioEndpoints(eType, DEVICE_STATE_ACTIVE, &deviceCollection);

	qDebug() << "selected device Name" << deviceName;

	UINT devicesCount;
	deviceCollection->GetCount(&devicesCount);
	qDebug() << "VolumeLevelGetter::getDeviceIndex  count  " << devicesCount;


	for (int i = 0; i < devicesCount; i++) {

		QString name = this->getDeviceName(deviceCollection, i);

		qDebug() << name;

		if (name.contains(deviceName) == true) {

			qDebug() << "VolumeLevelGetter::getDeviceIndex  mathched device Name " << name;
			deviceCollection->Item(i, device);
			break;
		}
	}

	deviceCollection->Release();
}

QString VolumeLevelGetter::getDeviceName(IMMDeviceCollection *deviceCollection, UINT deviceIndex) {

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


#endif 



#define SafeRelease(p) \
                  if(p!=NULL) {\
                     p->Release();\
                     p=NULL;}

void VolumeLevelGetter::clear() {


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

}