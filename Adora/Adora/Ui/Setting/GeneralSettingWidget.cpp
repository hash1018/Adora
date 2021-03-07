
#include "GeneralSettingWidget.h"
#include "Base/SettingManager.h"
#include <qdesktopservices.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <qcollator.h>
#include <qfile.h>
#include <qmessagebox.h>

GeneralSettingWidget::GeneralSettingWidget(QWidget *parent)
	:QWidget(parent), listType(Video), orderBy(NameAsc) {

	ui.setupUi(this);

	connect(ui.searchPathButton, &QPushButton::clicked, this, &GeneralSettingWidget::searchPathButtonClicked);
	connect(ui.openDirectoryButton, &QPushButton::clicked, this, &GeneralSettingWidget::openDirectoryButtonClicked);

	connect(ui.videoButton, &QPushButton::clicked, this, &GeneralSettingWidget::videoButtonClicked);
	connect(ui.imageButton, &QPushButton::clicked, this, &GeneralSettingWidget::imageButtonClicked);


	ui.savePathLineEdit->setText(SettingManager::getInstance()->getGeneralSetting()->getSavePath());
	this->updateItemList();

	connect(ui.itemListWidget, &QListWidget::itemDoubleClicked, this, &GeneralSettingWidget::itemListDoubleClicked);

	connect(ui.deleteButton, &QPushButton::clicked, this, &GeneralSettingWidget::deleteButtonClicked);
}

GeneralSettingWidget::~GeneralSettingWidget() {

}

#include <qpainter.h>
void GeneralSettingWidget::paintEvent(QPaintEvent *event) {

	//QPainter painter(this);
	//painter.fillRect(this->rect(), QColor(12, 12, 12));
}

void GeneralSettingWidget::searchPathButtonClicked() {

	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::FileMode::DirectoryOnly);
	dialog.setDirectory(ui.savePathLineEdit->text());

	if (dialog.exec() == QDialog::Accepted) {
		ui.savePathLineEdit->setText(dialog.selectedFiles().first());
		SettingManager::getInstance()->getGeneralSetting()->setSavePath(ui.savePathLineEdit->text());

		this->updateItemList();
	}
}

void GeneralSettingWidget::openDirectoryButtonClicked() {

	QDesktopServices::openUrl(QUrl::fromLocalFile(ui.savePathLineEdit->text()));
}

void GeneralSettingWidget::videoButtonClicked() {

	this->listType = Video;
	this->updateItemList();
}

void GeneralSettingWidget::imageButtonClicked() {

	this->listType = Image;
	this->updateItemList();
}

void GeneralSettingWidget::itemListDoubleClicked(QListWidgetItem *item) {


}


void GeneralSettingWidget::deleteButtonClicked() {

	if (ui.itemListWidget->currentRow() == -1)
		return;

	auto item = ui.itemListWidget->item(ui.itemListWidget->currentRow());

	QFile file(item->text());
	if (file.exists() == true) {
	
		file.remove(item->text());
		
	}
	else {
	

	}

	this->updateItemList();
}

void GeneralSettingWidget::updateItemList() {

	ui.itemListWidget->clear();

	QString path = ui.savePathLineEdit->text();
	QDir dir(path);

	if (this->listType == Video) {

		dir.setNameFilters(QStringList() << "*.mp4");
	}
	else {
	
		dir.setNameFilters(QStringList() << "*.png" << "*.jpg");
	}

	if (this->orderBy == NameAsc || this->orderBy == NameDes) {

		auto list = dir.entryList(QDir::Filter::Files);

		QCollator collator;
		collator.setNumericMode(true);

		qSort(list.begin(), list.end(), collator);

		if (this->orderBy == NameAsc) {

			for (int i = 0; i < list.size(); i++) {

				ui.itemListWidget->addItem(path + "/" + list.at(i));
			}
		}
		else {

			for (int i = list.size() - 1; i >= 0; i++) {
				ui.itemListWidget->addItem(path + "/" + list.at(i));
			}
		}
	}
	else if (this->orderBy == DateAsc || this->orderBy == DateDes) {

		auto list = dir.entryInfoList(QDir::Filter::Files, QDir::SortFlag::Time);

		if (this->orderBy == NameAsc) {

			for (int i = 0; i < list.size(); i++) {

				ui.itemListWidget->addItem(list.at(i).filePath());
			}
		}
		else {

			for (int i = list.size() - 1; i >= 0; i++) {
				ui.itemListWidget->addItem(list.at(i).filePath());
			}
		}
	}
}

