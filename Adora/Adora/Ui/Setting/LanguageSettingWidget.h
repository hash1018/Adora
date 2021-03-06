

#ifndef _LANGUAGESETTINGWIDGET_H
#define _LANGUAGESETTINGWIDGET_H

#include <qwidget.h>
#include "ui_LanguageSettingWidget.h"

class LanguageSettingWidget : public QWidget {

	Q_OBJECT

private:
	Ui::LanguageSettingWidget ui;

public:
	LanguageSettingWidget(QWidget *parent = nullptr);
	~LanguageSettingWidget();

signals:
	void requestChangeLanguage();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void changeButtonClicked();

};

#endif //_LANGUAGESETTINGWIDGET_H