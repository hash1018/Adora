
#include "AudioDeviceList.h"
#include <qdebug.h>

#ifdef Q_OS_WIN

#include <Functiondiscoverykeys_devpkey.h>
#include <combaseapi.h>

//const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
//const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);


#endif

AudioDeviceList::AudioDeviceList() {


}

AudioDeviceList::~AudioDeviceList() {


}


QStringList AudioDeviceList::getDeviceList(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 type) {


	QStringList list;

	IMMDeviceEnumerator *deviceEnumerator;

	HRESULT result;
	result = CoCreateInstance(
		CLSID_MMDeviceEnumerator, NULL,
		CLSCTX_ALL, IID_IMMDeviceEnumerator,
		(void**)&deviceEnumerator);

	if (FAILED(result) == true) {

		qDebug() << "createInstance failed";
		
		if (deviceEnumerator != NULL)
			deviceEnumerator->Release();

		return list;
	}


	IMMDeviceCollection *deviceCollection;
	deviceEnumerator->EnumAudioEndpoints(type, DEVICE_STATE_ACTIVE, &deviceCollection);

	UINT devicesCount;
	deviceCollection->GetCount(&devicesCount);

	for (int i = 0; i < devicesCount; i++) {

		QString name = AudioDeviceList::getDeviceName(deviceCollection, i);
		list.append(name);
	}


	deviceCollection->Release();
	deviceEnumerator->Release();


	return list;
}


QString AudioDeviceList::getDeviceName(IMMDeviceCollection *deviceCollection, UINT deviceIndex) {

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