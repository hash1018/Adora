

#ifndef _WRITINGSETTINGWIDGET_H
#define _WRITINGSETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_WritingSettingWidget.h"

class WritingSettingWidget : public AbstractStackWidget {

private:
	Ui::WritingSettingWidget ui;

public:
	WritingSettingWidget(QWidget *parent = nullptr);
	~WritingSettingWidget();

	private slots:
	void cursorHotkeyCheckBoxToggled(bool checked);
	void cursorHotkeyEmitted(const QKeySequence &keySequence);

	void pencilHotkeyCheckBoxToggled(bool checked);
	void pencilHotkeyEmitted(const QKeySequence &keySequence);

	void highlightHotkeyCheckBoxToggled(bool checked);
	void highlightHotkeyEmitted(const QKeySequence &keySequence);

	void lineHotkeyCheckBoxToggled(bool checked);
	void lineHotkeyEmitted(const QKeySequence &keySequence);

	void arrowLineHotkeyCheckBoxToggled(bool checked);
	void arrowLineHotkeyEmitted(const QKeySequence &keySequence);

	void numberingHotkeyCheckBoxToggled(bool checked);
	void numberingHotkeyEmitted(const QKeySequence &keySequence);

	void eraserHotkeyCheckBoxToggled(bool checked);
	void eraserHotkeyEmitted(const QKeySequence &keySequence);
};


#endif //_WRITINGSETTINGWIDGET_H