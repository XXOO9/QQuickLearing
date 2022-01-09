TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CClassTest.cpp \
        NoClassTest.cpp \
        main.cpp

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

HEADERS += \
    CClassTest.h \
    NoClassTest.h
