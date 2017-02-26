#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T11:45:32
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CuBa_3D_Client
TEMPLATE = app


SOURCES += main.cpp\
        CMainWindow.cpp \
    Assertion.cpp \
    CClient.cpp \
    CMessage.cpp \
    CRxThread.cpp \
    CMPUData.cpp \
    qcustomplot.cpp \
    CSensorCalibWidget.cpp \
    CTorqueData.cpp \
    CADCData.cpp \
    CADCWidget.cpp \
    CStateData.cpp \
    CControlWidget.cpp

HEADERS  += CMainWindow.h \
    Assertion.h \
    CClient.h \
    CMessage.h \
    CRxThread.h \
    EEvent.h \
    Global.h \
    CMPUData.h \
    CSensorCalibWidget.h \
    qcustomplot.h \
    CTorqueData.h \
    CADCData.h \
    CADCWidget.h \
    CStateData.h \
    CControlWidget.h
