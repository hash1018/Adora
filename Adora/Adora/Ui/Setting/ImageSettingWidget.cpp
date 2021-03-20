
#include "ImageSettingWidget.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"

ImageSettingWidget::ImageSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	ui.includeCursorCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getIncludeCursor());

	ui.imageCaptureHotkeyCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey());

	ui.imageCaptureHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey());
	ui.imageCaptureHotkeyLineEdit->load(SettingManager::getInstance()->getImageSetting()->getImageCaptureHotkey().toString());

	connect(ui.includeCursorCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::includeCursorCheckBoxToggled);
	connect(ui.imageCaptureHotkeyCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled);
	connect(ui.imageCaptureHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &ImageSettingWidget::imageCaptureHotkeyEmitted);

	

	QString str = "<b>" + getLanUiValue("MenuImage/Capture Image") + "</b>";
	ui.imageCpatureLabel->setTextFormat(Qt::RichText);
	ui.imageCpatureLabel->setText(str);

	ui.includeCursorCheckBox->setText(getLanUiValue("MenuImage/Include Cursor"));
	ui.imageFormatLabel->setText(getLanUiValue("MenuImage/Image Format"));
	ui.imageCaptureHotkeyCheckBox->setText(getLanUiValue("MenuImage/Image Capture Hotkey"));


	//png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif" << "*.tif" << "*.tiff

	ui.imageFormatComboBox->addItem("png");
	ui.imageFormatComboBox->addItem("jpg");
	ui.imageFormatComboBox->addItem("jpeg");
	ui.imageFormatComboBox->addItem("bmp");
	ui.imageFormatComboBox->addItem("gif");
	ui.imageFormatComboBox->addItem("tif");
	ui.imageFormatComboBox->addItem("tiff");

	ui.imageFormatComboBox->setCurrentText(SettingManager::getInstance()->getImageSetting()->getImageFormat());
	connect(ui.imageFormatComboBox, &QComboBox::currentTextChanged, this, &ImageSettingWidget::currentImageFormatComboBoxTextChanged);
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

void ImageSettingWidget::imageCaptureHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getImageSetting()->setImageCaptureHotkey(keySequence);
}

void ImageSettingWidget::currentImageFormatComboBoxTextChanged(const QString &text) {

	SettingManager::getInstance()->getImageSetting()->setImageFormat(text);
}