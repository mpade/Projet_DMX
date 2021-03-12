#include "IHMDMX.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHMDMX w;
    w.show();
    return a.exec();
}
