

#include "AudioSettingWidget.h"


AudioSettingWidget::AudioSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

AudioSettingWidget::~AudioSettingWidget() {

}

#include <qpainter.h>
void AudioSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(25, 25, 100));
}