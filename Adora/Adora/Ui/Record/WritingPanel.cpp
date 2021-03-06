

#include "WritingPanel.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"
#include <qcolordialog.h>
#include "FigurePopupWidget.h"
#include "WidthPopupWidget.h"

WritingPanel::WritingPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	connect(ui.cursorButton, &QPushButton::clicked, this, &WritingPanel::cursorButtonClicked);
	connect(ui.pencilButton, &QPushButton::clicked, this, &WritingPanel::pencilButtonClicked);
	connect(ui.eraserButton, &QPushButton::clicked, this, &WritingPanel::eraserButtonClicked);
	connect(ui.deleteAllButton, &QPushButton::clicked, this, &WritingPanel::deleteAllButtonClicked);
	connect(ui.highlightButton, &QPushButton::clicked, this, &WritingPanel::highlightButtonClicked);
	connect(ui.lineButton, &QPushButton::clicked, this, &WritingPanel::lineButtonClicked);
	connect(ui.arrowLineButton, &QPushButton::clicked, this, &WritingPanel::arrowLineButtonClicked);
	connect(ui.numberingButton, &QPushButton::clicked, this, &WritingPanel::numberingButtonClicked);
	connect(ui.colorButton, &QPushButton::clicked, this, &WritingPanel::colorButtonClicked);
	connect(ui.figureButton, &QPushButton::clicked, this, &WritingPanel::figureButtonClicked);
	connect(ui.widthButton, &QPushButton::clicked, this, &WritingPanel::widthButtonClicked);
	

	this->items.append(ui.cursorButton);
	this->items.append(ui.pencilButton);
	this->items.append(ui.eraserButton);
	this->items.append(ui.highlightButton);
	this->items.append(ui.lineButton);
	this->items.append(ui.arrowLineButton);
	this->items.append(ui.numberingButton);
	this->items.append(ui.figureButton);

	//////////
	QString str = getLanUiValue("WritingPanel/Cursor");
	if (SettingManager::getInstance()->getWritingSetting()->getCursorHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseCursorHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getCursorHotkey().toString();
	}
	ui.cursorButton->setToolTip(str);

	///////////

	str = getLanUiValue("WritingPanel/Pencil");
	if (SettingManager::getInstance()->getWritingSetting()->getPencilHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUsePencilHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getPencilHotkey().toString();
	}
	ui.pencilButton->setToolTip(str);

	//////////

	str = getLanUiValue("WritingPanel/Highlighter");
	if (SettingManager::getInstance()->getWritingSetting()->getHighlightHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseHighlightHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getHighlightHotkey().toString();
	}
	ui.highlightButton->setToolTip(str);

	/////////

	str = getLanUiValue("WritingPanel/Line");
	if (SettingManager::getInstance()->getWritingSetting()->getLineHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseLineHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getLineHotkey().toString();
	}
	ui.lineButton->setToolTip(str);

	//////////

	str = getLanUiValue("WritingPanel/ArrowLine");
	if (SettingManager::getInstance()->getWritingSetting()->getArrowLineHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseArrowLineHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getArrowLineHotkey().toString();
	}
	ui.arrowLineButton->setToolTip(str);


	///////////

	str = getLanUiValue("WritingPanel/Numbering");
	if (SettingManager::getInstance()->getWritingSetting()->getNumberingHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseNumberingHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getNumberingHotkey().toString();
	}
	ui.numberingButton->setToolTip(str);

	///////////

	str = getLanUiValue("WritingPanel/Eraser");
	if (SettingManager::getInstance()->getWritingSetting()->getEraserHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseEraserHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getEraserHotkey().toString();
	}
	ui.eraserButton->setToolTip(str);

	///////////

	str = getLanUiValue("WritingPanel/DeleteAll");
	if (SettingManager::getInstance()->getWritingSetting()->getDeleteAllHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseDeleteAllHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getDeleteAllHotkey().toString();
	}
	ui.deleteAllButton->setToolTip(str);


	//////////


	ui.colorButton->setToolTip(getLanUiValue("WritingPanel/Change Color"));

	ui.widthButton->setToolTip(getLanUiValue("WritingPanel/Change Width"));



	/////////

	ui.figureButton->setToolTip(getLanUiValue("WritingPanel/Select Figures"));


	this->figurePopupWidget = new FigurePopupWidget;

	connect(this->figurePopupWidget, &FigurePopupWidget::circleButtonClicked, this, &WritingPanel::circleButtonClicked);
	connect(this->figurePopupWidget, &FigurePopupWidget::rectangleButtonClicked, this, &WritingPanel::rectangleButtonClicked);
	connect(this->figurePopupWidget, &FigurePopupWidget::triangleButtonClicked, this, &WritingPanel::triangleButtonClicked);


	this->widthPopupWidget = new WidthPopupWidget;
	connect(this->widthPopupWidget, &WidthPopupWidget::currentWidthChanged, this, &WritingPanel::currentWidthChanged);

}

