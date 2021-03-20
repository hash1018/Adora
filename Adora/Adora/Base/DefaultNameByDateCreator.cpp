

#include "DefaultNameByDateCreator.h"
#include <qdatetime.h>
DefaultNameByDateCreator::DefaultNameByDateCreator() {


}

DefaultNameByDateCreator::~DefaultNameByDateCreator() {

}


QString DefaultNameByDateCreator::create() {

	QString text;

	text += QString::number(QDate::currentDate().year());
	text += "-" + QString::number(QDate::currentDate().month());
	text += "-" + QString::number(QDate::currentDate().day());
	text += " " + QString::number(QTime::currentTime().hour());
	text += "-" + QString::number(QTime::currentTime().minute());
	text += "-" + QString::number(QTime::currentTime().second());
	text += "-" + QString::number(QTime::currentTime().msec());

	return text;
}