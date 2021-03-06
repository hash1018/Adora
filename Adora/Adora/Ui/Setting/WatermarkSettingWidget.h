

#ifndef _WATERMARKSETTINGWIDGET_H
#define _WATERMARKSETTINGWIDGET_H


#include <qwidget.h>

class WatermarkSettingWidget : public QWidget {

public:
	WatermarkSettingWidget(QWidget *parent = nullptr);
	~WatermarkSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);
};

#endif //_WATERMARKSETTINGWIDGET_H