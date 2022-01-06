QT += quick qml gui core
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD/thirdParty/opencv/include

include($$PWD/InterAction.pri)
include($$PWD/DevCamera.pri)
include($$PWD/APP.pri)

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/MOC
        RCC_DIR     = $$PWD/debug/RCC
        OBJECTS_DIR = $$PWD/debug/OBJ

}
CONFIG( release, debug | release ){
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/MOC
        RCC_DIR     = $$PWD/release/RCC
        OBJECTS_DIR = $$PWD/release/OBJ
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
