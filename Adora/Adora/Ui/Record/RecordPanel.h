

#ifndef _RECORDPANEL_H
#define _RECORDPANEL_H

#include <qwidget.h>
#include "ui_RecordPanel.h"
#include "RecordVideo/Chain/RecordVideoChain.h"
#include <qlist.h>

class RecordVideoNotifyEvent;

class RecordPanel : public QWidget, public RecordVideoChain {

private:
	Ui::RecordPanel ui;

private:
	QList<QWidget*> items;

public:
	RecordPanel(QWidget *parent = nullptr);
	~RecordPanel();

	void update(RecordVideoNotifyEvent *event);

	private slots:
	void recordButtonClicked();
	void quitButtonClicked();
	void captureButtonClicked();
	void resumeButtonClicked();
	void pauseButtonClicked();
	void stopButtonClicked();

};

#endif //_RECORDPANEL_H