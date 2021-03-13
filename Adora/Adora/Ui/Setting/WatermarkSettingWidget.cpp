

#include "WatermarkSettingWidget.h"
#include "Base/SettingManager.h"
#include <qfiledialog.h>
#include <qfile.h>

WatermarkSettingWidget::WatermarkSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	ui.useWatermarkCheckBox->setChecked(SettingManager::getInstance()->getWatermarkSetting()->getUseWatermark());
	

	QString filePath = SettingManager::getInstance()->getWatermarkSetting()->getImagePath();
	QFile file(filePath);

	if (file.exists() == true) {
		ui.imagePathLineEdit->setText(filePath);
	}
	else {
		SettingManager::getInstance()->getWatermarkSetting()->setImagePath("");
	}




	ui.opacitySpinBox->setValue(SettingManager::getInstance()->getWatermarkSetting()->getOpacity());


	WatermarkSetting::Layout layout = SettingManager::getInstance()->getWatermarkSetting()->getLayout();

	if (layout == WatermarkSetting::Layout::TopLeft) {
		ui.topLeftRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::TopCenter) {
		ui.topCenterRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::TopRight) {
		ui.topRightRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::CenterLeft) {
		ui.centerLeftRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::CenterCenter) {
		ui.centerCenterRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::CenterRight) {
		ui.centerRightRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::BottomLeft) {
		ui.bottomLeftRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::BottomCenter) {
		ui.bottomCenterRadioButton->setChecked(true);
	}
	else if (layout == WatermarkSetting::Layout::BottomRight) {
		ui.bottomRightRadioButton->setChecked(true);
	}


	connect(ui.useWatermarkCheckBox, &QCheckBox::clicked, this, &WatermarkSettingWidget::useWatermarkCheckBoxClicked);

	connect(ui.openExplorerButton, &QPushButton::clicked, this, &WatermarkSettingWidget::openExplorerButtonClicked);

	connect(ui.opacitySpinBox, SIGNAL(valueChanged(int)), this, SLOT(opacitySpinBoxValueChanged(int)));

	connect(ui.topLeftRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.topCenterRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.topRightRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.centerLeftRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.centerCenterRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.centerRightRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.bottomLeftRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.bottomCenterRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	connect(ui.bottomRightRadioButton, &QRadioButton::clicked, this, &WatermarkSettingWidget::layoutRadioButtonClicked);
	
}

WatermarkSettingWidget::~WatermarkSettingWidget() {

}

#include <qpainter.h>
void WatermarkSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(100, 100, 100));
}

void WatermarkSettingWidget::useWatermarkCheckBoxClicked() {

	if (ui.useWatermarkCheckBox->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setUseWatermark(true);
	}
	else {
		SettingManager::getInstance()->getWatermarkSetting()->setUseWatermark(false);
	}
}


void WatermarkSettingWidget::openExplorerButtonClicked() {

	QFileDialog dialog(this);
	dialog.setNameFilters(QStringList() << "*.png" << "*.jpg");
	dialog.setFileMode(QFileDialog::FileMode::ExistingFile);

	if (dialog.exec() == QDialog::Accepted) {
		ui.imagePathLineEdit->setText(dialog.selectedFiles().first());
		SettingManager::getInstance()->getWatermarkSetting()->setImagePath(ui.imagePathLineEdit->text());
	}
}


void WatermarkSettingWidget::opacitySpinBoxValueChanged(int value) {

	SettingManager::getInstance()->getWatermarkSetting()->setOpacity(value);
}

void WatermarkSettingWidget::layoutRadioButtonClicked() {

	if (ui.topLeftRadioButton->isChecked() == true) {
	
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::TopLeft);
	}
	else if (ui.topCenterRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::TopCenter);
	}
	else if (ui.topRightRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::TopRight);
	}
	else if (ui.centerLeftRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::CenterLeft);
	}
	else if (ui.centerCenterRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::CenterCenter);
	}
	else if (ui.centerRightRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::CenterRight);
	}
	else if (ui.bottomLeftRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::BottomLeft);
	}
	else if (ui.bottomCenterRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::BottomCenter);
	}
	else if (ui.bottomRightRadioButton->isChecked() == true) {
		SettingManager::getInstance()->getWatermarkSetting()->setLayout(WatermarkSetting::Layout::BottomRight);
	}
}