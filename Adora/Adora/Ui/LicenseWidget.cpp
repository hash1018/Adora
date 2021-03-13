

#include "LicenseWidget.h"
#include <qfile.h>
#include <qtextstream.h>
LicenseWidget::LicenseWidget(QWidget *parent)
	:QWidget(parent) {

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

#include <qpainter.h>
void LicenseWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(88, 99, 99));
}