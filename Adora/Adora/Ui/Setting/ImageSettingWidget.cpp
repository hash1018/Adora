
#include "ImageSettingWidget.h"
#include "Base/SettingManager.h"

ImageSettingWidget::ImageSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	ui.includeCursorCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getIncludeCursor());
	ui.imageCaptureHotkeyCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey());

	connect(ui.includeCursorCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::includeCursorCheckBoxToggled);
	connect(ui.imageCaptureHotkeyCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled);
}

ImageSettingWidget::~ImageSettingWidget() {

}

void ImageSettingWidget::includeCursorCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getImageSetting()->setIncludeCursor(checked);
}

void ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getImageSetting()->setUseImageCaptureHotkey(checked);
}