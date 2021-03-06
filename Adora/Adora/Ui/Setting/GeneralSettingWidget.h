

#ifndef _GENERALSETTINGWIDGET_H
#define _GENERALSETTINGWIDGET_H

#include <qwidget.h>
#include "ui_GeneralSettingWidget.h"

class GeneralSettingWidget : public QWidget {

private:
	Ui::GeneralSettingWidget ui;

public:
	GeneralSettingWidget(QWidget *parent = nullptr);
	~GeneralSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void searchPathButtonClicked();
	void openDirectoryButtonClicked();
};

#endif //_GENERALSETTINGWIDGET_H
