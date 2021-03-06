
#include "Ui/Adora.h"
#include <QtWidgets/QApplication>
#include <qsharedmemory.h>
#include <qfile.h>
#include "Base/Hotkey.h"
//#include <vld.h>

void adora(QApplication &app) {

	Adora w;
	w.show();

	app.exec();


	if (w.restart == true) {
		HotkeyList::getInstance()->deleteAll();
		adora(app);
	}

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSharedMemory shared("Adora");

	if (shared.create(512, QSharedMemory::ReadWrite) == false) {

		exit(0);
	}

	QFile mainQss(":/Qss/main");
	mainQss.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(mainQss.readAll());
	a.setStyleSheet(styleSheet);

	QString family = "Malgun Gothic";
	QFont font;
	font.setFamily(family);
	//font.setPointSize(9);
	//font.setPixelSize(14);
	
	a.setFont(font);
	
	
	a.setWindowIcon(QIcon(":/Main/logo"));
	
	adora(a);

	return 0;
}
