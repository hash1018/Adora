
#include "GeneralSettingWidget.h"
#include "Base/SettingManager.h"
#include <qdesktopservices.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <qcollator.h>
#include <qfile.h>
#include <qmessagebox.h>
#include "Base/LanguageManager.h"
#include <qfilesystemwatcher.h>

GeneralSettingWidget::GeneralSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent), listType(Video), orderBy(NameAsc) {

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


	QString str = "<b>" + getLanUiValue("MenuGeneral/SavePath") + "</b>";
	ui.savePathLabel->setTextFormat(Qt::RichText);
	ui.savePathLabel->setText(str);

	ui.openDirectoryButton->setText(getLanUiValue("MenuGeneral/Open"));

	ui.deleteButton->setText("   " + getLanUiValue("MenuGeneral/Delete"));
	ui.uploadButton->setText("   " + getLanUiValue("MenuGeneral/Upload"));
	ui.playButton->setText("   " + getLanUiValue("MenuGeneral/Play"));

	ui.videoButton->setText("    " + getLanUiValue("MenuGeneral/Video"));
	ui.imageButton->setText("    " + getLanUiValue("MenuGeneral/Image"));
	ui.orderByButton->setText("    " + getLanUiValue("MenuGeneral/Sort"));



	ui.uploadButton->hide();
	ui.playButton->hide();

	this->fileSystemWatcher = new QFileSystemWatcher(this);
	this->fileSystemWatcher->addPath(SettingManager::getInstance()->getGeneralSetting()->getSavePath());
	connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &GeneralSettingWidget::directoryChanged);
}

GeneralSettingWidget::~GeneralSettingWidget() {

	if (this->orderByMenu != nullptr)
		delete this->orderByMenu;
}


void GeneralSettingWidget::searchPathButtonClicked() {

	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::FileMode::DirectoryOnly);
	dialog.setDirectory(ui.savePathLineEdit->text());

	if (dialog.exec() == QDialog::Accepted) {

		this->fileSystemWatcher->removePath(SettingManager::getInstance()->getGeneralSetting()->getSavePath());

		ui.savePathLineEdit->setText(dialog.selectedFiles().first());
		SettingManager::getInstance()->getGeneralSetting()->setSavePath(ui.savePathLineEdit->text());

		this->fileSystemWatcher->addPath(SettingManager::getInstance()->getGeneralSetting()->getSavePath());

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

/*
#ifdef Q_OS_WIN
#include <wmp.h>
#pragma comment(lib,"Winmm.lib")
#endif 
*/
void GeneralSettingWidget::itemListDoubleClicked(QListWidgetItem *item) {

	/*
#ifdef Q_OS_WIN
	IWMPPlayer4 *player;
	CoCreateInstance(CLSID_WindowsMediaPlayer, NULL, CLSCTX_ALL, IID_IWMPPlayer4, (void**)&player);
	
	BSTR bstr = SysAllocStringLen(0, item->text().length());
	item->text().toWCharArray(bstr);

	player->openPlayer(bstr);

#endif 
	*/
	
}


void GeneralSettingWidget::deleteButtonClicked() {

	if (ui.itemListWidget->currentRow() == -1)
		return;

	auto item = ui.itemListWidget->item(ui.itemListWidget->currentRow());

	QString path = ui.savePathLineEdit->text();
	QString filePath = path + "/" + item->text();

	QFile file(filePath);
	if (file.exists() == true) {
	
		disconnect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &GeneralSettingWidget::directoryChanged);

		file.remove(filePath);

		connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &GeneralSettingWidget::directoryChanged);
		
	}
	else {
	
		QMessageBox box;
		box.setText(getLanMessageValue("The file does not exist in the directory."));
		box.exec();
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

	ui.videoButton->updateSelected(false);
	ui.imageButton->updateSelected(false);

	if (this->listType == ListType::Video)
		ui.videoButton->updateSelected(true);
	else if (this->listType == ListType::Image)
		ui.imageButton->updateSelected(true);

	ui.itemListWidget->clear();

	QString path = ui.savePathLineEdit->text();
	QDir dir(path);

	if (this->listType == Video) {

		dir.setNameFilters(QStringList() << "*.mp4");
	}
	else {
	
		dir.setNameFilters(QStringList() << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif" << "*.tif" << "*.tiff");
	}

	if (this->orderBy == NameAsc || this->orderBy == NameDes) {

		auto list = dir.entryList(QDir::Filter::Files);

		QCollator collator;
		collator.setNumericMode(true);

		qSort(list.begin(), list.end(), collator);

		if (this->orderBy == NameAsc) {

			for (int i = 0; i < list.size(); i++) {

				ui.itemListWidget->addItem(list.at(i));
			}
		}
		else {

			for (int i = list.size() - 1; i >= 0; i--) {
				ui.itemListWidget->addItem(list.at(i));
			}
		}
	}
	else if (this->orderBy == DateAsc || this->orderBy == DateDes) {

		auto list = dir.entryInfoList(QDir::Filter::Files, QDir::SortFlag::Time);

		if (this->orderBy == DateAsc) {

			for (int i = 0; i < list.size(); i++) {

				ui.itemListWidget->addItem(list.at(i).fileName());
			}
		}
		else {

			for (int i = list.size() - 1; i >= 0; i--) {
				ui.itemListWidget->addItem(list.at(i).fileName());
			}
		}
	}
}

void GeneralSettingWidget::directoryChanged(const QString &path) {

	this->updateItemList();
}

void GeneralSettingWidget::connectFileSystemWatcher(bool connect1) {

	if (connect1 == true) {
		connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &GeneralSettingWidget::directoryChanged);
	}
	else {
		disconnect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &GeneralSettingWidget::directoryChanged);
	}
}




////////////////////////////////////////////////////////////////////////

OrderByMenu::OrderByMenu(QWidget *parent)
	:QMenu(parent) {
	
	this->orderByNameAction = new QAction(getLanUiValue("OrderBy/Name"), this);
	this->orderByNameAction->setCheckable(true);

	this->orderByDateAction = new QAction(getLanUiValue("OrderBy/Date"), this);
	this->orderByDateAction->setCheckable(true);

	this->orderByAscAction = new QAction(getLanUiValue("OrderBy/Asc"), this);
	this->orderByAscAction->setCheckable(true);

	this->orderByDescAction = new QAction(getLanUiValue("OrderBy/Desc"), this);
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