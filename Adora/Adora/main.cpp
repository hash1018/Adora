#include "Adora.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Adora w;
	w.show();
	return a.exec();
}
