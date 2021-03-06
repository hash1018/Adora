#include "Adora.h"

Adora::Adora(QWidget *parent)
	: QMainWindow(parent) {

	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);

	connect(ui.adoraFrameWidget, &AdoraFrameWidget::closeButtonClicked, this, &Adora::closeButtonClicked);
	connect(ui.adoraFrameWidget, &AdoraFrameWidget::minimizeButtonClicked, this, &Adora::minimizeButtonClicked);
}

Adora::~Adora() {

}

void Adora::closeButtonClicked() {

	this->close();
	
}

void Adora::minimizeButtonClicked() {

	this->showMinimized();
}