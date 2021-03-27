

#include "WritingModeFactory.h"
#include "RecordVideo/Mode/WritingMode/CursorMode.h"
#include "RecordVideo/Mode/WritingMode/PencilMode.h"
#include "RecordVideo/Mode/WritingMode/EraserMode.h"
#include "RecordVideo/Mode/WritingMode/HighlightMode.h"
#include "RecordVideo/Mode/WritingMode/LineMode.h"
#include "RecordVideo/Mode/WritingMode/ArrowLineMode.h"
#include "RecordVideo/Mode/WritingMode/NumberingMode.h"
#include "RecordVideo/Mode/WritingMode/RectangleMode.h"

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

	else if (writingStatus == WritingStatus::ArrowLine)
		return new ArrowLineMode(recordVideoDialog);

	else if (writingStatus == WritingStatus::Numbering)
		return new NumberingMode(recordVideoDialog);

	else if (writingStatus == WritingStatus::WritingStatus_Rectangle)
		return new RectangleMode(recordVideoDialog);

	return new PencilMode(recordVideoDialog);
}