

#ifndef _WATERMARKSETTINGWIDGET_H
#define _WATERMARKSETTINGWIDGET_H


#include <qwidget.h>
#include "ui_WatermarkSettingWidget.h"

class WatermarkSettingWidget : public QWidget {

	Q_OBJECT

private:
	Ui::WatermarkSettingWidget ui;

public:
	WatermarkSettingWidget(QWidget *parent = nullptr);
	~WatermarkSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);


	private slots:
	void useWatermarkCheckBoxClicked();
	void openExplorerButtonClicked();
	void opacitySpinBoxValueChanged(int value);
	void layoutRadioButtonClicked();
	
};

#endif //_WATERMARKSETTINGWIDGET_H