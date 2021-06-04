
#include "IHMDMX.h"
#include "IHMDMX2.h"
#include <QtWidgets/QApplication>
#include "main.h"
#include <QPushButton>
#include "Client.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
	QWidget *window = new QWidget;
    IHMDMX w;
    w.show();
	IHMDMX2 x;
	x.show();
    return app.exec();

}
