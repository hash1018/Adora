
#ifndef ADORA_H
#define ADORA_H

#include <QtWidgets/QMainWindow>
#include "ui_Adora.h"

class Adora : public QMainWindow {
	Q_OBJECT

private:
	Ui::Adora ui;

private:
	bool mousePressed;
	QPoint prev;

public:
	Adora(QWidget *parent = nullptr);
	~Adora();

protected:
	virtual void closeEvent(QCloseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	

	private slots :
	void closeButtonClicked();
	void minimizeButtonClicked();


private:
	void initPosition();
	
};

#endif // ADORA_H
