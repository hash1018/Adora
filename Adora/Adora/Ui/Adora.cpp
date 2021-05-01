
#include "Adora.h"
#include <QMouseEvent>
#include "Base/SettingManager.h"

#include "Ui/Setting/GeneralSettingWidget.h"
#include "Ui/Setting/VideoSettingWidget.h"
#include "Ui/Setting/AudioSettingWidget.h"
#include "Ui/Setting/ImageSettingWidget.h"
#include "Ui/Setting/TimeLimitSettingWidget.h"
#include "Ui/Setting/WatermarkSettingWidget.h"
#include "Ui/Setting/WritingSettingWidget.h"
#include "Ui/Setting/LanguageSettingWidget.h"
#include "Ui/LicenseWidget.h"
#include "Ui/AboutWidget.h"


#include "Base/LanguageManager.h"

#include "Ui/Record/RecordVideoDialog.h"

#include <QGraphicsDropShadowEffect>
#include <qpainter.h>

Adora::Adora(QWidget *parent)
	: QMainWindow(parent), mousePressed(false), restart(false) {

	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);

	connect(ui.adoraFrameWidget, &AdoraFrameWidget::closeButtonClicked, this, &Adora::closeButtonClicked);
	connect(ui.adoraFrameWidget, &AdoraFrameWidget::minimizeButtonClicked, this, &Adora::minimizeButtonClicked);

	SettingManager::getInstance()->load();

	this->initPosition();
	this->initMenuStackWidget();
	this->initMenuButtons();


	ui.recordButton->setText("    " + getLanUiValue("Menu/Record"));
	connect(ui.recordButton, &QPushButton::clicked, this, &Adora::recordButtonClicked);

	this->setContentsMargins(0, 0, 5, 5);
	QGraphicsDropShadowEffect *wndShadow = new QGraphicsDropShadowEffect(this);
	wndShadow->setBlurRadius(5.0);
	wndShadow->setColor(QColor(0, 0, 0, 100));
	wndShadow->setOffset(2.0);
	this->setGraphicsEffect(wndShadow);
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

void Adora::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing); // Anti-aliasing;
	painter.setBrush(QBrush(QColor("#FFFFFF")));
	painter.setPen(Qt::transparent);
	QRect rect(QPoint(157, 66), QSize(745 - 157, 645 - 66));
	rect.setWidth(rect.width());
	rect.setHeight(rect.height());
	painter.drawRoundedRect(rect, 14, 14);


	//painter.fillRect(QRect(20, 0, this->width() - 20, 20), QColor("#FFFFFF"));
	//painter.fillRect(QRect(0, this->height() - 20, 20, 20), QColor("#FFFFFF"));
}


void Adora::closeButtonClicked() {

	this->close();
	
}

void Adora::minimizeButtonClicked() {

	this->showMinimized();
}

void Adora::recordButtonClicked() {

	this->hide();

	this->generalSettingWidget->connectFileSystemWatcher(false);

	this->recordVideoDialog = new RecordVideoDialog;
	connect(this->recordVideoDialog, &RecordVideoDialog::recordVideoDialogClosed, this, &Adora::recordVideoDialogFinished);
	this->recordVideoDialog->show();
}

void Adora::recordVideoDialogFinished(){

	this->recordVideoDialog->hide();
	disconnect(this->recordVideoDialog, &RecordVideoDialog::recordVideoDialogClosed, this, &Adora::recordVideoDialogFinished);
	this->recordVideoDialog->deleteLater();

	this->show();

	this->generalSettingWidget->connectFileSystemWatcher(true);

	this->generalSettingWidget->updateItemList();
}

void Adora::generalButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.generalButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->generalSettingWidget);
}

void Adora::videoButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.videoButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->videoSettingWidget);
}

void Adora::audioButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.audioButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->audioSettingWidget);
}

void Adora::imageButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.imageButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->imageSettingWidget);
}

void Adora::timeLimitButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.timeLimitButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->timeLimitSettingWidget);
}

void Adora::watermarkButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.watermarkButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->watermarkSettingWidget);
}

void Adora::writingButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.writingButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->writingSettingWidget);
}

void Adora::languageButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.languageButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->languageSettingWidget);
}

void Adora::licenseButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.licenseButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->licenseWidget);
}

