

#ifndef _GENERALSETTINGWIDGET_H
#define _GENERALSETTINGWIDGET_H

#include <qwidget.h>
#include "ui_GeneralSettingWidget.h"
#include <qmenu.h>


class QAction;
class OrderByMenu;

class GeneralSettingWidget : public QWidget {

	Q_OBJECT

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

private:
	OrderByMenu *orderByMenu;

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
	void orderByButtonClicked();
	void orderByMenuActionClicked(OrderBy orderBy);

private:
	void updateItemList();
};



///////////////////////////////////////////////////////

class OrderByMenu : public QMenu {

	Q_OBJECT


private:
	GeneralSettingWidget::OrderBy currentOrder;

	QAction *orderByNameAction;
	QAction *orderByDateAction;
	QAction *orderByAscAction;
	QAction *orderByDescAction;

public:
	OrderByMenu(QWidget *parent = nullptr);
	~OrderByMenu();

	void setCurrentOrderBy(GeneralSettingWidget::OrderBy currentOrder);
	
signals:
	void orderActionClicked(GeneralSettingWidget::OrderBy orderBy);

	private slots:

	void orderByNameActionClicked();
	void orderByDateActionClicked();
	void orderByAscActionClicked();
	void orderByDescActionClicked();

};

#endif //_GENERALSETTINGWIDGET_H
