

#ifndef _WRITINGLAYER_H
#define _WRITINGLAYER_H

#include <qwidget.h>
class QGraphicsOpacityEffect;

class WritingLayer : public QWidget {

private:
	QGraphicsOpacityEffect *effect;

public:
	WritingLayer(QWidget *parent = nullptr);
	~WritingLayer();

protected:
	virtual void paintEvent(QPaintEvent *event);

};

#endif //_WRITINGLAYER_H