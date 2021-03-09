

#ifndef _IMAGESETTINGWIDGET_H
#define _IMAGESETTINGWIDGET_H

#include <qwidget.h>
#include "ui_ImageSettingWidget.h"

class ImageSettingWidget : public QWidget {

private:
	Ui::ImageSettingWidget ui;

public:
	ImageSettingWidget(QWidget *parent = nullptr);
	~ImageSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void includeCursorCheckBoxToggled(bool checked);
	void useImageCaptureHotkeyCheckBoxToggled(bool checked);

};

#endif //_IMAGESETTINGWIDGET_H