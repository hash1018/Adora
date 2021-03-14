

#include "AdoraFrameWidget.h"


AdoraFrameWidget::AdoraFrameWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	connect(ui.closeButton, &QPushButton::clicked, this, &AdoraFrameWidget::closeButtonClicked);
	connect(ui.minimizeButton, &QPushButton::clicked, this, &AdoraFrameWidget::minimizeButtonClicked);
}

AdoraFrameWidget::~AdoraFrameWidget() {

}

