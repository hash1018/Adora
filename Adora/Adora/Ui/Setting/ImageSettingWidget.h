

#ifndef _IMAGESETTINGWIDGET_H
#define _IMAGESETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_ImageSettingWidget.h"

class ImageSettingWidget : public AbstractStackWidget {

private:
	Ui::ImageSettingWidget ui;

public:
	ImageSettingWidget(QWidget *parent = nullptr);
	~ImageSettingWidget();

protected:

	private slots:
	void includeCursorCheckBoxToggled(bool checked);
	void useImageCaptureHotkeyCheckBoxToggled(bool checked);

};

#endif //_IMAGESETTINGWIDGET_H