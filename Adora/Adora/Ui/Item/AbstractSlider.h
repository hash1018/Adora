#ifndef ABSTRACTSLIDER_H
#define ABSTRACTSLIDER_H

#include <qslider.h>
#include <qstring.h>

class AbstractSlider : public QSlider
{
	Q_OBJECT

public:
	enum SliderType {

		Horizontal,
		Vertical,
	};

public:
	AbstractSlider(QWidget *parent = nullptr, SliderType sliderType = Horizontal);
	~AbstractSlider();

private:
	SliderType sliderType;

private:
	bool sliderPressedFlag;
	
	QString handleImagePath;
	QSize handleSize;
	QString subPageColor;
	QString addPageColor;
	int grooveHeight;


	//border padding   = handleSize + paddingMargin;
	int paddingWidthMargin;
	int paddingHeightMargin;

private:
	void setSliderStyleSheet();

public:
	void setHandleImage(const QString &imagePath);
	void setSubPageColor(const QString &colorStr) { this->subPageColor = colorStr; }
	void setAddPageColor(const QString &colorStr) { this->addPageColor = colorStr; }
	void setGrooveHeight(const int &height) { this->grooveHeight = height; }
	void setSliderType(SliderType sliderType) { this->sliderType = sliderType; this->setSliderStyleSheet(); }
	void setPaddingWidthMargin(int width) { this->paddingWidthMargin = width; }
	void setPaddingHeightMargin(int height) { this->paddingHeightMargin = height; }


protected:
	bool eventFilter(QObject *object, QEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);
};

#endif // ABSTRACTSLIDER_H
