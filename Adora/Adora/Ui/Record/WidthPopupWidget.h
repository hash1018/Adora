

#ifndef _WIDTHPOPUPWIDGET_H
#define _WIDTHPOPUPWIDGET_H

#include <qwidget.h>
#include "ui_WidthPopupWidget.h"
#include "Base/Namespace.h"

class WidthPopupWidget : public QWidget {

	Q_OBJECT

private:
	Ui::WidthPopupWidget ui;

private:
	int width_;
	WritingStatus writingStatus;

public:
	WidthPopupWidget();
	~WidthPopupWidget();


	void setWidth(int width);
	void setWritingStatus(WritingStatus writingStatus);

signals:
	void currentWidthChanged(int width);

private:
	void updateList();

	private slots:
	void currentRowChanged(int row);
};

#endif //_WIDTHPOPUPWIDGET_H