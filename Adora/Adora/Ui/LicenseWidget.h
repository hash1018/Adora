

#ifndef _LICENSEWIDGET_H
#define _LICENSEWIDGET_H

#include <qwidget.h>

class LicenseWidget : public QWidget {

public:
	LicenseWidget(QWidget *parent = nullptr);
	~LicenseWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);
};


#endif //_LICENSEWIDGET_H