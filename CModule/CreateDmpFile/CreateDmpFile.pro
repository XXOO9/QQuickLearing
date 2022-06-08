QT += quick core widgets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#创建dmp文件需要的库
LIBS += -lDbgHelp

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

SOURCES += \
        CTestClass.cpp \
        CTestMgr.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CTestClass.h \
    CTestMgr.h
