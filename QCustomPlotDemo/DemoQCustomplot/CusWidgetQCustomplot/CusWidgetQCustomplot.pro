QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    qcustomplot.cpp

HEADERS += \
    MainWindow.h \
    qcustomplot.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
