

#include "AboutWidget.h"

AboutWidget::AboutWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	
	//ui.githubLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
	ui.githubLabel->setTextFormat(Qt::RichText);

	ui.githubLabel->setText("<a href=\"http://www.github.com/hash1018\" style=\"color: blue;\">http://www.github.com/hash1018</a>");
	ui.githubLabel->setOpenExternalLinks(true);
	
}

AboutWidget::~AboutWidget() {


}
