

#ifndef _AUDIOSETTINGWIDGET_H
#define _AUDIOSETTINGWIDGET_H

#include <qwidget.h>

class AudioSettingWidget : public QWidget {

public:
	AudioSettingWidget(QWidget *parent = nullptr);
	~AudioSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);


};

#endif //_AUDIOSETTINGWIDGET_H