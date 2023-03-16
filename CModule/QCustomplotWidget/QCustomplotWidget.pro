#-------------------------------------------------
#
# Project created by QtCreator 2023-03-14T10:31:48
#
#-------------------------------------------------

QT       += core gui

greaterThan( QT_MAJOR_VERSION, 4 ): QT += widgets printsupport

INCLUDEPATH += $$PWD/thirdParty/qcustomplot/

DEFINES += QCUSTOMPLOT_USE_OPENGL

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

TARGET = QCustomplotWidget
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS



CONFIG += c++11

SOURCES += \
        CBasePlot.cpp \
        CPlotLoadDataThread.cpp \
        main.cpp \
        CMainWidget.cpp \
        thirdParty/qcustomplot/qcustomplot.cpp

HEADERS += \
        CBasePlot.h \
        CMainWidget.h \
        CPlotLoadDataThread.h \
        thirdParty/qcustomplot/qcustomplot.h

FORMS += \
        CMainWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
