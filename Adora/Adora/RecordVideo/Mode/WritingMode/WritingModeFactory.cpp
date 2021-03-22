

#include "WritingModeFactory.h"
#include "RecordVideo/Mode/WritingMode/CursorMode.h"
#include "RecordVideo/Mode/WritingMode/PencilMode.h"
#include "RecordVideo/Mode/WritingMode/EraserMode.h"
#include "RecordVideo/Mode/WritingMode/HighlightMode.h"
#include "RecordVideo/Mode/WritingMode/LineMode.h"

WritingModeFactory::WritingModeFactory() {


}

WritingModeFactory::~WritingModeFactory() {


}

WritingMode* WritingModeFactory::create(RecordVideoDialog *recordVideoDialog, WritingStatus writingStatus) {

	if (writingStatus == WritingStatus::Cursor)
		return new CursorMode(recordVideoDialog);

	else if (writingStatus == WritingStatus::Eraser)
		return new EraserMode(recordVideoDialog);

	else if (writingStatus == WritingStatus::Highlight)
		return new HighlightMode(recordVideoDialog);

	else if (writingStatus == WritingStatus::Line)
		return new LineMode(recordVideoDialog);


	return new PencilMode(recordVideoDialog);
}