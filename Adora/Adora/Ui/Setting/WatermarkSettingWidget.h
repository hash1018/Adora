

#ifndef _WATERMARKSETTINGWIDGET_H
#define _WATERMARKSETTINGWIDGET_H


#include "Ui/AbstractStackWidget.h"
#include "ui_WatermarkSettingWidget.h"

class WatermarkSettingWidget : public AbstractStackWidget {

	Q_OBJECT

private:
	Ui::WatermarkSettingWidget ui;

public:
	WatermarkSettingWidget(QWidget *parent = nullptr);
	~WatermarkSettingWidget();

protected:

	private slots:
	void useWatermarkCheckBoxClicked();
	void openExplorerButtonClicked();
	void opacitySpinBoxValueChanged(int value);
	void layoutRadioButtonClicked();
	
};

#endif //_WATERMARKSETTINGWIDGET_H