
#include "GeneralSettingWidget.h"

GeneralSettingWidget::GeneralSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

GeneralSettingWidget::~GeneralSettingWidget() {

}

#include <qpainter.h>
void GeneralSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(12, 12, 12));
}