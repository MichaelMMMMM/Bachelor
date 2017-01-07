#include <QApplication>
#include "CMainWindow.h"
#include "CMessage.h"
#include <iostream>
#include <QThread>
#include "CMainTask.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CMainTask mainThread;
    CMainWindow mainWindow;
    mainWindow.show();
    mainWindow.moveToThread(&mainThread);
    mainThread.start();
    return app.exec();
}
