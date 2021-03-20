
#include "AbstractButton.h"
#include <qtooltip.h>
#include <qtimer.h>

AbstractButton::AbstractButton(QWidget *parent)
	:QPushButton(parent), aboutToShowTooltip(false) {

	this->setMouseTracking(true);
}

AbstractButton::~AbstractButton() {

}

void AbstractButton::enterEvent(QEvent *event) {

	if (this->isEnabled() == true) {
		this->aboutToShowTooltip = true;
		QTimer::singleShot(1000, this, &AbstractButton::showToolTip);
	}
}

void AbstractButton::leaveEvent(QEvent *event) {

	this->aboutToShowTooltip = false;
}

void AbstractButton::showToolTip() {

	if (this->aboutToShowTooltip == true) {
		if (this->tooltipText != "") {

			QToolTip::showText(QCursor::pos(), this->tooltipText);
		}
	}
}