#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T12:41:22
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CuBa_Client
TEMPLATE = app


SOURCES += main.cpp \
    CMainWindow.cpp \
    CExperimentWidget.cpp \
    CSensorCalibration.cpp \
    QCustomPlot.cpp \
    CPlot.cpp \
    CADCCalibration.cpp

HEADERS  += \
    CMainWindow.h \
    CExperimentWidget.h \
    CSensorCalibration.h \
    QCustomPlot.h \
    CPlot.h \
    CADCCalibration.h
