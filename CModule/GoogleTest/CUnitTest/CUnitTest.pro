include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

HEADERS += \
        ../PlainCppTestDemo/NoClassTest.h \
        ../QtClass/QtClassTest.h \
        tst_casename.h

SOURCES += \
        ../PlainCppTestDemo/NoClassTest.cpp \
        ../QtClass/QtClassTest.cpp \
        DemoTest.cpp \
        main.cpp
