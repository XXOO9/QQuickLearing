QT += quick core gui
CONFIG += c++11

#DEFINES += QCUSTOMPLOT_USE_OPENGL

TARGET = ChartViewThread
greaterThan( QT_MAJOR_VERSION, 4 ): QT += widgets printsupport

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/bin/debug
        LIBS       += -lopengl32 -lglu32
}else
{
        DESTDIR     = $$PWD/bin/release
        LIBS       += -lopengl32 -lglu32
}

MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj

DEFINES += QT_DEPRECATED_WARNINGS

include( $$PWD/BasesicPlot/BasesicPlot.pri )

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        qcustomplot.cpp

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
    qcustomplot.h
