

#include "TimeLimitSettingWidget.h"
#include "Base/SettingManager.h"
TimeLimitSettingWidget::TimeLimitSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	ui.useTimeLimitCheckBox->setChecked(SettingManager::getInstance()->getTimeLimitSetting()->getUseTimeLimit());
	ui.hourSpinBox->setValue(SettingManager::getInstance()->getTimeLimitSetting()->getHour());
	ui.minuteSpinBox->setValue(SettingManager::getInstance()->getTimeLimitSetting()->getMinute());
	ui.secondSpinBox->setValue(SettingManager::getInstance()->getTimeLimitSetting()->getSecond());


	connect(ui.useTimeLimitCheckBox, &QCheckBox::toggled, this, &TimeLimitSettingWidget::useTimeLimitCheckBoxToggled);
	connect(ui.hourSpinBox, SIGNAL(valueChanged(int)), this, SLOT(hourSpinBoxValueChanged(int)));
	connect(ui.minuteSpinBox, SIGNAL(valueChanged(int)), this, SLOT(minuteSpinBoxValueChanged(int)));
	connect(ui.secondSpinBox, SIGNAL(valueChanged(int)), this, SLOT(secondSpinBoxValueChanged(int)));
}

TimeLimitSettingWidget::~TimeLimitSettingWidget() {

}

//#include <qpainter.h>
void TimeLimitSettingWidget::paintEvent(QPaintEvent *event) {

	//QPainter painter(this);
	//painter.fillRect(this->rect(), QColor(77, 77, 77));
}

void TimeLimitSettingWidget::useTimeLimitCheckBoxToggled(bool checked){

	SettingManager::getInstance()->getTimeLimitSetting()->setUseTimeLimit(checked);
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