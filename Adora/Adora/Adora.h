#ifndef ADORA_H
#define ADORA_H

#include <QtWidgets/QMainWindow>
#include "ui_Adora.h"

class Adora : public QMainWindow
{
	Q_OBJECT

public:
	Adora(QWidget *parent = 0);
	~Adora();

private:
	Ui::AdoraClass ui;
};

#endif // ADORA_H
