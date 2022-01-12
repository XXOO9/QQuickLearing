QT -= gui
QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD/../../CTestShardLibrary


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/tmp
        RCC_DIR     = $$PWD/debug/tmp
        OBJECTS_DIR = $$PWD/debug/tmp
#        LIBS       += -L$$PWD/thirdParty -lCHttpModule
        LIBS       += -L$$PWD/debug -lCTestShardLibrary
}else
{
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/tmp
        RCC_DIR     = $$PWD/release/tmp
        OBJECTS_DIR = $$PWD/release/tmp
}

SOURCES += \
#        ../../CHttpModule/CHttpModule.cpp \
        QtClassTest.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
#    ../../CHttpModule/CHttpModule.h \
    QtClassTest.h
