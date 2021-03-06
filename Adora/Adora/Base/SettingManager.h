

#ifndef _SETTINGMANAGER_H
#define _SETTINGMANAGER_H

#include "Singleton.h"
#include <qpoint.h>

class SettingManager {

	DeclareSingleton(SettingManager)

private:
	QPoint adoraPosition;

public:
	void load();
	void save();
	
public:
	void setAdoraPosition(const QPoint &point) { this->adoraPosition = point; }


public:
	inline const QPoint& getAdoraPosition() const { return this->adoraPosition; }

	
};

#endif //_SETTINGMANAGER_H