void Adora::aboutButtonClicked() {

	for (int i = 0; i < this->menuButtons.size(); i++)
		this->menuButtons.at(i)->setSelected(false);

	ui.aboutButton->setSelected(true);

	ui.menuStackWidget->setCurrentWidget(this->aboutWidget);
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

void Adora::initMenuStackWidget() {

	this->generalSettingWidget = new GeneralSettingWidget(ui.menuStackWidget);
	this->videoSettingWidget = new VideoSettingWidget(ui.menuStackWidget);
	this->audioSettingWidget = new AudioSettingWidget(ui.menuStackWidget);
	this->imageSettingWidget = new ImageSettingWidget(ui.menuStackWidget);
	this->timeLimitSettingWidget = new TimeLimitSettingWidget(ui.menuStackWidget);
	this->watermarkSettingWidget = new WatermarkSettingWidget(ui.menuStackWidget);
	this->writingSettingWidget = new WritingSettingWidget(ui.menuStackWidget);
	this->languageSettingWidget = new LanguageSettingWidget(ui.menuStackWidget);
	this->licenseWidget = new LicenseWidget(ui.menuStackWidget);
	this->aboutWidget = new AboutWidget(ui.menuStackWidget);


	ui.menuStackWidget->addWidget(this->generalSettingWidget);
	ui.menuStackWidget->addWidget(this->videoSettingWidget);
	ui.menuStackWidget->addWidget(this->audioSettingWidget);
	ui.menuStackWidget->addWidget(this->imageSettingWidget);
	ui.menuStackWidget->addWidget(this->timeLimitSettingWidget);
	ui.menuStackWidget->addWidget(this->watermarkSettingWidget);
	ui.menuStackWidget->addWidget(this->writingSettingWidget);
	ui.menuStackWidget->addWidget(this->languageSettingWidget);
	ui.menuStackWidget->addWidget(this->licenseWidget);
	ui.menuStackWidget->addWidget(this->aboutWidget);

	ui.menuStackWidget->setCurrentIndex(0);

	connect(this->languageSettingWidget, &LanguageSettingWidget::requestChangeLanguage, this, &Adora::requestRestart);
}

void Adora::initMenuButtons() {


	ui.watermarkButton->hide();

	this->menuButtons.append(ui.generalButton);
	this->menuButtons.append(ui.videoButton);
	this->menuButtons.append(ui.audioButton);
	this->menuButtons.append(ui.imageButton);
	this->menuButtons.append(ui.timeLimitButton);
	this->menuButtons.append(ui.watermarkButton);
	this->menuButtons.append(ui.writingButton);
	this->menuButtons.append(ui.languageButton);
	this->menuButtons.append(ui.licenseButton);
	this->menuButtons.append(ui.aboutButton);


	ui.generalButton->setIcon(QIcon(":/Menu/general"));
	ui.generalButton->setSelected(true);


	ui.videoButton->setIcon(QIcon(":/Menu/video"));
	ui.audioButton->setIcon(QIcon(":/Menu/audio"));
	ui.imageButton->setIcon(QIcon(":/Menu/image"));
	ui.timeLimitButton->setIcon(QIcon(":/Menu/timeLimit"));
	ui.watermarkButton->setIcon(QIcon(":/Menu/watermark"));
	ui.writingButton->setIcon(QIcon(":/Menu/writing"));
	ui.languageButton->setIcon(QIcon(":/Menu/language"));
	ui.licenseButton->setIcon(QIcon(":/Menu/license"));
	ui.aboutButton->setIcon(QIcon(":/Menu/about"));

	
	ui.generalButton->setText(getLanUiValue("Menu/General"));
	ui.videoButton->setText(getLanUiValue("Menu/Video"));
	ui.audioButton->setText(getLanUiValue("Menu/Audio"));
	ui.imageButton->setText(getLanUiValue("Menu/Image"));
	ui.timeLimitButton->setText(getLanUiValue("Menu/Timelimit"));
	ui.watermarkButton->setText(getLanUiValue("Menu/Watermark"));
	ui.writingButton->setText(getLanUiValue("Menu/Writing"));
	ui.languageButton->setText(getLanUiValue("Menu/Language"));
	ui.licenseButton->setText(getLanUiValue("Menu/License"));
	ui.aboutButton->setText(getLanUiValue("Menu/About"));


	connect(ui.generalButton, &QPushButton::clicked, this, &Adora::generalButtonClicked);
	connect(ui.videoButton, &QPushButton::clicked, this, &Adora::videoButtonClicked);
	connect(ui.audioButton, &QPushButton::clicked, this, &Adora::audioButtonClicked);
	connect(ui.imageButton, &QPushButton::clicked, this, &Adora::imageButtonClicked);
	connect(ui.timeLimitButton, &QPushButton::clicked, this, &Adora::timeLimitButtonClicked);
	connect(ui.watermarkButton, &QPushButton::clicked, this, &Adora::watermarkButtonClicked);
	connect(ui.writingButton, &QPushButton::clicked, this, &Adora::writingButtonClicked);
	connect(ui.languageButton, &QPushButton::clicked, this, &Adora::languageButtonClicked);
	connect(ui.licenseButton, &QPushButton::clicked, this, &Adora::licenseButtonClicked);
	connect(ui.aboutButton, &QPushButton::clicked, this, &Adora::aboutButtonClicked);


}