

#include "FigurePopupWidget.h"
#include <qpainter.h>

FigurePopupWidget::FigurePopupWidget()
	:QWidget(nullptr,Qt::Popup) {


	ui.setupUi(this);

	//this->setAttribute(Qt::WA_TranslucentBackground);
}

FigurePopupWidget::~FigurePopupWidget() {

}


void FigurePopupWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing); // Anti-aliasing;
	painter.setBrush(QBrush(QColor("#FFFFFF")));
	painter.setPen(Qt::transparent);
	QRect rect = this->rect();
	rect.setWidth(rect.width());
	rect.setHeight(rect.height());
	painter.drawRoundedRect(rect, 10, 10);
}