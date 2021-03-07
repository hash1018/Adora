

#ifndef _LANGUAGEMANAGER_H
#define _LANGUAGEMANAGER_H

#include "Singleton.h"
#include <qstring.h>

#define getLanUiValue(key) (LanguageManager::getInstance()->getValue(LanguageManager::Ui,key))
#define getLanMessageValue(key) (LanguageManager::getInstance()->getValue(LanguageManager::Message,key))

class QSettings;

class LanguageManager {

	DeclareSingleton(LanguageManager)

public:
	enum Language {

		English,
		Korean,
	};

	enum Type {

		Ui,
		Message,
	};

private:
	Language language;
	QSettings *settings;
	Type type;

public:
	bool setLanguage(Language language);
	QString getValue(const Type &type, const QString &key);

private:
	static QString convertDirectoryName(Language language);
	static QString convertFileName(Type type);


};

#endif //_LANGUAGEMANAGER_H