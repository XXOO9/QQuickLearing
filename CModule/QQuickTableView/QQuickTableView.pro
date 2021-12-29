QT += quick core qml
CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/MOC
        RCC_DIR     = $$PWD/debug/RCC
        OBJECTS_DIR = $$PWD/debug/OBJ
}else
{
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/MOC
        RCC_DIR     = $$PWD/release/RCC
        OBJECTS_DIR = $$PWD/release/OBJ
}

SOURCES += \
        CDataModel.cpp \
        CTableModelRowData.cpp \
        CustTableModel.cpp \
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
    CDataModel.h \
    CTableModelRowData.h \
    CustTableModel.h
