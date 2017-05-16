#include "CMainWindow.h"
#include <QApplication>
#include "CMPUData.h"
#include "CADCData.h"
#include "TMatrix.h"
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<CMPUData>("CMPUData");
    qRegisterMetaType<CADCData>("CADCData");
    qRegisterMetaType<QVector<double> >("Qvector<double>");

    CMainWindow w;
    w.show();

    return a.exec();
}
