

#include "AboutWidget.h"

AboutWidget::AboutWidget(QWidget *parent)
	:QWidget(parent) {

}

AboutWidget::~AboutWidget() {


}

#include <qpainter.h>
void AboutWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(222, 112, 211));
}