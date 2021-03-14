

#include "LicenseWidget.h"
#include <qfile.h>
#include <qtextstream.h>
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
}

LicenseWidget::~LicenseWidget() {

}