WritingPanel::~WritingPanel() {

	if (this->figurePopupWidget != nullptr)
		delete this->figurePopupWidget;

}
#include <qdebug.h>
void WritingPanel::update(RecordVideoNotifyEvent *event) {

	if (event->getType() == RecordVideoNotifyEvent::EventType::WritingModeChanged) {
	
		for (int i = 0; i < this->items.size(); i++) {
			this->items.at(i)->updateSelected(false);
		}

		ui.colorButton->setDisabled(false);
		ui.widthButton->setDisabled(false);

		WritingStatus status = dynamic_cast<RecordVideoWritingModeChangedEvent*>(event)->getStatus();
		QColor color = dynamic_cast<RecordVideoWritingModeChangedEvent*>(event)->getColor();
		int width = dynamic_cast<RecordVideoWritingModeChangedEvent*>(event)->getWidth();
		
		this->color = color;
		this->width = width;

		this->setColorButtonStyleSheets(color);

		ui.widthButton->setText(QString::number(this->width));
		this->widthPopupWidget->setWidth(this->width);
		this->widthPopupWidget->setWritingStatus(status);

		if (status == WritingStatus::Cursor) {
			ui.cursorButton->updateSelected(true);
			ui.colorButton->setDisabled(true);
			ui.widthButton->setDisabled(true);
			ui.widthButton->setText("");
		}
		else if (status == WritingStatus::Pencil) {
			ui.pencilButton->updateSelected(true);
		}
		else if (status == WritingStatus::Eraser) {
			ui.eraserButton->updateSelected(true);
			ui.colorButton->setDisabled(true);
			ui.widthButton->setDisabled(true);
			ui.widthButton->setText("");
		}
		else if (status == WritingStatus::Highlight)
			ui.highlightButton->updateSelected(true);
		else if (status == WritingStatus::Line)
			ui.lineButton->updateSelected(true);
		else if (status == WritingStatus::ArrowLine)
			ui.arrowLineButton->updateSelected(true);
		else if (status == WritingStatus::Numbering)
			ui.numberingButton->updateSelected(true);

		else if (status == WritingStatus::WritingStatus_Circle ||
			status == WritingStatus::WritingStatus_Rectangle ||
			status == WritingStatus::WritingStatus_Triangle) {

			ui.figureButton->updateSelected(true);
			this->figurePopupWidget->setWritingStatus(status);
		}
	}
	else if (event->getType() == RecordVideoNotifyEvent::EventType::WritingDataChanged) {
		
		RecordVideoWritingDataChangedEvent *event2 = dynamic_cast<RecordVideoWritingDataChangedEvent*>(event);

		if (event2->getChangedType() == RecordVideoWritingDataChangedEvent::ChangedType::ChangedType_Color) {

			this->color = event2->getColor();

			this->setColorButtonStyleSheets(this->color);
			
		}
		else if (event2->getChangedType() == RecordVideoWritingDataChangedEvent::ChangedType::ChangedType_Width) {

			this->width = event2->getWidth();

			ui.widthButton->setText(QString::number(event2->getWidth()));

			this->widthPopupWidget->setWidth(event2->getWidth());
		}
	}
}

void WritingPanel::cursorButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Cursor);
	this->request(&request);

}

void WritingPanel::pencilButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Pencil);
	this->request(&request);
}

void WritingPanel::eraserButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Eraser);
	this->request(&request);
}

void WritingPanel::deleteAllButtonClicked() {

	RecordVideoRequestWritingDeleteAll request;
	this->request(&request);
}

void WritingPanel::highlightButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Highlight);
	this->request(&request);
}

void WritingPanel::lineButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Line);
	this->request(&request);
}

void WritingPanel::arrowLineButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::ArrowLine);
	this->request(&request);
}

void WritingPanel::numberingButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Numbering);
	this->request(&request);
}

void WritingPanel::colorButtonClicked() {

	QColorDialog dialog;
	dialog.setCurrentColor(this->color);
	dialog.setWindowFlag(Qt::WindowStaysOnTopHint);
	if (dialog.exec() == QDialog::Accepted) {
	
		RecordVideoRequestChangeWritingData request(dialog.currentColor());
		this->request(&request);
	}
}

void WritingPanel::widthButtonClicked() {

	QPoint point = ui.widthButton->geometry().topLeft();
	point.setX(point.x() - 10);
	point.setY(point.y() - this->widthPopupWidget->height());
	this->widthPopupWidget->setGeometry(this->mapToGlobal(point).x(), this->mapToGlobal(point).y(),
		this->widthPopupWidget->minimumWidth() + 10, this->widthPopupWidget->height());

	this->widthPopupWidget->show();
}

void WritingPanel::figureButtonClicked() {

	QPoint point = QPoint(0, -5);
	this->figurePopupWidget->setGeometry(this->mapToGlobal(point).x(), this->mapToGlobal(point).y(),
		this->figurePopupWidget->width(), this->figurePopupWidget->height());

	this->figurePopupWidget->show();
}

void WritingPanel::circleButtonClicked() {

	this->figurePopupWidget->hide();
	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Mode_Circle);
	this->request(&request);
}

void WritingPanel::rectangleButtonClicked() {

	this->figurePopupWidget->hide();
	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Mode_Rectangle);
	this->request(&request);
}

void WritingPanel::triangleButtonClicked() {

	this->figurePopupWidget->hide();
	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Mode_Triangle);
	this->request(&request);
}

void WritingPanel::currentWidthChanged(int width) {

	this->widthPopupWidget->hide();

	RecordVideoRequestChangeWritingData request(width);
	this->request(&request);
}


void WritingPanel::setColorButtonStyleSheets(const QColor &color) {
	

	QString rgba = "rgba(" + QString::number(color.red()) + "," +
		QString::number(color.green()) + "," +
		QString::number(color.blue()) + ",0.6)";
	

	ui.colorButton->setStyleSheet((QString("\n"
		"QPushButton {\n"
		"    background-color: %1;\n"
		"    border:0px;\n"
		"    border-radius:10px;\n"
		"    background-image:url(:/RecordVideo_Writing/color);\n"
		"}\n"
		"\n"
		"\n"
		"QPushButton:hover {\n"
		"    background-color:%2;\n"
		"}\n"
		"QPushButton:disabled {\n"
		"    background-color:white;\n"
		"    background-image:url(:/RecordVideo_Writing/color_disabled);\n"
		"}\n").arg(color.name()).arg(rgba)));

}