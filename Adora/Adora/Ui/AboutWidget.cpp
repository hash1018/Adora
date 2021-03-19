

#include "AboutWidget.h"
#include "Base/AdoraInfo.h"
#include "Base/LanguageManager.h"

AboutWidget::AboutWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	
	//ui.githubLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
	


	ui.versionLabel->setText("ver. " + AdoraInfo::getInstance()->getVersion());


	ui.developerLabel->setText(getLanUiValue("MenuAbout/Developer"));
	ui.emailLabel->setText("E-mail");
	ui.githubLabel->setText("Github");

	QString str = "<b>" + AdoraInfo::getInstance()->getName() + "</b>";
	ui.developerLabel2->setTextFormat(Qt::RichText);
	ui.developerLabel2->setText(str);

	str = "<b>" + AdoraInfo::getInstance()->getEmail() + "</b>";
	ui.emailLabel2->setTextFormat(Qt::RichText);
	ui.emailLabel2->setText(str);

	ui.githubLabel2->setTextFormat(Qt::RichText);
	ui.githubLabel2->setText("<a href=\"http://www.github.com/hash1018\" style=\"color: black;\"><b>http://www.github.com/hash1018<b></a>");
	ui.githubLabel2->setOpenExternalLinks(true);
	
}

AboutWidget::~AboutWidget() {


}
