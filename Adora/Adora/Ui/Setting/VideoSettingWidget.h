

#ifndef _VIDEOSETTINGWIDGET_H
#define _VIDEOSETTINGWIDGET_H

#include <qwidget.h>

class VideoSettingWidget : public QWidget {

public:
	VideoSettingWidget(QWidget *parent = nullptr);
	~VideoSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);


};

#endif //_VIDEOSETTINGWIDGET_H