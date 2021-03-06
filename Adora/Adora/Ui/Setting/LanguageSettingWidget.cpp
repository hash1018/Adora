

#include "LanguageSettingWidget.h"

LanguageSettingWidget::LanguageSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	ui.languageComboBox->addItem("English");
	ui.languageComboBox->addItem("Korean");


	connect(ui.changeButton, &QPushButton::clicked, this, &LanguageSettingWidget::changeButtonClicked);
}

LanguageSettingWidget::~LanguageSettingWidget() {


}

#include <qpainter.h>
void LanguageSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(55, 55, 23));
}

#include "Base/SettingManager.h"
void LanguageSettingWidget::changeButtonClicked() {

	SettingManager::getInstance()->getLanguageSetting()->setLanguage(LanguageSetting::Language(ui.languageComboBox->currentIndex()));
	emit this->requestChangeLanguage();
}