#include "CMainWindow.h"
#include <QApplication>
#include "CMPUData.h"
#include "CADCData.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<CMPUData>("CMPUData");
    qRegisterMetaType<CADCData>("CADCData");

    CMainWindow w;
    w.show();

    return a.exec();
}
