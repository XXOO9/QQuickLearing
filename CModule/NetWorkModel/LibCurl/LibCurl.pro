QT += quick core
CONFIG += c++11

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/bin/debug
        LIBS       += -L$$PWD/libcurl/ -llibcurld
}else
{
        DESTDIR     = $$PWD/bin/release
}


DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD/libcurl/

SOURCES += \
        CHttpGet.cpp \
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
    CHttpGet.h
