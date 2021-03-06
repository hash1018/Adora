

#include "TimeLimitSettingWidget.h"

TimeLimitSettingWidget::TimeLimitSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

TimeLimitSettingWidget::~TimeLimitSettingWidget() {

}

#include <qpainter.h>
void TimeLimitSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(77, 77, 77));
}

