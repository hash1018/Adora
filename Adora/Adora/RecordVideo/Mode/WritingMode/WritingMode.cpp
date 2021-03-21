

#include "WritingMode.h"
#include "Ui/Record/WritingLayer.h"
#include "Ui/Record/RecordVideoDialog.h"

WritingMode::WritingMode(RecordVideoDialog *recordVideoDialog)
	:recordVideoDialog(recordVideoDialog), writingLayer(nullptr) {

}


WritingMode::~WritingMode() {

}


void WritingMode::createWritingLayer() {

	if (this->writingLayer == nullptr) {

		this->writingLayer = new WritingLayer(this->recordVideoDialog);
		this->writingLayer->show();
		this->writingLayer->setGeometry(this->recordVideoDialog->getRecordAreaRect());
	}
}

void WritingMode::deleteWritingLayer() {

	if (this->writingLayer != nullptr) {
		this->writingLayer->deleteLater();
		this->writingLayer = nullptr;
	}
}