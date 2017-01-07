#-------------------------------------------------
#
# Project created by QtCreator 2017-01-05T14:26:54
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Client_1D
TEMPLATE = app


SOURCES += main.cpp\
        CMainWindow.cpp \
    CClient.cpp \
    CSensorPlotGrid.cpp \
    qcustomplot.cpp \
    Assertion.cpp \
    CBinarySemaphore.cpp \
    CMessage.cpp \
    CMutex.cpp \
    CCommComp.cpp \
    CCountingSemaphore.cpp \
    AComponentBase.cpp \
    CRxTask.cpp

HEADERS  += CMainWindow.h \
    CClient.h \
    CSensorData.h \
    CSensorPlotGrid.h \
    Global.h \
    qcustomplot.h \
    Assertion.h \
    CBinarySemaphore.h \
    CMessage.h \
    CMutex.h \
    CPhi.h \
    CPhi__d.h \
    CPsi__d.h \
    EEvent.h \
    EFilter.h \
    FWMemory.h \
    CRxTask.h \
    IRunnable.h \
    TQueue.h \
    CCountingSemaphore.h \
    CProxy.h \
    CMainTask.h

FORMS    += cmainwindow.ui

OTHER_FILES += \
    Client_1D.pro.user
