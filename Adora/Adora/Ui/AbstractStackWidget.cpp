

#include "AbstractStackWidget.h"

AbstractStackWidget::AbstractStackWidget(QWidget *parent)
	:QWidget(parent) {

}

AbstractStackWidget::~AbstractStackWidget() {

}

#include <qpainter.h>
void AbstractStackWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	
	painter.setRenderHint(QPainter::Antialiasing); // Anti-aliasing;
	painter.setBrush(QBrush(QColor("#FFFFFF")));
	painter.setPen(Qt::transparent);
	QRect rect = this->rect();
	rect.setWidth(rect.width());
	rect.setHeight(rect.height());
	painter.drawRoundedRect(rect, 14, 14);


	painter.fillRect(QRect(20, 0, this->width() - 20, 20), QColor("#FFFFFF"));
	painter.fillRect(QRect(0, this->height() - 20, 20, 20), QColor("#FFFFFF"));

	QWidget::paintEvent(event);
}