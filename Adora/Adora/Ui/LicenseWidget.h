

#ifndef _LICENSEWIDGET_H
#define _LICENSEWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_LicenseWidget.h"

class LicenseWidget : public AbstractStackWidget {
	
private:
	Ui::LicenseWidget ui;

public:
	LicenseWidget(QWidget *parent = nullptr);
	~LicenseWidget();

protected:

};


#endif //_LICENSEWIDGET_H