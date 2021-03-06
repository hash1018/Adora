

#ifndef _LANGUAGESETTINGWIDGET_H
#define _LANGUAGESETTINGWIDGET_H

#include <qwidget.h>

class LanguageSettingWidget : public QWidget {

public:
	LanguageSettingWidget(QWidget *parent = nullptr);
	~LanguageSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

};

#endif //_LANGUAGESETTINGWIDGET_H