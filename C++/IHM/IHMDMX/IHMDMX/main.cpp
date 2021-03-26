#include "IHMDMX.h"
#include "IHMDMX2.h"
#include <QtWidgets/QApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHMDMX w;
	IHMDMX2 x;
    w.show();
	x.show();
    return a.exec();


}
