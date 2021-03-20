

#include "CaptureImageDelegate.h"
#include <qimage.h>
#include "Base/SettingManager.h"
#include "Base/DefaultNameByDateCreator.h"
#include <qtimer.h>
#include <qpainter.h>
#include "Ui/Record/RecordVideoDialog.h"

CaptureImageDelegate::CaptureImageDelegate(RecordVideoDialog *recordVideoDialog)
	: recordVideoDialog(recordVideoDialog), showFlash(false), timer(nullptr) {

}

CaptureImageDelegate::~CaptureImageDelegate() {


}

void CaptureImageDelegate::capture(int x, int y, int width, int height) {

	unsigned char *bits = nullptr;
	this->gdiManager.init(&bits, width, height);

	this->gdiManager.capture(x, y, width, height, SettingManager::getInstance()->getImageSetting()->getIncludeCursor());


	QImage image = QImage(bits, width, height, width * 4, QImage::Format::Format_RGB32);
	QString format = SettingManager::getInstance()->getImageSetting()->getImageFormat();
	QString path = SettingManager::getInstance()->getGeneralSetting()->getSavePath() +
		"/" + "Adora " + DefaultNameByDateCreator::create() + "." + format;

	image.save(path, format.toUtf8());

	this->gdiManager.close();

	if (this->timer == nullptr) {

		this->timer = new QTimer(this);
		connect(this->timer, &QTimer::timeout, this, &CaptureImageDelegate::timePassed);
	}

	this->showFlash = true;
	this->timer->stop();
	this->timer->setInterval(300);
	this->timer->start();
	this->recordVideoDialog->update();
}


void CaptureImageDelegate::paintEvent(QPainter &painter) {

	if (this->showFlash == true) {

		QPen pen(QColor(000, 153, 255));
		pen.setWidth(4);

		QPen oldPen = painter.pen();
		painter.setPen(pen);

		QRect rect = this->recordVideoDialog->getRecordBorderRect();
		QPoint start, end;

		start = QPoint(rect.topLeft());
		end = QPoint(rect.topRight());
		painter.drawLine(start, end);

		start = end;
		end = QPoint(rect.bottomRight());
		painter.drawLine(start, end);

		start = end;
		end = QPoint(rect.bottomLeft());
		painter.drawLine(start, end);

		start = end;
		end = QPoint(rect.topLeft());
		painter.drawLine(start, end);

		painter.setPen(oldPen);
	}
}

void CaptureImageDelegate::timePassed() {

	this->showFlash = false;
	this->timer->stop();
	this->recordVideoDialog->update();
}