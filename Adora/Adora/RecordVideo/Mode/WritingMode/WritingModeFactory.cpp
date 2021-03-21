

#include "WritingModeFactory.h"
#include "RecordVideo/Mode/WritingMode/CursorMode.h"
#include "RecordVideo/Mode/WritingMode/PencilMode.h"
#include "RecordVideo/Mode/WritingMode/EraserMode.h"


WritingModeFactory::WritingModeFactory() {


}

WritingModeFactory::~WritingModeFactory() {


}

WritingMode* WritingModeFactory::create(RecordVideoDialog *recordVideoDialog, WritingStatus writingStatus) {

	if (writingStatus == WritingStatus::Cursor)
		return new CursorMode(recordVideoDialog);

	else if (writingStatus == WritingStatus::Eraser)
		return new EraserMode(recordVideoDialog);


	return new PencilMode(recordVideoDialog);
}