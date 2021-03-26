

#include "TimeCounter.h"
#include "Base/Time.h"

#define TimeInterval 10

TimeCounter::TimeCounter(Time *mainTime)
	:mainTime(mainTime), timer(nullptr) {

}

TimeCounter::~TimeCounter() {


}

void TimeCounter::timePassed() {

	int second = this->mainTime->getSeconds();

	this->mainTime->passMillisecond(TimeInterval);

	int nextSecond = this->mainTime->getSeconds();

	if (second != nextSecond)
		emit this->timePassed(*this->mainTime);
}

void TimeCounter::start() {

	if (this->timer == nullptr) {

		this->timer = new QTimer(this);
		this->timer->setTimerType(Qt::PreciseTimer);
		connect(this->timer, SIGNAL(timeout()), this, SLOT(timePassed()));
		this->timer->setInterval(TimeInterval);
	}

	this->timer->start();

}

void TimeCounter::finish() {

	this->timer->stop();
}