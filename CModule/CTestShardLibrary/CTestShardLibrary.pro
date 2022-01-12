#-------------------------------------------------
#
# Project created by QtCreator 2022-01-10T14:35:45
#
#-------------------------------------------------

QT       -= gui

TARGET = CTestShardLibrary
TEMPLATE = lib

DEFINES += CTESTSHARDLIBRARY_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/../GoogleTest/QtClass/debug
        MOC_DIR     = $$PWD/debug/tmp
        RCC_DIR     = $$PWD/debug/tmp
        OBJECTS_DIR = $$PWD/debug/tmp
}else
{
        DESTDIR     = $$PWD/../GoogleTest/QtClass/release
        MOC_DIR     = $$PWD/release/tmp
        RCC_DIR     = $$PWD/release/tmp
        OBJECTS_DIR = $$PWD/release/tmp
}

include($$PWD/subLibrary.pri)

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \

HEADERS += \
        ctestshardlibrary_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
