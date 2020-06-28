#include "RongMapMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RongMapMainWindow w;
	w.show();
	return a.exec();
}
