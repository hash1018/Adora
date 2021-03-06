

#include "WatermarkSettingWidget.h"

WatermarkSettingWidget::WatermarkSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

WatermarkSettingWidget::~WatermarkSettingWidget() {

}

#include <qpainter.h>
void WatermarkSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(100, 100, 100));
}