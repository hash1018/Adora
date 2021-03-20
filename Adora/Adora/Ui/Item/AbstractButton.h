

#ifndef _ABSTRACTBUTTON_H
#define _ABSTRACTBUTTON_H

#include <qpushbutton.h>
#include <qstring.h>

class AbstractButton : public QPushButton {

	Q_OBJECT 

protected:
	QString tooltipText;
	bool aboutToShowTooltip;

public:
	AbstractButton(QWidget *parent = nullptr);
	~AbstractButton();

	virtual void setToolTip(const QString &toolTipText) { this->tooltipText = toolTipText; }

protected:
	virtual void enterEvent(QEvent *event);
	virtual void leaveEvent(QEvent *event);

	private slots:
	void showToolTip();
};

#endif //_ABSTRACTBUTTON_H
