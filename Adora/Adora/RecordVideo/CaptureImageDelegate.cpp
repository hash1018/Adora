

#include "CaptureImageDelegate.h"
#include <qimage.h>
#include "Base/SettingManager.h"
#include "Base/DefaultNameByDateCreator.h"

CaptureImageDelegate::CaptureImageDelegate(RecordVideoDialog *recordVideoDialog)
	: recordVideoDialog(recordVideoDialog) {

}

CaptureImageDelegate::~CaptureImageDelegate() {


}
#include <qdebug.h>
void CaptureImageDelegate::capture(int x, int y, int width, int height) {

	unsigned char *bits = nullptr;
	this->gdiManager.init(&bits, width, height);

	this->gdiManager.capture(x, y, width, height, SettingManager::getInstance()->getImageSetting()->getIncludeCursor());


	QImage image = QImage(bits, width, height, width * 4, QImage::Format::Format_RGB32);
	QString format = SettingManager::getInstance()->getImageSetting()->getImageFormat();
	QString path = SettingManager::getInstance()->getGeneralSetting()->getSavePath() +
		"/" + "Adora " + DefaultNameByDateCreator::create() + "." + format;

	qDebug() << path;

	image.save(path, format.toUtf8());

	this->gdiManager.close();
}