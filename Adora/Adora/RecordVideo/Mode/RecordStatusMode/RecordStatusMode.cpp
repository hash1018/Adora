

#include "RecordStatusMode.h"
#include <qpainter.h>
#include "Ui/Record/RecordVideoDialog.h"

RecordStatusMode::RecordStatusMode(RecordVideoDialog *recordVideoDialog)
	:recordVideoDialog(recordVideoDialog) {

}

RecordStatusMode::~RecordStatusMode() {

}


//////////////////////////////////////////////


RecordStatusNotRecordingMode::RecordStatusNotRecordingMode(RecordVideoDialog *recordVideoDialog)
	:RecordStatusMode(recordVideoDialog) {

}

RecordStatusNotRecordingMode::~RecordStatusNotRecordingMode() {

}


void RecordStatusNotRecordingMode::paintEvent(QPainter &painter) {

	QRect rect = this->recordVideoDialog->getRecordAreaRect();

	int x = rect.x() + (rect.width() / 2) - 20;
	int y = rect.y() + (rect.height() / 2) - 20;
	int width = 40;
	int height = 40;

	painter.fillRect(x, y, width, height, QColor(123, 123, 123));
}

////////////////////////////////////////////////


RecordStatusRecordingMode::RecordStatusRecordingMode(RecordVideoDialog *recordVideoDialog)
	:RecordStatusMode(recordVideoDialog) {

}

RecordStatusRecordingMode::~RecordStatusRecordingMode() {


}

//////////////////////////////////////////////////

RecordStatusPausedMode::RecordStatusPausedMode(RecordVideoDialog *recordVideoDialog)
	:RecordStatusMode(recordVideoDialog) {

}

RecordStatusPausedMode::~RecordStatusPausedMode() {


}

void RecordStatusPausedMode::paintEvent(QPainter &painter) {

	QRect rect = this->recordVideoDialog->getRecordAreaRect();

	int x = rect.x() + (rect.width()/2) - 20;
	int y = rect.y() + (rect.height()/2) - 20;
	int width = 40;
	int height = 40;

	painter.fillRect(x, y, width, height, QColor(123, 123, 123));
}