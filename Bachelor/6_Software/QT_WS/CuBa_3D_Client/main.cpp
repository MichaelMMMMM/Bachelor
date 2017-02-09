#include "CMainWindow.h"
#include <QApplication>

//Q_DECLARE_METATYPE(CMPUData)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<CMPUData>("CMPUData");
    qRegisterMetaType<CADCData>("CADCData");
    qRegisterMetaType<CTorqueData>("CTorqueData");

    CMainWindow w;
    w.show();

    return a.exec();
}
