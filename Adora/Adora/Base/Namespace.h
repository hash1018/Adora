

#ifndef _NAMESPACE_H
#define _NAMESPACE_H

enum RecordStatus {

	NotRecording,
	Recording,
	Paused,
};

enum WritingStatus {
	Cursor,
	Pencil,
	Eraser,
	Highlight,
	Line,

};

enum ResizeBehavior {
	Nothing,
	Move,
	ResizeTopRight,
	ResizeTopLeft,
	ResizeBottomRight,
	ResizeBottomLeft,
	ResizeTop,
	ResizeBottom,
	ResizeLeft,
	ResizeRight,
};

#endif //_NAMESPACE_H
