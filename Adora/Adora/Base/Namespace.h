

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
	ArrowLine,
	Numbering,
	WritingStatus_Rectangle,
	WritingStatus_Triangle,
	WritingStatus_Circle,

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
