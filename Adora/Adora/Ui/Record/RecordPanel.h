

#ifndef _RECORDPANEL_H
#define _RECORDPANEL_H

#include <qwidget.h>
#include "ui_RecordPanel.h"
class RecordPanel : public QWidget {

private:
	Ui::RecordPanel ui;

public:
	RecordPanel(QWidget *parent = nullptr);
	~RecordPanel();

};

#endif //_RECORDPANEL_H