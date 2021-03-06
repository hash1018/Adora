
#include "GeneralSettingWidget.h"
#include "Base/SettingManager.h"

GeneralSettingWidget::GeneralSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	connect(ui.searchPathButton, &QPushButton::clicked, this, &GeneralSettingWidget::searchPathButtonClicked);
	connect(ui.openDirectoryButton, &QPushButton::clicked, this, &GeneralSettingWidget::openDirectoryButtonClicked);


	ui.savePathLineEdit->setText(SettingManager::getInstance()->getGeneralSetting()->getSavePath());
}

GeneralSettingWidget::~GeneralSettingWidget() {

}

#include <qpainter.h>
void GeneralSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(12, 12, 12));
}

#include <qfiledialog.h>
void GeneralSettingWidget::searchPathButtonClicked() {

	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::FileMode::DirectoryOnly);
	dialog.setDirectory(ui.savePathLineEdit->text());

	if (dialog.exec() == QDialog::Accepted) {
		ui.savePathLineEdit->setText(dialog.selectedFiles().first());
		SettingManager::getInstance()->getGeneralSetting()->setSavePath(ui.savePathLineEdit->text());
	}
}

#include <qdesktopservices.h>
void GeneralSettingWidget::openDirectoryButtonClicked() {

	QDesktopServices::openUrl(QUrl::fromLocalFile(ui.savePathLineEdit->text()));
}