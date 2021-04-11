

#ifndef _SOUNDAMPLITUDERENDERWIDGET_H
#define _SOUNDAMPLITUDERENDERWIDGET_H

#include <qwidget.h>

class SoundAmplitudeRenderWidget : public QWidget {

private:
	float amplitude;

private:
	bool isDisable;

public:
	SoundAmplitudeRenderWidget(QWidget *parent = nullptr);
	~SoundAmplitudeRenderWidget();

	void setAmplitude(float amplitude);
	void setDisabled(bool disabled);

protected:
	virtual void paintEvent(QPaintEvent *event);

};


#endif //_SOUNDAMPLITUDERENDERWIDGET_H