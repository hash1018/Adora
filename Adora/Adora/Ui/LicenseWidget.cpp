

#include "LicenseWidget.h"
#include <qfile.h>
#include <qtextstream.h>
#include "Base/LanguageManager.h"

LicenseWidget::LicenseWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	QFile file("license.txt");
	QString line;
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream stream(&file);
	
		line.append(stream.readAll());
	
		ui.licenseTextEdit->setText(line);

	}


	QString str = "<b>" + getLanUiValue("MenuLicense/License") + "</b>";
	ui.licenseLabel->setTextFormat(Qt::RichText);
	ui.licenseLabel->setText(str);
}

LicenseWidget::~LicenseWidget() {

}
