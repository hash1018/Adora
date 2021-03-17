

#include "LanguageSettingWidget.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"

LanguageSettingWidget::LanguageSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	ui.languageComboBox->addItem("English");
	ui.languageComboBox->addItem("Korean");
	ui.languageComboBox->setCurrentIndex(SettingManager::getInstance()->getLanguageSetting()->getLanguage());

	QString str = "<b>" + getLanUiValue("MenuLanguage/Language") + "</b>";
	ui.languageLabel->setTextFormat(Qt::RichText);
	ui.languageLabel->setText(str);

	connect(ui.changeButton, &QPushButton::clicked, this, &LanguageSettingWidget::changeButtonClicked);
}

LanguageSettingWidget::~LanguageSettingWidget() {


}

void LanguageSettingWidget::changeButtonClicked() {

	if (ui.languageComboBox->currentIndex() == SettingManager::getInstance()->getLanguageSetting()->getLanguage())
		return;

	SettingManager::getInstance()->getLanguageSetting()->setLanguage(LanguageSetting::Language(ui.languageComboBox->currentIndex()));
	emit this->requestChangeLanguage();
}