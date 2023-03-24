QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/bin/debug
        MOC_DIR     = $$PWD/bin/debug/temp/moc
        RCC_DIR     = $$PWD/bin/debug/temp/rcc
        UI_DIR      = $$PWD/bin/debug/temp/ui
        OBJECTS_DIR = $$PWD/bin/debug/temp/obj
}else
{
        DESTDIR     = $$PWD/bin/release
        MOC_DIR     = $$PWD/bin/release/temp/moc
        RCC_DIR     = $$PWD/bin/release/temp/rcc
        UI_DIR      = $$PWD/bin/release/temp/ui
        OBJECTS_DIR = $$PWD/bin/release/temp/obj
}

SOURCES += \
        CUPDStation.cpp \
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
    CUPDStation.h
