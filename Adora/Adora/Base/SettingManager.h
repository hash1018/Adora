

#ifndef _SETTINGMANAGER_H
#define _SETTINGMANAGER_H

#include "Singleton.h"
#include <qpoint.h>
#include <qstring.h>

class GeneralSetting {

	friend class SettingManager;

private:
	QString savePath;

private:
	GeneralSetting();
	~GeneralSetting();

	void load();
	void save();

public:
	void setSavePath(const QString &path) { this->savePath = path; }

public:
	inline const QString& getSavePath() const { return this->savePath; }

};


////////////////////////////////////////////////////////

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
	GeneralSetting generalSetting;
	LanguageSetting languageSetting;
	

public:
	void load();
	void save();
	
public:
	void setAdoraPosition(const QPoint &point) { this->adoraPosition = point; }


public:
	inline const QPoint& getAdoraPosition() const { return this->adoraPosition; }

	inline GeneralSetting* getGeneralSetting() { return &(this->generalSetting); }
	inline LanguageSetting* getLanguageSetting() { return &(this->languageSetting); }
	
};

//////////////////////////////////////////////////////////////


#endif //_SETTINGMANAGER_H
