

#include "LanguageSettingWidget.h"
#include "Base/SettingManager.h"

LanguageSettingWidget::LanguageSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	ui.languageComboBox->addItem("English");
	ui.languageComboBox->addItem("Korean");
	ui.languageComboBox->setCurrentIndex(SettingManager::getInstance()->getLanguageSetting()->getLanguage());


	connect(ui.changeButton, &QPushButton::clicked, this, &LanguageSettingWidget::changeButtonClicked);
}

LanguageSettingWidget::~LanguageSettingWidget() {


}

#include <qpainter.h>
void LanguageSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(55, 55, 23));
}


void LanguageSettingWidget::changeButtonClicked() {

	if (ui.languageComboBox->currentIndex() == SettingManager::getInstance()->getLanguageSetting()->getLanguage())
		return;

	SettingManager::getInstance()->getLanguageSetting()->setLanguage(LanguageSetting::Language(ui.languageComboBox->currentIndex()));
	emit this->requestChangeLanguage();
}