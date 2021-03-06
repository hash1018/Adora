

#include "LanguageSettingWidget.h"

LanguageSettingWidget::LanguageSettingWidget(QWidget *parent)
	:QWidget(parent) {

}

LanguageSettingWidget::~LanguageSettingWidget() {


}

#include <qpainter.h>
void LanguageSettingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(55, 55, 23));
}

