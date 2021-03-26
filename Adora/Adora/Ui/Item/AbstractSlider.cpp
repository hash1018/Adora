#include "AbstractSlider.h"

#include <qimagereader.h>

AbstractSlider::AbstractSlider(QWidget *parent, AbstractSlider::SliderType sliderType)
	: QSlider(parent), sliderPressedFlag(false), handleImagePath("")
	, subPageColor("#000000"), addPageColor("#FFFFFF"), grooveHeight(4), sliderType(sliderType) {

	this->installEventFilter(this);
	this->setMouseTracking(true);


	this->paddingHeightMargin = 0;
	this->paddingWidthMargin = 0;

	connect(this, &QSlider::sliderPressed, this, [&]() { this->sliderPressedFlag = true; });
	connect(this, &QSlider::sliderReleased, this, [&]() { this->sliderPressedFlag = false; });

}

AbstractSlider::~AbstractSlider() {

}

void AbstractSlider::setSliderStyleSheet() {
	

	if (this->sliderType == SliderType::Horizontal) {
		/*
			%1 : padding Px	(= handle width, image width)
			%2 : groove Height
			%3 : handle image url
			%4 : handle horizontal margin px (= handle width/2 + 3)(+ 값은 미세조정값)
			%5 : subPage color
			%6 : addPage color
		*/

		int padding = this->handleSize.width() + this->paddingWidthMargin;

		this->setStyleSheet(QString("QSlider {	border: 1px solid transparent;\
											padding: 0px %7px;\
											}\
\
								QSlider::groove:horizontal {\
											border: 0px;\
											height: %2px;\
								}\
\
								QSlider::handle:horizontal{\
											width: %1px;\
											background-color: transparent;\
											image: url(%3);\
											margin: -10px -%4px;\
								}\
\
								QSlider::handle:hover:horizontal{\
\
								}\
\
								QSlider::sub-page:horizontal{\
											background-color: %5;\
								}\
\
								QSlider::add-page:horizontal{\
											background-color: %6;\
								}\
						").arg(this->handleSize.width())
			.arg(this->grooveHeight)
			.arg(this->handleImagePath)
			.arg((this->handleSize.width() / 2))
			.arg(this->subPageColor)
			.arg(this->addPageColor)
			.arg(padding));

	}
	else {
	
	
		/*
		%1 : padding Px	(= handle width, image width)
		%2 : groove Height
		%3 : handle image url
		%4 : handle horizontal margin px (= handle width/2 + 3)(+ 값은 미세조정값)
		%5 : subPage color
		%6 : addPage color
		*/

		int padding = this->handleSize.height() + this->paddingHeightMargin;

		this->setStyleSheet(QString("QSlider {	border: 1px solid transparent;\
											padding: %7px 0px;\
											}\
\
								QSlider::groove:vertical {\
											border: 0px;\
											width: %2px;\
								}\
\
								QSlider::handle:vertical{\
											height: %1px;\
											background-color: transparent;\
											image: url(%3);\
											margin: -%4px -10px;\
								}\
\
								QSlider::handle:hover:vertical{\
\
								}\
\
								QSlider::sub-page:vertical{\
											background-color: %5;\
								}\
\
								QSlider::add-page:vertical{\
											background-color: %6;\
								}\
						").arg(this->handleSize.height())
			.arg(this->grooveHeight)
			.arg(this->handleImagePath)
			.arg((this->handleSize.height() / 2))
			.arg(this->addPageColor)
			.arg(this->subPageColor)
			.arg(padding));

	}

}


// Slider의 Handle 이미지를 설정한다.
void AbstractSlider::setHandleImage(const QString &imagePath) {
	
	this->handleImagePath = imagePath;
	
	QImageReader reader(this->handleImagePath);
	this->handleSize = reader.size();

	setSliderStyleSheet();
}

// EventFilter
#include <qevent.h>
#include <qdebug.h>
bool AbstractSlider::eventFilter(QObject *object, QEvent *event) {


	if (this->sliderType == SliderType::Horizontal) {


		// Slider 조작
		if (event->type() == QEvent::MouseButtonPress) {

			if (this->sliderPressedFlag == false) {

				auto mouseEvent = static_cast<QMouseEvent*>(event);
				if (mouseEvent->button() == Qt::LeftButton) {

					qreal leftPadding = 20;
					qreal rightPadding = 20;

					qreal mouseLocalPosX = mouseEvent->localPos().x() - leftPadding;
					qreal positionSliderGrooveWidth = this->width() - (leftPadding + rightPadding);

					if (mouseLocalPosX < 0) mouseLocalPosX = 0;
					if (mouseLocalPosX > positionSliderGrooveWidth) mouseLocalPosX = positionSliderGrooveWidth;

					qreal value = this->minimum() + (this->maximum() - this->minimum()) * mouseLocalPosX / positionSliderGrooveWidth;

					this->setValue(qRound(value));
					emit this->sliderMoved(qRound(value));	// 클릭한 곳으로 move시키는 signal 발생시킨다.
				}
			}
		}

	}
	else {
	
		// Slider 조작
		if (event->type() == QEvent::MouseButtonPress) {

			if (this->sliderPressedFlag == false) {

				auto mouseEvent = static_cast<QMouseEvent*>(event);
				if (mouseEvent->button() == Qt::LeftButton) {

					qreal bottomPadding = 20;
					qreal topPadding = 20;

					qreal mouseLocalPosY = mouseEvent->localPos().y() - bottomPadding;
					qreal positionSliderGrooveHeight = this->height() - (bottomPadding + topPadding);

					// 양 끝 처리
					if (mouseLocalPosY < 0) mouseLocalPosY = 0;
					if (mouseLocalPosY > positionSliderGrooveHeight) mouseLocalPosY = positionSliderGrooveHeight;

					qreal value = this->maximum() + (this->minimum() - this->maximum()) * mouseLocalPosY / positionSliderGrooveHeight;

					this->setValue(qRound(value));
					qDebug() << "value" << this->value();
					emit this->sliderMoved(qRound(value));	// 클릭한 곳으로 move시키는 signal 발생시킨다.
				}
			}
		}
	}

	return QWidget::eventFilter(object, event);
}

void AbstractSlider::keyPressEvent(QKeyEvent *event) {
	
	event->ignore();
}