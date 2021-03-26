

#include "Time.h"

Time::Time()
	:minutes(0), seconds(0), hours(0), milliseconds(0) {

}

Time::Time(const Time &other)
	: milliseconds(other.milliseconds), seconds(other.seconds), minutes(other.minutes), hours(other.hours) {

}


Time::~Time() {

}

Time& Time::operator=(const Time &other) {

	this->mutex.lock();

	this->milliseconds = other.milliseconds;
	this->seconds = other.seconds;
	this->minutes = other.minutes;
	this->hours = other.hours;

	this->mutex.unlock();

	return *this;
}

Time& Time::operator=(uint64_t milliseconds) {

	*this = Time::convertTime(milliseconds);

	return *this;
}

bool Time::operator>=(const Time &other) {

	if (Time::convertMilliseconds(*this) >= Time::convertMilliseconds(other)) {

		return true;
	}

	return false;
}

bool Time::operator<=(const Time &other) {

	if (Time::convertMilliseconds(*this) <= Time::convertMilliseconds(other)) {

		return true;
	}

	return false;
}

bool Time::operator==(const Time &other) {

	if (Time::convertMilliseconds(*this) == Time::convertMilliseconds(other)) {

		return true;
	}

	return false;
}

bool Time::operator!=(const Time &other) {

	if (Time::convertMilliseconds(*this) != Time::convertMilliseconds(other)) {

		return true;
	}

	return false;
}

bool Time::operator>(const Time &other) {

	if (Time::convertMilliseconds(*this) > Time::convertMilliseconds(other)) {

		return true;
	}

	return false;
}

bool Time::operator<(const Time &other) {

	if (Time::convertMilliseconds(*this) < Time::convertMilliseconds(other)) {

		return true;
	}

	return false;
}

void Time::passSecond() {

	this->mutex.lock();

	this->seconds++;

	if (this->seconds >= 60) {

		this->seconds = 0;
		this->minutes++;

		if (this->minutes >= 60) {

			this->minutes = 0;
			this->hours++;
		}
	}

	this->mutex.unlock();
}

void Time::passMillisecond(int millisecond) {

	this->mutex.lock();

	this->milliseconds += millisecond;

	if (milliseconds >= 1000) {

		this->seconds++;

		if (this->seconds >= 60) {

			this->seconds = 0;
			this->minutes++;

			if (this->minutes >= 60) {

				this->minutes = 0;
				this->hours++;
			}
		}

		this->milliseconds -= 1000;
	}

	this->mutex.unlock();
}

void Time::clear() {

	this->mutex.lock();

	this->milliseconds = 0;
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;

	this->mutex.unlock();
}


uint64_t Time::convertMilliseconds(const Time &time) {

	Time time2 = time;

	uint64_t milliseconds = time2.getMilliseconds();
	uint64_t seconds = time2.getSeconds();
	uint64_t minutes = time2.getMinutes();
	uint64_t hours = time2.getHours();

	minutes += hours * 60;
	seconds += minutes * 60;
	milliseconds += (seconds * 1000);

	return milliseconds;
}

Time Time::convertTime(uint64_t milliseconds) {

	Time time;

	if (milliseconds >= 3600000) {

		time.hours = milliseconds / 3600000;
		milliseconds %= 3600000;
	}

	if (milliseconds >= 60000) {

		time.minutes = milliseconds / 60000;
		milliseconds %= 60000;
	}

	if (milliseconds >= 1000) {

		time.seconds = milliseconds / 1000;

		milliseconds %= 1000;
	}

	time.milliseconds = milliseconds;


	return time;
}