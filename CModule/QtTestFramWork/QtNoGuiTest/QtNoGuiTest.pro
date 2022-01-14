QT += testlib core
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

TEMPLATE = app

SOURCES +=  tst_demotest.cpp \
    CustTestClass.cpp

HEADERS += \
    CustTestClass.h
