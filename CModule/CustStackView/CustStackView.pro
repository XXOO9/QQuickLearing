QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/tmp
        RCC_DIR     = $$PWD/debug/tmp
        OBJECTS_DIR = $$PWD/debug/tmp
}else
{
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/tmp
        RCC_DIR     = $$PWD/release/tmp
        OBJECTS_DIR = $$PWD/release/tmp
}

SOURCES += \
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
