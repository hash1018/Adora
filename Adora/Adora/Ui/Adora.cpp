
#include "Adora.h"
#include <QMouseEvent>
#include "Base/SettingManager.h"

#include "Ui/Setting/GeneralSettingWidget.h"
#include "Ui/Setting/VideoSettingWidget.h"
#include "Ui/Setting/AudioSettingWidget.h"
#include "Ui/Setting/ImageSettingWidget.h"
#include "Ui/Setting/TimeLimitSettingWidget.h"
#include "Ui/Setting/WatermarkSettingWidget.h"
#include "Ui/Setting/LanguageSettingWidget.h"
#include "Ui/LicenseWidget.h"
#include "Ui/AboutWidget.h"


#include "Base/LanguageManager.h"

Adora::Adora(QWidget *parent)
	: QMainWindow(parent), mousePressed(false),restart(false) {

	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);

	connect(ui.adoraFrameWidget, &AdoraFrameWidget::closeButtonClicked, this, &Adora::closeButtonClicked);
	connect(ui.adoraFrameWidget, &AdoraFrameWidget::minimizeButtonClicked, this, &Adora::minimizeButtonClicked);

	SettingManager::getInstance()->load();

	this->initPosition();
	this->initMenuListWidget();
	this->initMenuStackWidget();

	connect(ui.recordButton, &QPushButton::clicked, this, &Adora::recordButtonClicked);
	connect(ui.menuListWidget, &QListWidget::itemClicked, this, &Adora::menuListItemClicked);

}

Adora::~Adora() {

}

void Adora::closeEvent(QCloseEvent *event) {

	QMainWindow::closeEvent(event);

	SettingManager::getInstance()->setAdoraPosition(this->pos());
	SettingManager::getInstance()->save();
}


void Adora::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->prev = event->globalPos();
}

void Adora::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		QPoint current = event->globalPos();

		QPoint delta = current - this->prev;

		this->move(this->x() + delta.x(), this->y() + delta.y());

		this->prev = current;
	}
}

void Adora::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
}

void Adora::closeButtonClicked() {

	this->close();
	
}

void Adora::minimizeButtonClicked() {

	this->showMinimized();
}

void Adora::recordButtonClicked() {


}

void Adora::menuListItemClicked(QListWidgetItem *item) {

	int index = ui.menuListWidget->row(item);
	ui.menuStackWidget->setCurrentIndex(index);
}

void Adora::requestRestart() {

	this->restart = true;
	this->close();
}

#include <qscreen.h>
void Adora::initPosition() {

	QPoint position = SettingManager::getInstance()->getAdoraPosition();

	QRect rect = QRect(position.x(), position.y(), this->minimumWidth(), this->minimumHeight());

	QList<QScreen*> screens = QGuiApplication::screens();
	QRect screenRect;

	for (int i = 0; i < screens.size(); i++) {
		screenRect = screenRect.united(screens.at(i)->geometry());
	}

	if (screenRect.contains(rect) == true) {
		this->setGeometry(rect);
	}
	else {
		this->setGeometry(0, 0, this->minimumWidth(), this->minimumHeight());
	}
}

void Adora::initMenuListWidget() {

	
	ui.menuListWidget->addItem(getLanUiValue("Menu/General"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/Video"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/Audio"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/Image"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/Timelimit"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/Watermark"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/Language"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/License"));
	ui.menuListWidget->addItem(getLanUiValue("Menu/About"));

	ui.menuListWidget->setCurrentRow(0);
}

void Adora::initMenuStackWidget() {

	this->generalSettingWidget = new GeneralSettingWidget(ui.menuStackWidget);
	this->videoSettingWidget = new VideoSettingWidget(ui.menuStackWidget);
	this->audioSettingWidget = new AudioSettingWidget(ui.menuStackWidget);
	this->imageSettingWidget = new ImageSettingWidget(ui.menuStackWidget);
	this->timeLimitSettingWidget = new TimeLimitSettingWidget(ui.menuStackWidget);
	this->watermarkSettingWidget = new WatermarkSettingWidget(ui.menuStackWidget);
	this->languageSettingWidget = new LanguageSettingWidget(ui.menuStackWidget);
	this->licenseWidget = new LicenseWidget(ui.menuStackWidget);
	this->aboutWidget = new AboutWidget(ui.menuStackWidget);


	ui.menuStackWidget->addWidget(this->generalSettingWidget);
	ui.menuStackWidget->addWidget(this->videoSettingWidget);
	ui.menuStackWidget->addWidget(this->audioSettingWidget);
	ui.menuStackWidget->addWidget(this->imageSettingWidget);
	ui.menuStackWidget->addWidget(this->timeLimitSettingWidget);
	ui.menuStackWidget->addWidget(this->watermarkSettingWidget);
	ui.menuStackWidget->addWidget(this->languageSettingWidget);
	ui.menuStackWidget->addWidget(this->licenseWidget);
	ui.menuStackWidget->addWidget(this->aboutWidget);

	ui.menuStackWidget->setCurrentIndex(0);

	connect(this->languageSettingWidget, &LanguageSettingWidget::requestChangeLanguage, this, &Adora::requestRestart);
}