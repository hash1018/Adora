

#ifndef _WRITINGPANEL_H
#define _WRITINGPANEL_H

#include <qwidget.h>
#include "RecordVideo/Chain/RecordVideoChain.h"
#include "ui_WritingPanel.h"
#include <qlist.h>
#include <qcolor.h>

class RecordVideoNotifyEvent;
class AbstractButton;
class FigurePopupWidget;

class WritingPanel : public QWidget, public RecordVideoChain {

private:
	Ui::WritingPanel ui;

private:
	QList<AbstractButton*> items;

	QColor color;
	int width;

private:
	FigurePopupWidget *figurePopupWidget;


public:
	WritingPanel(QWidget *parent = nullptr);
	~WritingPanel();

	virtual void update(RecordVideoNotifyEvent *event);

	private slots:
	void cursorButtonClicked();
	void pencilButtonClicked();
	void eraserButtonClicked();
	void deleteAllButtonClicked();
	void highlightButtonClicked();
	void lineButtonClicked();
	void arrowLineButtonClicked();
	void numberingButtonClicked();
	void colorButtonClicked();
	void figureButtonClicked();
	void circleButtonClicked();
	void rectangleButtonClicked();
	void triangleButtonClicked();



private:
	void setColorButtonStyleSheets(const QColor &color);
};

#endif //_WRITINGPANEL_H
