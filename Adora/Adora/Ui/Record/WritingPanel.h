

#ifndef _WRITINGPANEL_H
#define _WRITINGPANEL_H

#include <qwidget.h>
#include "RecordVideo/Chain/RecordVideoChain.h"
#include "ui_WritingPanel.h"
#include <qlist.h>

class RecordVideoNotifyEvent;
class AbstractButton;

class WritingPanel : public QWidget, public RecordVideoChain {

private:
	Ui::WritingPanel ui;

private:
	QList<AbstractButton*> items;

public:
	WritingPanel(QWidget *parent = nullptr);
	~WritingPanel();

	void update(RecordVideoNotifyEvent *event);

	private slots:
	void cursorButtonClicked();
	void pencilButtonClicked();
	void eraserButtonClicked();
	void deleteAllButtonClicked();
	void highlightButtonClicked();
	void lineButtonClicked();
	void arrowLineButtonClicked();


};

#endif //_WRITINGPANEL_H
