

#ifndef _UNREDOPANEL_H
#define _UNREDOPANEL_H

#include <qwidget.h>
#include "RecordVideo/Chain/RecordVideoChain.h"
#include "ui_UnredoPanel.h"

class RecordVideoNotifyEvent;

class UnredoPanel : public QWidget, public RecordVideoChain {

private:
	Ui::UnredoPanel ui;

public:
	UnredoPanel(QWidget *parent = nullptr);
	~UnredoPanel();

	void update(RecordVideoNotifyEvent *event);

	private slots:
	void undoButtonClicked();
	void redoButtonClicked();
};

#endif //_UNREDOPANEL_H
