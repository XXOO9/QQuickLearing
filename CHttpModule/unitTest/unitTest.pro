#-------------------------------------------------
#
# Project created by QtCreator 2021-12-21T16:18:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = unitTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#include($$PWD/../CHttpModule/CHttpConfigReader/CHttpConfigReader.pri)
INCLUDEPATH += $$PWD/../CHttpModule
INCLUDEPATH += $$PWD/../CHttpModule2


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/MOC
        RCC_DIR     = $$PWD/debug/RCC
        OBJECTS_DIR = $$PWD/debug/OBJ
        LIBS       += -L$$PWD/../CHttpModule/debug -lCHttpModule
        LIBS       += -L$$PWD/../CHttpModule2/debug -lCHttpModule2
}else
{
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/MOC
        RCC_DIR     = $$PWD/release/RCC
        OBJECTS_DIR = $$PWD/release/OBJ
}

INCLUDEPATH += $$PWD/../CHttpModule
INCLUDEPATH += $$PWD/../CHttpModule

CONFIG += c++11

SOURCES += \
        main.cpp \
        CMainWidget.cpp

HEADERS += \
        CMainWidget.h

FORMS += \
        CMainWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
