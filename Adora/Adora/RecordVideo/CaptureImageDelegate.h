

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

private:
	int x;
	int y;
	int width;
	int height;
	unsigned char *bits;

public:
	CaptureImageDelegate(RecordVideoDialog *recordVideoDialog);
	~CaptureImageDelegate();


	void capture(int x, int y, int width, int height);
	void paintEvent(QPainter &painter);

	bool isShowFlash() const { return this->showFlash; }

	private slots:
	void timePassed();
};

#endif //_CAPTUREIMAGEDELEGATE_H
