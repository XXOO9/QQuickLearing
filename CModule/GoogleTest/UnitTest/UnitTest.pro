QT += core

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG += thread
CONFIG += qt

CONFIG( debug, debug | release ){
        DESTDIR  = $$PWD/debug
}else
{
        DESTDIR  = $$PWD/release
}

INCLUDEPATH += ../QtClass\


HEADERS += \
        ../QtClass/QtClassTest.h \
        tst_testcase.h

SOURCES += \
        ../QtClass/QtClassTest.cpp \
        main.cpp    \
        DemoTest.cpp


