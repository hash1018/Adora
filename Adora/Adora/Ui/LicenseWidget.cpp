

#include "LicenseWidget.h"

LicenseWidget::LicenseWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);
}

LicenseWidget::~LicenseWidget() {

}

#include <qpainter.h>
void LicenseWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(88, 99, 99));
}