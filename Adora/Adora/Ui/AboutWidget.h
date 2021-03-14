

#ifndef _ABOUTWIDGET_H
#define _ABOUTWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_AboutWidget.h"

class AboutWidget : public AbstractStackWidget {

private:
	Ui::AboutWidget ui;

public:
	AboutWidget(QWidget *parent = nullptr);
	~AboutWidget();

protected:

};


#endif //_ABOUTWIDGET_H