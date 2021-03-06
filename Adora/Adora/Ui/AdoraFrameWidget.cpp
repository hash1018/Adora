

#include "AdoraFrameWidget.h"


AdoraFrameWidget::AdoraFrameWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	connect(ui.closeButton, &QPushButton::clicked, this, &AdoraFrameWidget::closeButtonClicked);
	connect(ui.minimizeButton, &QPushButton::clicked, this, &AdoraFrameWidget::minimizeButtonClicked);
}

AdoraFrameWidget::~AdoraFrameWidget() {


}

#include <qpainter.h>
void AdoraFrameWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(123, 123, 123));
}