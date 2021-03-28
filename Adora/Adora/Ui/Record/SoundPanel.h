
#ifndef _SOUNDPANEL_H
#define _SOUNDPANEL_H

#include <qwidget.h>
#include "ui_SoundPanel.h"
#include "RecordVideo/Chain/RecordVideoChain.h"

class RecordVideoNotifyEvent;

class SoundPanel : public QWidget , public RecordVideoChain {

private:
	Ui::SoundPanel ui;

public:
	SoundPanel(QWidget *parent = nullptr);
	~SoundPanel();

	void update(RecordVideoNotifyEvent *event);


	private slots:
	void speakerButtonClicked();
	void micButtonClicked();
};

#endif //_SOUNDPANEL_H