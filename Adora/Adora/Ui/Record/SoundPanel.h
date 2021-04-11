
#ifndef _SOUNDPANEL_H
#define _SOUNDPANEL_H

#include <qwidget.h>
#include "ui_SoundPanel.h"
#include "RecordVideo/Chain/RecordVideoChain.h"

class RecordVideoNotifyEvent;
class VolumeLevelGetter;

class SoundPanel : public QWidget , public RecordVideoChain {

private:
	Ui::SoundPanel ui;

private:
	VolumeLevelGetter *speakerVolumeGetter;
	VolumeLevelGetter *micVolumeGetter;

public:
	SoundPanel(QWidget *parent = nullptr);
	~SoundPanel();

	void update(RecordVideoNotifyEvent *event);


	private slots:
	void speakerButtonClicked();
	void micButtonClicked();
	
	void speakerAmplitudeChanged(float level);
	void micAmplitudeChanged(float level);
};

#endif //_SOUNDPANEL_H