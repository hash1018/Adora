#include "Ui/Adora.h"
#include <QtWidgets/QApplication>
#include <qsharedmemory.h>

void adora(QApplication &app) {

	Adora w;
	w.show();

	app.exec();


	if (w.restart == true)
		adora(app);

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSharedMemory shared("Adora");

	if (shared.create(512, QSharedMemory::ReadWrite) == false) {

		exit(0);
	}
	
	adora(a);

	return 0;
}
