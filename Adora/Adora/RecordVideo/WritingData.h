

#ifndef _WRITINGDATA_H
#define _WRITINGDATA_H

#include <qcolor.h>
#include <qlist.h>
#include "Base/Namespace.h"
#include <qstring.h>

class WritingData {

private:
	class Data {

		friend class WritingData;
	private:
		QColor color;
		int width;
		WritingStatus status;

	private:
		Data(WritingStatus status)
			:width(2), status(status) {

		}

		~Data() {

		}
	};


private:
	QList<WritingData::Data*> list;

public:
	WritingData();
	~WritingData();

	void load();
	void save();

public:
	QColor getColor(WritingStatus status);
	int getWidth(WritingStatus status);
	void setColor(WritingStatus status, const QColor &color);
	void setWidth(WritingStatus status, int width);


private:
	int getIndex(WritingStatus status);
};



#endif //_WRITINGDATA_H
