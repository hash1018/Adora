

#ifndef _HWENCODERFINDER_H
#define _HWENCODERFINDER_H

#include <qstringlist.h>
extern "C" {

#include <libavcodec/avcodec.h>
}

class HwEncoderFinder {


	

public:
	HwEncoderFinder();
	~HwEncoderFinder();


	static QStringList getAvailableHwEncoderList(AVCodecID codecID = AVCodecID::AV_CODEC_ID_H264);


private:
	static void findHwEncoderName(AVHWDeviceType hwDeviceType, AVCodecID codecId, char *hwEncoderName);
	static void convertDeviceTypeToString(AVHWDeviceType hwDeviceType, char *string);
};


#endif //_HWENCODERFINDER_H
