

#ifndef _LICENSEWIDGET_H
#define _LICENSEWIDGET_H

#include <qwidget.h>
#include "ui_LicenseWidget.h"

class LicenseWidget : public QWidget {
	
private:
	Ui::LicenseWidget ui;

public:
	LicenseWidget(QWidget *parent = nullptr);
	~LicenseWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);
};


#endif //_LICENSEWIDGET_H