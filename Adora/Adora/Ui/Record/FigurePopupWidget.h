

#ifndef _FIGUREPOPUPWIDGET_H
#define _FIGUREPOPUPWIDGET_H

#include <qwidget.h>
#include "ui_FigurePopupWidget.h"
#include "Base/Namespace.h"

class FigurePopupWidget : public QWidget {

	Q_OBJECT

private:
	Ui::FigurePopupWidget ui;

public:
	FigurePopupWidget();
	~FigurePopupWidget();

	void setWritingStatus(WritingStatus status);

signals:
	void circleButtonClicked();
	void rectangleButtonClicked();
	void triangleButtonClicked();

};

#endif //_FIGUREPOPUPWIDGET_H
