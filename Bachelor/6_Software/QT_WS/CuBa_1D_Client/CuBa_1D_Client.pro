#-------------------------------------------------
#
# Project created by QtCreator 2017-01-08T11:26:57
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CuBa_1D_Client
TEMPLATE = app


SOURCES += main.cpp\
        CMainWindow.cpp \
    Assertion.cpp \
    CClient.cpp \
    CMessage.cpp \
    qcustomplot.cpp \
    CSensorPlotGrid.cpp \
    CSensorCalibrationWidget.cpp \
    CRxThread.cpp \
    CADCCalibrationWidget.cpp \
    CControlWidget.cpp

HEADERS  += CMainWindow.h \
    Assertion.h \
    CClient.h \
    CPhi.h \
    CPhi__d.h \
    CPsi__d.h \
    CSensorData.h \
    EEvent.h \
    EFilter.h \
    Global.h \
    CMessage.h \
    qcustomplot.h \
    CSensorPlotGrid.h \
    CSensorCalibrationWidget.h \
    CRxThread.h \
    CADCCalibrationWidget.h \
    CControlWidget.h
