

#include "HwEncoder.h"
#include "CodecInfo.h"

HwEncoder::HwEncoder()
	:hwDeviceContext(NULL), avFrame(NULL), avFramegetBuffered(false) {

}


HwEncoder::~HwEncoder() {

	if (this->hwDeviceContext != NULL) {

		av_buffer_unref(&this->hwDeviceContext);
	}

	if (this->avFrame != NULL)
		av_frame_free(&this->avFrame);
}


void HwEncoder::convertDeviceTypeToString(char *string) {

	if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VDPAU)
		strcpy(string, "AV_HWDEVICE_TYPE_VDPAU");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_CUDA)
		strcpy(string, "AV_HWDEVICE_TYPE_CUDA");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VAAPI)
		strcpy(string, "AV_HWDEVICE_TYPE_VAAPI");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DXVA2)
		strcpy(string, "AV_HWDEVICE_TYPE_DXVA2");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_QSV)
		strcpy(string, "AV_HWDEVICE_TYPE_QSV");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VIDEOTOOLBOX)
		strcpy(string, "AV_HWDEVICE_TYPE_VIDEOTOOLBOX");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_D3D11VA)
		strcpy(string, "AV_HWDEVICE_TYPE_D3D11VA");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DRM)
		strcpy(string, "AV_HWDEVICE_TYPE_DRM");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_OPENCL)
		strcpy(string, "AV_HWDEVICE_TYPE_OPENCL");
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC)
		strcpy(string, "AV_HWDEVICE_TYPE_MEDIACODEC");
}


AVCodec* HwEncoder::findUseableCodec(const VideoCodecInfo &videoCodecInfo) {

	int ret;
	char encoderName[128];
	AVCodec *codec = NULL;

	for (int i = AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC;
		i != AVHWDeviceType::AV_HWDEVICE_TYPE_NONE;
		i--) {

		ret = av_hwdevice_ctx_create(&this->hwDeviceContext, (AVHWDeviceType)i, NULL, NULL, 0);
		if (ret >= 0) {

			this->hwDeviceType = (AVHWDeviceType)i;


			this->findHwEncoderName(videoCodecInfo.codecID, encoderName);
			codec = avcodec_find_encoder_by_name(encoderName);

			if (codec != NULL) {

				char string[128];
				this->convertDeviceTypeToString(string);
				return codec;
			}

			av_buffer_unref(&this->hwDeviceContext);
		}
	}

	return NULL;
}



AVCodec* HwEncoder::getCodec(char *hwEncoderName) {

	int ret;
	AVCodec *codec = NULL;

	this->hwDeviceType = this->getHWDeviceType(hwEncoderName);

	ret = av_hwdevice_ctx_create(&this->hwDeviceContext, this->hwDeviceType, NULL, NULL, 0);
	if (ret >= 0) {

		codec = avcodec_find_encoder_by_name(hwEncoderName);

		if (codec != NULL) {

			char string[128];
			this->convertDeviceTypeToString(string);
			return codec;
		}

	}

	return NULL;
}


AVHWDeviceType HwEncoder::getHWDeviceType(char *hwEncoderName) {

	AVHWDeviceType type;

	if (strcmp(hwEncoderName, "h264_vdpau") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_VDPAU;
	else if (strcmp(hwEncoderName, "h264_nvenc") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_CUDA;
	else if (strcmp(hwEncoderName, "h264_vaapi") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_VAAPI;
	else if (strcmp(hwEncoderName, "h264_dxva2") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_DXVA2;
	else if (strcmp(hwEncoderName, "h264_qsv") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_QSV;
	else if (strcmp(hwEncoderName, "h264_videotoolbox") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_VIDEOTOOLBOX;
	else if (strcmp(hwEncoderName, "h264_d3d11va") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_D3D11VA;
	else if (strcmp(hwEncoderName, "h264_drm") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_DRM;
	else if (strcmp(hwEncoderName, "h264_opencl") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_OPENCL;
	else if (strcmp(hwEncoderName, "h264_mediacodec") == 0)
		type = AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC;


	return type;
}


void HwEncoder::findHwEncoderName(AVCodecID codecId, char *hwEncoderName) {

	if (codecId == AV_CODEC_ID_H264) {

		if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VDPAU)
			strcpy(hwEncoderName, "h264_vdpau");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_CUDA)
			strcpy(hwEncoderName, "h264_nvenc");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VAAPI)
			strcpy(hwEncoderName, "h264_vaapi");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DXVA2)
			strcpy(hwEncoderName, "h264_dxva2");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_QSV)
			strcpy(hwEncoderName, "h264_qsv");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VIDEOTOOLBOX)
			strcpy(hwEncoderName, "h264_videotoolbox");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_D3D11VA)
			strcpy(hwEncoderName, "h264_d3d11va");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DRM)
			strcpy(hwEncoderName, "h264_drm");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_OPENCL)
			strcpy(hwEncoderName, "h264_opencl");
		else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC)
			strcpy(hwEncoderName, "h264_mediacodec");
	}
}


AVPixelFormat HwEncoder::getPixelFormat() {

	if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VDPAU)
		return AV_PIX_FMT_VDPAU;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_CUDA)
		return AV_PIX_FMT_CUDA;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VAAPI)
		return AV_PIX_FMT_VAAPI;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DXVA2)
		return AV_PIX_FMT_DXVA2_VLD;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_QSV)
		return AV_PIX_FMT_QSV;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_VIDEOTOOLBOX)
		return AV_PIX_FMT_VIDEOTOOLBOX;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_D3D11VA)
		return AV_PIX_FMT_D3D11VA_VLD;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_DRM)
		return AV_PIX_FMT_DRM_PRIME;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_OPENCL)
		return AV_PIX_FMT_OPENCL;
	else if (this->hwDeviceType == AVHWDeviceType::AV_HWDEVICE_TYPE_MEDIACODEC)
		return AV_PIX_FMT_MEDIACODEC;

	return AV_PIX_FMT_NONE;
}


bool HwEncoder::setHwFrameContext(AVCodecContext *avCodecContext, const VideoCodecInfo &videoCodecInfo) {

	AVBufferRef *hwFrameRef;
	AVHWFramesContext *hwFramesContext = NULL;

	int ret;

	hwFrameRef = av_hwframe_ctx_alloc(this->hwDeviceContext);
	if (hwFrameRef == NULL) {
		
		return false;
	}

	hwFramesContext = (AVHWFramesContext*)(hwFrameRef->data);
	hwFramesContext->format = this->getPixelFormat();
	hwFramesContext->sw_format = videoCodecInfo.pixelFormat;
	hwFramesContext->width = videoCodecInfo.width;
	hwFramesContext->height = videoCodecInfo.height;
	hwFramesContext->initial_pool_size = 32;

	ret = av_hwframe_ctx_init(hwFrameRef);

	if (ret < 0) {

		av_buffer_unref(&hwFrameRef);
		
		return false;
	}

	avCodecContext->hw_frames_ctx = av_buffer_ref(hwFrameRef);

	av_buffer_unref(&hwFrameRef);

	return true;
}


bool HwEncoder::allocFrame() {

	if (this->avFrame == NULL) {

		this->avFrame = av_frame_alloc();

		if (this->avFrame == NULL)
			return false;
	}

	return true;
}
