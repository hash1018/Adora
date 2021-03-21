
#include "WritingLayer.h"
#include <QGraphicsOpacityEffect>
#include <qpainter.h>

WritingLayer::WritingLayer(QWidget *parent)
	:QWidget(parent) {

	this->effect = new QGraphicsOpacityEffect(this);
	this->effect->setOpacity(0.01);
	this->setMouseTracking(true);

	this->setGraphicsEffect(this->effect);
}

WritingLayer::~WritingLayer() {


}


void WritingLayer::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor("#FFFFFF"));

}