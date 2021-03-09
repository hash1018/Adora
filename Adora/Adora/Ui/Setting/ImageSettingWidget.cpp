
#include "ImageSettingWidget.h"
#include "Base/SettingManager.h"

ImageSettingWidget::ImageSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	ui.includeCursorCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getIncludeCursor());
	ui.imageCaptureHotkeyCheckBox->setChecked(SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey());

	connect(ui.includeCursorCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::includeCursorCheckBoxToggled);
	connect(ui.imageCaptureHotkeyCheckBox, &QCheckBox::toggled, this, &ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled);
}

ImageSettingWidget::~ImageSettingWidget() {

}

//#include <qpainter.h>
void ImageSettingWidget::paintEvent(QPaintEvent *event) {

	//QPainter painter(this);
	//painter.fillRect(this->rect(), QColor(50, 50, 12));
}

void ImageSettingWidget::includeCursorCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getImageSetting()->setIncludeCursor(checked);
}

void ImageSettingWidget::useImageCaptureHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getImageSetting()->setUseImageCaptureHotkey(checked);
}