

#include "TimeLimitSettingWidget.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"

TimeLimitSettingWidget::TimeLimitSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	bool checked = SettingManager::getInstance()->getTimeLimitSetting()->getUseTimeLimit();
	ui.useTimeLimitCheckBox->setChecked(checked);
	ui.hourSpinBox->setValue(SettingManager::getInstance()->getTimeLimitSetting()->getHour());
	ui.minuteSpinBox->setValue(SettingManager::getInstance()->getTimeLimitSetting()->getMinute());
	ui.secondSpinBox->setValue(SettingManager::getInstance()->getTimeLimitSetting()->getSecond());

	ui.hourSpinBox->setDisabled(!checked);
	ui.minuteSpinBox->setDisabled(!checked);
	ui.secondSpinBox->setDisabled(!checked);


	connect(ui.useTimeLimitCheckBox, &QCheckBox::toggled, this, &TimeLimitSettingWidget::useTimeLimitCheckBoxToggled);
	connect(ui.hourSpinBox, SIGNAL(valueChanged(int)), this, SLOT(hourSpinBoxValueChanged(int)));
	connect(ui.minuteSpinBox, SIGNAL(valueChanged(int)), this, SLOT(minuteSpinBoxValueChanged(int)));
	connect(ui.secondSpinBox, SIGNAL(valueChanged(int)), this, SLOT(secondSpinBoxValueChanged(int)));


	QString str = "<b>" + getLanUiValue("MenuTimeLimit/TimeLimit") + "</b>";
	ui.timeLimitLabel->setTextFormat(Qt::RichText);
	ui.timeLimitLabel->setText(str);
}

TimeLimitSettingWidget::~TimeLimitSettingWidget() {

}

void TimeLimitSettingWidget::useTimeLimitCheckBoxToggled(bool checked){

	SettingManager::getInstance()->getTimeLimitSetting()->setUseTimeLimit(checked);

	ui.hourSpinBox->setDisabled(!checked);
	ui.minuteSpinBox->setDisabled(!checked);
	ui.secondSpinBox->setDisabled(!checked);
}

void TimeLimitSettingWidget::hourSpinBoxValueChanged(int value) {

	SettingManager::getInstance()->getTimeLimitSetting()->setHour(value);
}

void TimeLimitSettingWidget::minuteSpinBoxValueChanged(int value) {

	SettingManager::getInstance()->getTimeLimitSetting()->setMinute(value);
}

void TimeLimitSettingWidget::secondSpinBoxValueChanged(int value) {

	SettingManager::getInstance()->getTimeLimitSetting()->setSecond(value);
}