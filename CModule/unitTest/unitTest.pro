#-------------------------------------------------
#
# Project created by QtCreator 2021-12-21T16:18:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = unitTest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


INCLUDEPATH += $$PWD/../CHttpModule
INCLUDEPATH += $$PWD/../CHttpModule2


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/MOC
        RCC_DIR     = $$PWD/debug/RCC
        OBJECTS_DIR = $$PWD/debug/OBJ
        LIBS       += -L$$PWD/../CHttpModule/debug -lCHttpModule
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
