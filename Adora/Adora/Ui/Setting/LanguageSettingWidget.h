

#ifndef _LANGUAGESETTINGWIDGET_H
#define _LANGUAGESETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_LanguageSettingWidget.h"

class LanguageSettingWidget : public AbstractStackWidget {

	Q_OBJECT

private:
	Ui::LanguageSettingWidget ui;

public:
	LanguageSettingWidget(QWidget *parent = nullptr);
	~LanguageSettingWidget();

signals:
	void requestChangeLanguage();

protected:
	

	private slots:
	void changeButtonClicked();

};

#endif //_LANGUAGESETTINGWIDGET_H