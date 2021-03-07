
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


	this->orderByMenu = new OrderByMenu(this);
	this->orderByMenu->setCurrentOrderBy(this->orderBy);

	connect(this->orderByMenu, &OrderByMenu::orderActionClicked, this, &GeneralSettingWidget::orderByMenuActionClicked);
	connect(ui.orderByButton, &QPushButton::clicked, this, &GeneralSettingWidget::orderByButtonClicked);
}

GeneralSettingWidget::~GeneralSettingWidget() {

	if (this->orderByMenu != nullptr)
		delete this->orderByMenu;
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
	
		//QMessageBox;
	}

	this->updateItemList();
}

void GeneralSettingWidget::orderByButtonClicked() {

	this->orderByMenu->exec(QCursor::pos());
}

void GeneralSettingWidget::orderByMenuActionClicked(GeneralSettingWidget::OrderBy orderBy) {

	this->orderBy = orderBy;

	this->orderByMenu->setCurrentOrderBy(this->orderBy);

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

			for (int i = list.size() - 1; i >= 0; i--) {
				ui.itemListWidget->addItem(path + "/" + list.at(i));
			}
		}
	}
	else if (this->orderBy == DateAsc || this->orderBy == DateDes) {

		auto list = dir.entryInfoList(QDir::Filter::Files, QDir::SortFlag::Time);

		if (this->orderBy == DateAsc) {

			for (int i = 0; i < list.size(); i++) {

				ui.itemListWidget->addItem(list.at(i).filePath());
			}
		}
		else {

			for (int i = list.size() - 1; i >= 0; i--) {
				ui.itemListWidget->addItem(list.at(i).filePath());
			}
		}
	}
}





////////////////////////////////////////////////////////////////////////

OrderByMenu::OrderByMenu(QWidget *parent)
	:QMenu(parent) {

	this->orderByNameAction = new QAction(QString::fromLocal8Bit("이름"), this);
	this->orderByNameAction->setCheckable(true);

	this->orderByDateAction = new QAction(QString::fromLocal8Bit("날짜"), this);
	this->orderByDateAction->setCheckable(true);

	this->orderByAscAction = new QAction(QString::fromLocal8Bit("오름차순"), this);
	this->orderByAscAction->setCheckable(true);

	this->orderByDescAction = new QAction(QString::fromLocal8Bit("내림차순"), this);
	this->orderByDescAction->setCheckable(true);

	this->addAction(this->orderByNameAction);
	this->addAction(this->orderByDateAction);
	this->addSeparator();
	this->addAction(this->orderByAscAction);
	this->addAction(this->orderByDescAction);

	connect(this->orderByNameAction, &QAction::triggered, this, &OrderByMenu::orderByNameActionClicked);
	connect(this->orderByDateAction, &QAction::triggered, this, &OrderByMenu::orderByDateActionClicked);
	connect(this->orderByAscAction, &QAction::triggered, this, &OrderByMenu::orderByAscActionClicked);
	connect(this->orderByDescAction, &QAction::triggered, this, &OrderByMenu::orderByDescActionClicked);

}

OrderByMenu::~OrderByMenu() {



}


void OrderByMenu::setCurrentOrderBy(GeneralSettingWidget::OrderBy currentOrder) {

	this->currentOrder = currentOrder;

	this->orderByNameAction->setChecked(false);
	this->orderByDateAction->setChecked(false);
	this->orderByAscAction->setChecked(false);
	this->orderByDescAction->setChecked(false);

	switch (currentOrder)
	{

	case GeneralSettingWidget::OrderBy::NameAsc:
		this->orderByNameAction->setChecked(true);
		this->orderByAscAction->setChecked(true);
		break;

	case GeneralSettingWidget::OrderBy::NameDes:
		this->orderByNameAction->setChecked(true);
		this->orderByDescAction->setChecked(true);
		break;

	case GeneralSettingWidget::OrderBy::DateDes:
		this->orderByDateAction->setChecked(true);
		this->orderByDescAction->setChecked(true);
		break;

	case GeneralSettingWidget::OrderBy::DateAsc:
		this->orderByDateAction->setChecked(true);
		this->orderByAscAction->setChecked(true);
		break;

	default:
		break;
	}

}



void OrderByMenu::orderByNameActionClicked() {

	if (this->orderByAscAction->isChecked() == true) {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::NameAsc);
	}
	else {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::NameDes);
	}
}

void OrderByMenu::orderByDateActionClicked() {

	if (this->orderByAscAction->isChecked() == true) {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::DateAsc);
	}
	else {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::DateDes);
	}
}


void OrderByMenu::orderByAscActionClicked() {

	if (this->orderByNameAction->isChecked() == true) {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::NameAsc);
	}
	else {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::DateAsc);
	}

}

void OrderByMenu::orderByDescActionClicked() {

	if (this->orderByNameAction->isChecked() == true) {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::NameDes);
	}
	else {

		emit this->orderActionClicked(GeneralSettingWidget::OrderBy::DateDes);
	}
}