




#ifndef _TIME_H
#define _TIME_H

#include <qmutex.h>

class Time {

private:
	int seconds;
	int minutes;
	int hours;
	int milliseconds;

private:
	QMutex mutex;

public:
	Time();
	Time(const Time &other);
	~Time();

public:
	Time& operator=(const Time &other);
	Time& operator=(uint64_t milliseconds);

	bool operator>=(const Time &other);
	bool operator<=(const Time &other);
	bool operator==(const Time &other);
	bool operator!=(const Time &other);
	bool operator>(const Time &other);
	bool operator<(const Time &other);
public:

	void passSecond();
	void passMillisecond(int millisecond);
	void clear();

	inline Time getTime() {

		Time time;
		time = *this;
		return time;
	}

	inline int getSeconds() {

		this->mutex.lock();
		int seconds = this->seconds;
		this->mutex.unlock();
		return seconds;
	}

	inline int getMinutes() {

		this->mutex.lock();
		int minutes = this->minutes;
		this->mutex.unlock();
		return minutes;
	}

	inline int getHours() {

		this->mutex.lock();
		int hours = this->hours;
		this->mutex.unlock();
		return hours;
	}

	inline int getMilliseconds() {

		this->mutex.lock();
		int milliseconds = this->milliseconds;
		this->mutex.unlock();
		return milliseconds;
	}

	static uint64_t convertMilliseconds(const Time &time);
	static Time convertTime(uint64_t milliseconds);
};

#endif //_TIME_H
