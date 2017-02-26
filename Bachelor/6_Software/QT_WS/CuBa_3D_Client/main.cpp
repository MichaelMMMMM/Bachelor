#include "CMainWindow.h"
#include "CStateData.h"
#include <QApplication>

//Q_DECLARE_METATYPE(CMPUData)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<CMPUData>("CMPUData");
    qRegisterMetaType<CADCData>("CADCData");
    qRegisterMetaType<CTorqueData>("CTorqueData");
    qRegisterMetaType<CGData>("CGData");
    qRegisterMetaType<CUKData>("CUKData");
    qRegisterMetaType<CURData>("CURData");

    CMainWindow w;
    w.show();

    return a.exec();
}
