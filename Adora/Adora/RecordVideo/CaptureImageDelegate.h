

#ifndef _CAPTUREIMAGEDELEGATE_H
#define _CAPTUREIMAGEDELEGATE_H

#include <qobject.h>
#include "lib/multimedia/GDIManager.h"
class RecordVideoDialog;

class CaptureImageDelegate : public QObject {

private:
	RecordVideoDialog *recordVideoDialog;
	GDIManager gdiManager;

public:
	CaptureImageDelegate(RecordVideoDialog *recordVideoDialog);
	~CaptureImageDelegate();


	void capture(int x, int y, int width, int height);
};

#endif //_CAPTUREIMAGEDELEGATE_H
