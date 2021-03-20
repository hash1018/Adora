

#ifndef _RECORDVIDEODIALOG_H
#define _RECORDVIDEODIALOG_H

#include <qdialog.h>
#include "RecordVideo/Chain/RecordVideoChain.h"
#include "Base/Namespace.h"

class ControllerWidget;
class RecordStatusMode;
class ResizeRecordRectDelegate;

class RecordVideoDialog : public QDialog, public RecordVideoChain {

	Q_OBJECT


	friend class RecordVideoRequestStrategy;
	friend class RecordVideoRequestChangeRecordStatusStrategy;

private:
	QRect recordAreaRect;

private:
	ControllerWidget *controllerWidget;

private:
	RecordStatusMode *recordStatusMode;
	ResizeRecordRectDelegate *resizeRecordRectDelegate;


public:
	RecordVideoDialog(QWidget *parent = nullptr);
	~RecordVideoDialog();

signals:
	void recordVideoDialogClosed();

private:
	void changeRecordStatusMode(RecordStatus recordStatus);

private:
	virtual void request(RecordVideoRequest *request);

private:
	void record();
	void quit();
	void pause();
	void stop();
	void resume();
	void capture();

protected:
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	virtual void resizeEvent(QResizeEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);


public:
	QRect getRecordBorderRect();
};



#endif //_RECORDVIDEODIALOG_H
