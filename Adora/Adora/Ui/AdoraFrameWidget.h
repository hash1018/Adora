

#ifndef _ADORAFRAMEWIDGET_H
#define _ADORAFRAMEWIDGET_H

#include <qwidget.h>
#include "ui_AdoraFrameWidget.h"

class AdoraFrameWidget : public QWidget {

	Q_OBJECT

private:
	Ui::AdoraFrameWidget ui;

public:
	AdoraFrameWidget(QWidget *parent = nullptr);
	~AdoraFrameWidget();


public:
	signals:
		   void closeButtonClicked();
		   void minimizeButtonClicked();


protected:
	virtual void paintEvent(QPaintEvent *event);
};

#endif //_ADORAFRAMEWIDGET_H