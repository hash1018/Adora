

#include "VideoSettingWidget.h"


VideoSettingWidget::VideoSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

VideoSettingWidget::~VideoSettingWidget() {

}

#include <qpainter.h>
void VideoSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(12, 123, 32));
}