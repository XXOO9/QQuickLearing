QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_auto_test.cpp \
    Car.cpp \
    SignalTest.cpp \
    TestA.cpp \
    TestB.cpp \
    main.cpp

HEADERS += \
    Car.h \
    SignalTest.h \
    TestA.h \
    TestB.h
