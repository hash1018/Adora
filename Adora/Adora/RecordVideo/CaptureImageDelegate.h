

#ifndef _CAPTUREIMAGEDELEGATE_H
#define _CAPTUREIMAGEDELEGATE_H

#include <qobject.h>
#include "lib/multimedia/GDIManager.h"


class RecordVideoDialog;
class QTimer;
class QPainter;

class CaptureImageDelegate : public QObject {

private:
	RecordVideoDialog *recordVideoDialog;
	GDIManager gdiManager;

private:
	bool showFlash;
	QTimer *timer;

public:
	CaptureImageDelegate(RecordVideoDialog *recordVideoDialog);
	~CaptureImageDelegate();


	void capture(int x, int y, int width, int height);
	void paintEvent(QPainter &painter);

	private slots:
	void timePassed();
};

#endif //_CAPTUREIMAGEDELEGATE_H
