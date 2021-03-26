

#include "HwEncoderFinder.h"
#include <qdebug.h>

HwEncoderFinder::HwEncoderFinder() {

}

HwEncoderFinder::~HwEncoderFinder() {


}

QStringList HwEncoderFinder::getAvailableHwEncoderList(AVCodecID codecID) {

	qDebug() << "HwEncoderFinder::getAvailableHwEncoderList";

	QStringList list;
	
	int ret;
	AVBufferRef *hwDeviceContext = NULL;
	AVHWDeviceType hwDeviceType;
	AVCodec *codec = NULL;
	char encoderName[128];

	for (int i = AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC;
		i != AVHWDeviceType::AV_HWDEVICE_TYPE_NONE;
		i--) {


		//if ((AVHWDeviceType)i == AVHWDeviceType::AV_HWDEVICE_TYPE_QSV)
		//	continue;

		char name[128];
		HwEncoderFinder::convertDeviceTypeToString((AVHWDeviceType)i, name);
		qDebug() << "about to Check " << name;

		ret = av_hwdevice_ctx_create(&hwDeviceContext, (AVHWDeviceType)i, NULL, NULL, 0);

		qDebug() << "av_hwdevice_ctx_create end";
		if (ret == 0) {
			qDebug() << "av_hwdevice_ctx_create success";

			hwDeviceType = (AVHWDeviceType)i;


			HwEncoderFinder::findHwEncoderName(hwDeviceType, codecID, encoderName);
			codec = NULL;

			qDebug() << "encoderName i" << encoderName << i;
			codec = avcodec_find_encoder_by_name(encoderName);

			if (codec != NULL) {

				qDebug() << "encoderName  " << encoderName;

				char hwDeviceTypeString[128];
				HwEncoderFinder::convertDeviceTypeToString(hwDeviceType, hwDeviceTypeString);
				qDebug() << "hwDeviceType " << hwDeviceTypeString;

				list.append(encoderName);
				codec = NULL;
				
			}

			av_buffer_unref(&hwDeviceContext);
			hwDeviceContext = NULL;
		}

		
	}



	if (hwDeviceContext != NULL) {

		av_buffer_unref(&hwDeviceContext);
	}

	return list;
}


void HwEncoderFinder::findHwEncoderName(AVHWDeviceType hwDeviceType, AVCodecID codecId, char *hwEncoderName) {

	if (codecId == AV_CODEC_ID_H264) {

		if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VDPAU)
			strcpy(hwEncoderName, "h264_vdpau");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_CUDA)
			strcpy(hwEncoderName, "h264_nvenc");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VAAPI)
			strcpy(hwEncoderName, "h264_vaapi");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DXVA2)
			strcpy(hwEncoderName, "h264_dxva2");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_QSV)
			strcpy(hwEncoderName, "h264_qsv");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VIDEOTOOLBOX)
			strcpy(hwEncoderName, "h264_videotoolbox");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_D3D11VA)
			strcpy(hwEncoderName, "h264_d3d11va");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DRM)
			strcpy(hwEncoderName, "h264_drm");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_OPENCL)
			strcpy(hwEncoderName, "h264_opencl");
		else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC)
			strcpy(hwEncoderName, "h264_mediacodec");
	}
}



void HwEncoderFinder::convertDeviceTypeToString(AVHWDeviceType hwDeviceType, char *string) {

	if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VDPAU)
		strcpy(string, "AV_HWDEVICE_TYPE_VDPAU");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_CUDA)
		strcpy(string, "AV_HWDEVICE_TYPE_CUDA");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VAAPI)
		strcpy(string, "AV_HWDEVICE_TYPE_VAAPI");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DXVA2)
		strcpy(string, "AV_HWDEVICE_TYPE_DXVA2");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_QSV)
		strcpy(string, "AV_HWDEVICE_TYPE_QSV");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VIDEOTOOLBOX)
		strcpy(string, "AV_HWDEVICE_TYPE_VIDEOTOOLBOX");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_D3D11VA)
		strcpy(string, "AV_HWDEVICE_TYPE_D3D11VA");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DRM)
		strcpy(string, "AV_HWDEVICE_TYPE_DRM");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_OPENCL)
		strcpy(string, "AV_HWDEVICE_TYPE_OPENCL");
	else if (hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC)
		strcpy(string, "AV_HWDEVICE_TYPE_MEDIACODEC");
}