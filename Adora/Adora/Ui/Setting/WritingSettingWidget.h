

#ifndef _WRITINGSETTINGWIDGET_H
#define _WRITINGSETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_WritingSettingWidget.h"

class WritingSettingWidget : public AbstractStackWidget {

private:
	Ui::WritingSettingWidget ui;

public:
	WritingSettingWidget(QWidget *parent = nullptr);
	~WritingSettingWidget();


};


#endif //_WRITINGSETTINGWIDGET_H