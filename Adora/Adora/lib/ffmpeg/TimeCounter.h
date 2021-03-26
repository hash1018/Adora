

#ifndef _TIMECOUNTER_H
#define _TIMECOUNTER_H

#include <qobject.h>
#include <qtimer.h>
class Time;

class TimeCounter : public QObject {

	Q_OBJECT

private:
	QTimer *timer;
	Time *mainTime;

public:
	TimeCounter(Time *mainTime);
	~TimeCounter();


signals:
	void timePassed(Time &time);


	public slots:
	void start();
	void finish();

	private slots:
	void timePassed();

};

#endif //_TIMECOUNTER_H
