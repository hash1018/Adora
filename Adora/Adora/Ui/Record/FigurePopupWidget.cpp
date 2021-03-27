

#include "FigurePopupWidget.h"
#include <qpainter.h>

FigurePopupWidget::FigurePopupWidget()
	:QWidget(nullptr,Qt::Popup) {

	ui.setupUi(this);

	connect(ui.circleButton, &QPushButton::clicked, this, &FigurePopupWidget::circleButtonClicked);
	connect(ui.rectangleButton, &QPushButton::clicked, this, &FigurePopupWidget::rectangleButtonClicked);
	connect(ui.triangleButton, &QPushButton::clicked, this, &FigurePopupWidget::triangleButtonClicked);
}

FigurePopupWidget::~FigurePopupWidget() {

}


void FigurePopupWidget::setWritingStatus(WritingStatus status) {

	ui.circleButton->updateSelected(false);
	ui.rectangleButton->updateSelected(false);
	ui.triangleButton->updateSelected(false);

	if (status == WritingStatus::WritingStatus_Circle) {
		ui.circleButton->updateSelected(true);
	}
	else if (status == WritingStatus::WritingStatus_Rectangle) {
		ui.rectangleButton->updateSelected(true);
	}
	else if (status == WritingStatus::WritingStatus_Triangle) {
		ui.triangleButton->updateSelected(true);
	}
}
