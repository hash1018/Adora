
#include "ImageSettingWidget.h"

ImageSettingWidget::ImageSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

ImageSettingWidget::~ImageSettingWidget() {

}

#include <qpainter.h>
void ImageSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(50, 50, 12));
}