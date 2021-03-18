

#ifndef _ADORAINFO_H
#define _ADORAINFO_H


#include "Singleton.h"
#include <qstring.h>

class AdoraInfo {

	DeclareSingleton(AdoraInfo)

private:
	QString version;
	QString email;
	QString github;
	QString name;

public:
	inline const QString& getVersion() const { return this->version; }
	inline const QString& getEmail() const { return this->email; }
	inline const QString& getGithub() const { return this->github; }
	inline const QString& getName() const { return this->name; }

};

#endif //_ADORAINFO_H