

#include "VideoSettingWidget.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"
#include <qdebug.h>
#include "Base/Hotkey.h"

VideoSettingWidget::VideoSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	ui.startStopHotkeyCheckBox->setChecked(SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey());
	ui.startStopHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey());

	if (SettingManager::getInstance()->getVideoSetting()->getStartStopHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getVideoSetting()->getStartStopHotkey());
		hotkey->setType(HotkeyType::VideoStartAndStop);
		ui.startStopHotkeyLineEdit->load(hotkey);
	}

	ui.pauseResumeHotkeyCheckBox->setChecked(SettingManager::getInstance()->getVideoSetting()->getUsePauseAndResumeHotkey());
	ui.pauseResumeHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getVideoSetting()->getUsePauseAndResumeHotkey());

	if (SettingManager::getInstance()->getVideoSetting()->getPauseResumeHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getVideoSetting()->getPauseResumeHotkey());
		hotkey->setType(HotkeyType::VideoPauseAndResume);
		ui.pauseResumeHotkeyLineEdit->load(hotkey);
	}

	ui.includeCursorCheckBox->setChecked(SettingManager::getInstance()->getVideoSetting()->getIncludeCursor());

	ui.useHwEncoderCheckBox->setChecked(SettingManager::getInstance()->getVideoSetting()->getUseHwEncoder());
	ui.hwEncoderComboBox->setDisabled(!SettingManager::getInstance()->getVideoSetting()->getUseHwEncoder());

	ui.fpsComboBox->addItems(QStringList() << "10" << "15" << "20" << "25" << "30");
	ui.fpsComboBox->setCurrentText(QString::number(SettingManager::getInstance()->getVideoSetting()->getFps()));
	ui.videoBitrateSpinBox->setValue(SettingManager::getInstance()->getVideoSetting()->getVideoBitrate() / 1000);


	connect(ui.startStopHotkeyCheckBox, &QCheckBox::toggled, this, &VideoSettingWidget::startStopCheckBoxToggled);
	connect(ui.startStopHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &VideoSettingWidget::startStopHotkeyEmitted);

	connect(ui.pauseResumeHotkeyCheckBox, &QCheckBox::toggled, this, &VideoSettingWidget::pauseResumeCheckBoxToggled);
	connect(ui.pauseResumeHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &VideoSettingWidget::pauseResumeHotkeyEmitted);

	connect(ui.includeCursorCheckBox, &QCheckBox::toggled, this, &VideoSettingWidget::includeCursorCheckBoxToggled);
	connect(ui.useHwEncoderCheckBox, &QCheckBox::toggled, this, &VideoSettingWidget::useHwEncoderCheckBoxToggled);
	connect(ui.fpsComboBox, &QComboBox::currentTextChanged, this, &VideoSettingWidget::fpsComboBoxCurrentTextChanged);
	connect(ui.videoBitrateSpinBox, SIGNAL(valueChanged(int)), this, SLOT(videoBitrateSpinBoxValueChanged(int)));


	QString str = "<b>" + getLanUiValue("MenuVideo/Record Screen") + "</b>";
	ui.screenRecordLabel->setTextFormat(Qt::RichText);
	ui.screenRecordLabel->setText(str);

	ui.startStopHotkeyCheckBox->setText(getLanUiValue("MenuVideo/Start/Stop Hotkey"));
	ui.pauseResumeHotkeyCheckBox->setText(getLanUiValue("MenuVideo/Pause/Resume Hotkey"));
	ui.includeCursorCheckBox->setText(getLanUiValue("MenuVideo/Include Cursor"));
	ui.useHwEncoderCheckBox->setText(getLanUiValue("MenuVideo/Hardware Accelerate"));
	ui.fpsLabel->setText(getLanUiValue("MenuVideo/FPS"));
	ui.videoBitrateLabel->setText(getLanUiValue("MenuVideo/Video Bitrate"));
}

VideoSettingWidget::~VideoSettingWidget() {

}

void VideoSettingWidget::startStopCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getVideoSetting()->setUseStartAndStopHotkey(checked);

	
	ui.startStopHotkeyLineEdit->setDisabled(!checked);
}


void VideoSettingWidget::startStopHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getVideoSetting()->setStartStopHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::VideoStartAndStop);
}


void VideoSettingWidget::pauseResumeCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getVideoSetting()->setUsePauseAndResumeHotkey(checked);

	ui.pauseResumeHotkeyLineEdit->setDisabled(!checked);
}

void VideoSettingWidget::pauseResumeHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getVideoSetting()->setPauseResumeHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::VideoPauseAndResume);
}

void VideoSettingWidget::includeCursorCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getVideoSetting()->setIncludeCursor(checked);
}

void VideoSettingWidget::useHwEncoderCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getVideoSetting()->setUseHwEncoder(checked);

	ui.hwEncoderComboBox->setDisabled(!checked);
}

void VideoSettingWidget::fpsComboBoxCurrentTextChanged(const QString &text) {

	SettingManager::getInstance()->getVideoSetting()->setFps(text.toInt());
}

void VideoSettingWidget::videoBitrateSpinBoxValueChanged(int value) {

	SettingManager::getInstance()->getVideoSetting()->setVideoBitrate(value * 1000);
}