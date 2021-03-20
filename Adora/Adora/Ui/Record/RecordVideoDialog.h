

#ifndef _RECORDVIDEODIALOG_H
#define _RECORDVIDEODIALOG_H

#include <qdialog.h>

class ControllerWidget;

class RecordVideoDialog : public QDialog {

	Q_OBJECT


private:
	QRect recordAreaRect;

private:
	ControllerWidget *controllerWidget;

public:
	RecordVideoDialog(QWidget *parent = nullptr);
	~RecordVideoDialog();

signals:
	void recordVideoDialogClosed();

protected:
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	virtual void resizeEvent(QResizeEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);


private:
	QRect getRecordBorderRect();
};



#endif //_RECORDVIDEODIALOG_H
