

#ifndef _FIGUREPOPUPWIDGET_H
#define _FIGUREPOPUPWIDGET_H

#include <qwidget.h>
#include "ui_FigurePopupWidget.h"

class FigurePopupWidget : public QWidget {

private:
	Ui::FigurePopupWidget ui;

public:
	FigurePopupWidget();
	~FigurePopupWidget();
	

protected:
	virtual void paintEvent(QPaintEvent *event);



};



#endif //_FIGUREPOPUPWIDGET_H
