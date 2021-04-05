

#include "WidthPopupWidget.h"

WidthPopupWidget::WidthPopupWidget()
	:QWidget(nullptr, Qt::Popup), width_(0), writingStatus(WritingStatus::Cursor) {

	ui.setupUi(this);

	//connect(ui.listWidget, &QListWidget::currentRowChanged, this, &WidthPopupWidget::currentRowChanged);
}

WidthPopupWidget::~WidthPopupWidget() {

}

void WidthPopupWidget::setWidth(int width) {

	this->width_ = width;
	this->updateList();
}

void WidthPopupWidget::setWritingStatus(WritingStatus writingStatus) {

	this->writingStatus = writingStatus;
	this->updateList();
}

void WidthPopupWidget::updateList() {

	disconnect(ui.listWidget, &QListWidget::currentRowChanged, this, &WidthPopupWidget::currentRowChanged);

	ui.listWidget->clear();

	if (this->width_ == 0)
		return;

	if (this->writingStatus == Cursor)
		return;

	
	if (this->writingStatus != Numbering) {
		for (int i = 1; i <= 30; i++) {

			ui.listWidget->addItem(QString::number(i) + " px");
		}

		ui.listWidget->setCurrentRow(this->width_ - 1);
	}
	else {
	
		for (int i = 0; i <= 30; i++) {
		
			ui.listWidget->addItem(QString::number(i + 20));
		}

		ui.listWidget->setCurrentRow(this->width_ - 20);
	}


	connect(ui.listWidget, &QListWidget::currentRowChanged, this, &WidthPopupWidget::currentRowChanged);
}


void WidthPopupWidget::currentRowChanged(int row) {

	if (this->writingStatus != Numbering) {
		emit this->currentWidthChanged(row + 1);
	}
	else {
		emit this->currentWidthChanged(row + 20);
	}
}