

#ifndef _SETTINGMANAGER_H
#define _SETTINGMANAGER_H

#include "Singleton.h"
#include <qpoint.h>



class LanguageSetting {

	friend class SettingManager;

public:
	enum Language {

		English,
		Korean,
	};

private:
	Language language;

private:
	LanguageSetting();
	~LanguageSetting();

	void load();
	void save();

public:
	void setLanguage(Language language) { this->language = language; }

public:
	inline Language getLanguage() const { return this->language; }
};



//////////////////////////////////////////////////////////////////////

class SettingManager {

	DeclareSingleton(SettingManager)

private:
	QPoint adoraPosition;

private:
	LanguageSetting languageSetting;

public:
	void load();
	void save();
	
public:
	void setAdoraPosition(const QPoint &point) { this->adoraPosition = point; }


public:
	inline const QPoint& getAdoraPosition() const { return this->adoraPosition; }
	inline LanguageSetting* getLanguageSetting() { return &(this->languageSetting); }
	
};

//////////////////////////////////////////////////////////////


#endif //_SETTINGMANAGER_H
