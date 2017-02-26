#include "CMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<CSensorData>("CSensorData");
    qRegisterMetaType<CPhi>("CPhi");
    qRegisterMetaType<CPhi__d>("CPhi__d");
    qRegisterMetaType<CPsi__d>("CPsi__d");

    CMainWindow w;
    w.show();


    return a.exec();
}
