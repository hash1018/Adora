
#include "ImageSettingWidget.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"

ImageSettingWidget::ImageSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	ui.includeCursorCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getIncludeCursor());
	ui.imageCaptureHotkeyCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey());
	ui.imageCaptureHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey());

	connect(ui.includeCursorCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::includeCursorCheckBoxToggled);
	connect(ui.imageCaptureHotkeyCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled);
	

	QString str = "<b>" + getLanUiValue("MenuImage/Capture Image") + "</b>";
	ui.imageCpatureLabel->setTextFormat(Qt::RichText);
	ui.imageCpatureLabel->setText(str);

	ui.includeCursorCheckBox->setText(getLanUiValue("MenuImage/Include Cursor"));
	ui.imageFormatLabel->setText(getLanUiValue("MenuImage/Image Format"));
	ui.imageCaptureHotkeyCheckBox->setText(getLanUiValue("MenuImage/Image Capture Hotkey"));
}

ImageSettingWidget::~ImageSettingWidget() {

}

void ImageSettingWidget::includeCursorCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getImageSetting()->setIncludeCursor(checked);
}

void ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getImageSetting()->setUseImageCaptureHotkey(checked);

	ui.imageCaptureHotkeyLineEdit->setDisabled(!checked);
}