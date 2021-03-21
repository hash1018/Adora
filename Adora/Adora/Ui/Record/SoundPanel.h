
#ifndef _SOUNDPANEL_H
#define _SOUNDPANEL_H

#include <qwidget.h>
#include "ui_SoundPanel.h"
#include "RecordVideo/Chain/RecordVideoChain.h"

class SoundPanel : public QWidget , public RecordVideoChain {

private:
	Ui::SoundPanel ui;

public:
	SoundPanel(QWidget *parent = nullptr);
	~SoundPanel();
};

#endif //_SOUNDPANEL_H