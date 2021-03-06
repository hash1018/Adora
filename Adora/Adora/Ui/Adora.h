
#ifndef ADORA_H
#define ADORA_H

#include <QtWidgets/QMainWindow>
#include "ui_Adora.h"

class Adora : public QMainWindow {
	Q_OBJECT

private:
	Ui::Adora ui;

public:
	Adora(QWidget *parent = nullptr);
	~Adora();

	private slots :
	void closeButtonClicked();
	void minimizeButtonClicked();
	
};

#endif // ADORA_H
