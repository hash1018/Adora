

#include "SoundAmplitudeRenderWidget.h"
#include <qpainter.h>

SoundAmplitudeRenderWidget::SoundAmplitudeRenderWidget(QWidget *parent)
	:QWidget(parent), isDisable(false), amplitude(0) {

}

SoundAmplitudeRenderWidget::~SoundAmplitudeRenderWidget() {


}

void SoundAmplitudeRenderWidget::setAmplitude(float amplitude) {

	this->amplitude = amplitude;
	this->update();
}

void SoundAmplitudeRenderWidget::setDisabled(bool disabled) {

	this->isDisable = disabled;
	this->update();
	QWidget::setDisabled(disabled);
}

void SoundAmplitudeRenderWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing);
	QPainterPath path;

	QRect rect(0, this->height() / 4, this->width() - 1, this->height() / 2);
	path.addRoundedRect(rect, 5, 5);
	painter.fillPath(path, QColor("#FFFFFF"));

	if (this->amplitude == 0.0)
		return;

	if (this->isDisable == true)
		return;
	

	int pos = (this->width() - 2)*this->amplitude * 3;
	if (pos > this->width() - 1) pos = this->width() - 2;

	QPainterPath path2;
	QRect rect2(1, this->height() / 4 + 1, pos, this->height() / 2 - 1);
	path2.addRoundedRect(rect2, 5, 5);
	painter.fillPath(path2, QColor("#FFB513"));
	
}