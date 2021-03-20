

#include "ResizeRecordRectDelegate.h"
#include <QMouseEvent>
#include <qpainter.h>
#include "Ui/Record/RecordVideoDialog.h"
#include <qtimer.h>
#include <qguiapplication.h>
#include <qscreen.h>

ResizeRecordRectDelegate::ResizeRecordRectDelegate(RecordVideoDialog *recordVideoDialog)
	:recordVideoDialog(recordVideoDialog), mousePressed(false), timer(nullptr), showReiszedRect(false) {

}

ResizeRecordRectDelegate::~ResizeRecordRectDelegate() {

	
}


void ResizeRecordRectDelegate::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->prev = event->globalPos();
}

void ResizeRecordRectDelegate::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		bool succeeded = false;

		QPoint current = event->globalPos();

		if (this->timer == nullptr) {

			this->timer = new QTimer(this);
			connect(this->timer, &QTimer::timeout, this, &ResizeRecordRectDelegate::timePassed);
		}

		if (this->resizeBehavior != ResizeBehavior::Move) {

			this->showReiszedRect = true;
			this->timer->stop();
			this->timer->setInterval(3000);
			this->timer->start();
		}
		else {

			this->showReiszedRect = false;
			this->timer->stop();
		}

		succeeded = this->resize(this->prev, current);

		if (succeeded == true) {

			this->prev = current;
		}
		else {

			QCursor::setPos(this->prev);
		}

	}
	else {
		this->getResizeBehavior(this->recordVideoDialog->getRecordBorderRect(), event);
	}
}

void ResizeRecordRectDelegate::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->recordVideoDialog->setCursor(Qt::CursorShape::ArrowCursor);
}

void ResizeRecordRectDelegate::paintEvent(QPainter &painter) {

	if (this->showReiszedRect == true) {

		QFont font = painter.font();
		font.setPointSize(font.pointSize() * 2);
		painter.setFont(font);
		painter.setPen(QColor("#FFB513"));

		QRect rect = this->recordVideoDialog->getRecordBorderRect();

		painter.drawText(rect.topLeft().x() + 10, rect.y() + 10, 200, 40, Qt::AlignLeft, QString::number(rect.width()) + "x" +
			QString::number(rect.height()));
	}
}

void ResizeRecordRectDelegate::timePassed() {

	this->showReiszedRect = false;
	this->timer->stop();
	this->recordVideoDialog->update();
}

bool ResizeRecordRectDelegate::resize(const QPoint &prev, const QPoint &current) {


	bool succeeded = false;

	QPoint delta = current - prev;
	QSize minumumSize = this->recordVideoDialog->minimumSize();
	QRect recordRect = this->recordVideoDialog->getRecordBorderRect();
	recordRect = QRect(this->recordVideoDialog->mapToGlobal(QPoint(recordRect.x(), recordRect.y())), QSize(recordRect.width(), recordRect.height()));

	if (resizeBehavior == ResizeBehavior::Move) {

		QRect rect(recordRect.x() + delta.x(), recordRect.y() + delta.y(), recordRect.width(), recordRect.height());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x() + delta.x(), this->recordVideoDialog->y() + delta.y(),
				this->recordVideoDialog->width(), this->recordVideoDialog->height());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottomRight) {

		QRect rect(recordRect.x(), recordRect.y(), recordRect.width() + delta.x(), recordRect.height() + delta.y());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x(), this->recordVideoDialog->y(),
				this->recordVideoDialog->width() + delta.x(), this->recordVideoDialog->height() + delta.y());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTopRight) {

		if (this->recordVideoDialog->width() + delta.x() <= minumumSize.width())
			return false;

		if (this->recordVideoDialog->height() - delta.y() <= minumumSize.height())
			return false;

		QRect rect(recordRect.x(), recordRect.y() + delta.y(),
			recordRect.width() + delta.x(), recordRect.height() - delta.y());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {
			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x(), this->recordVideoDialog->y() + delta.y(),
				this->recordVideoDialog->width() + delta.x(), this->recordVideoDialog->height() - delta.y());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTopLeft) {

		if (this->recordVideoDialog->width() - delta.x() <= minumumSize.width())
			return false;

		if (this->recordVideoDialog->height() - delta.y() <= minumumSize.height())
			return false;

		QRect rect(recordRect.x() + delta.x(), recordRect.y() + delta.y(),
			recordRect.width() - delta.x(), recordRect.height() - delta.y());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x() + delta.x(), this->recordVideoDialog->y() + delta.y(),
				this->recordVideoDialog->width() - delta.x(), this->recordVideoDialog->height() - delta.y());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottomLeft) {

		if (this->recordVideoDialog->width() - delta.x() <= minumumSize.width())
			return false;

		if (this->recordVideoDialog->height() + delta.y() <= minumumSize.height())
			return false;

		QRect rect(recordRect.x() + delta.x(), recordRect.y(),
			recordRect.width() - delta.x(), recordRect.height() + delta.y());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x() + delta.x(), this->recordVideoDialog->y(),
				this->recordVideoDialog->width() - delta.x(), this->recordVideoDialog->height() + delta.y());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeTop) {

		if (this->recordVideoDialog->height() - delta.y() <= minumumSize.height())
			return false;

		QRect rect(recordRect.x(), recordRect.y() + delta.y(),
			recordRect.width(), recordRect.height() - delta.y());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x(), this->recordVideoDialog->y() + delta.y(),
				this->recordVideoDialog->width(), this->recordVideoDialog->height() - delta.y());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeBottom) {

		if (this->recordVideoDialog->height() + delta.y() <= minumumSize.height())
			return false;

		QRect rect(recordRect.x(), recordRect.y(),
			recordRect.width(), recordRect.height() + delta.y());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x(), this->recordVideoDialog->y(),
				this->recordVideoDialog->width(), this->recordVideoDialog->height() + delta.y());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeLeft) {

		if (this->recordVideoDialog->width() - delta.x() <= minumumSize.width())
			return false;

		QRect rect(recordRect.x() + delta.x(), recordRect.y(),
			recordRect.width() - delta.x(), recordRect.height());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x() + delta.x(), this->recordVideoDialog->y(),
				this->recordVideoDialog->width() - delta.x(), this->recordVideoDialog->height());
		}
	}
	else if (resizeBehavior == ResizeBehavior::ResizeRight) {

		if (this->recordVideoDialog->width() + delta.x() <= minumumSize.width())
			return false;

		QRect rect(recordRect.x(), recordRect.y(),
			recordRect.width() + delta.x(), recordRect.height());

		succeeded = this->containsInScreen(rect);

		if (succeeded == true) {

			this->recordVideoDialog->setGeometry(this->recordVideoDialog->x(), this->recordVideoDialog->y(),
				this->recordVideoDialog->width() + delta.x(), this->recordVideoDialog->height());
		}
	}


	return succeeded;
}

