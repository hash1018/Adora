

#ifndef _IMAGESETTINGWIDGET_H
#define _IMAGESETTINGWIDGET_H

#include <qwidget.h>

class ImageSettingWidget : public QWidget {

public:
	ImageSettingWidget(QWidget *parent = nullptr);
	~ImageSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);


};

#endif //_IMAGESETTINGWIDGET_H