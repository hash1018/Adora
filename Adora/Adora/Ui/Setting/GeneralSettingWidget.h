

#ifndef _GENERALSETTINGWIDGET_H
#define _GENERALSETTINGWIDGET_H

#include <qwidget.h>
#include "ui_GeneralSettingWidget.h"

class GeneralSettingWidget : public QWidget {


public:
	enum ListType {
		Video,
		Image,
	};

	enum OrderBy {
		NameAsc,
		NameDes,
		DateAsc,
		DateDes,
	};

private:
	Ui::GeneralSettingWidget ui;

private:
	ListType listType;
	OrderBy orderBy;

public:
	GeneralSettingWidget(QWidget *parent = nullptr);
	~GeneralSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void searchPathButtonClicked();
	void openDirectoryButtonClicked();
	void videoButtonClicked();
	void imageButtonClicked();
	void itemListDoubleClicked(QListWidgetItem *item);
	void deleteButtonClicked();

private:
	void updateItemList();
};

#endif //_GENERALSETTINGWIDGET_H