void ResizeRecordRectDelegate::getResizeBehavior(const QRect &rect, QMouseEvent *event) {

	int x = event->x();
	int y = event->y();



	if (x >= rect.topLeft().x() + 10 && x <= rect.topRight().x() - 10 &&
		y >= rect.topLeft().y() - 5 && y <= rect.topLeft().y() + 10) {

		
		this->resizeBehavior = ResizeBehavior::ResizeTop;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeVerCursor));
	}
	else if (x >= rect.topLeft().x() - 5 && x < rect.topLeft().x() + 5 &&
		y >= rect.topLeft().y() + 10 && y <= rect.bottomLeft().y() - 10) {
		
		this->resizeBehavior = ResizeBehavior::ResizeLeft;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeHorCursor));
	}
	else if (x >= rect.topRight().x() - 5 && x <= rect.topRight().x() + 5 &&
		y >= rect.topLeft().y() + 10 && y <= rect.bottomLeft().y() - 10) {
		
		this->resizeBehavior = ResizeBehavior::ResizeRight;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeHorCursor));
	}
	else if (x >= rect.topLeft().x() - 5 && x <= rect.topLeft().x() + 10 &&
		y >= rect.topLeft().y() - 5 && y <= rect.topLeft().y() + 10) {
		
		this->resizeBehavior = ResizeBehavior::ResizeTopLeft;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeFDiagCursor));
	}
	else if (x >= rect.topRight().x() - 10 && x <= rect.topRight().x() + 10 &&
		y >= rect.topRight().y() - 5 && y <= rect.topRight().y() + 10) {
		
		this->resizeBehavior = ResizeBehavior::ResizeTopRight;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
	}
	else if (x >= rect.bottomLeft().x() + 10 && x <= rect.bottomRight().x() - 10 &&
		y >= rect.bottomLeft().y() - 5 && y <= rect.bottomLeft().y() + 10) {
		
		this->resizeBehavior = ResizeBehavior::ResizeBottom;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeVerCursor));
	}
	else if (x >= rect.bottomLeft().x() - 5 && x <= rect.bottomLeft().x() + 10 &&
		y >= rect.bottomLeft().y() - 10 && y <= rect.bottomLeft().y() + 10) {
		
		this->resizeBehavior = ResizeBehavior::ResizeBottomLeft;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
	}
	else if (x >= rect.bottomRight().x() - 10 && x <= rect.bottomRight().x() + 10 &&
		y >= rect.bottomRight().y() - 10 && y <= rect.bottomRight().y() + 10) {

		this->resizeBehavior = ResizeBehavior::ResizeBottomRight;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::SizeFDiagCursor));
	}
	else {

		this->resizeBehavior = ResizeBehavior::Move;
		this->recordVideoDialog->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
	}
}

bool ResizeRecordRectDelegate::containsInScreen(const QRect &rect) {

	QList<QScreen*> screens = QGuiApplication::screens();

	QRect rect2;

	for (int i = 0; i < screens.size(); i++) {

		rect2 = rect2.united(screens.at(i)->geometry());
	}

	return rect2.contains(rect);
}