QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += $$PWD/../Components/

CONFIG( debug, debug | release ){
DESTDIR = $$PWD/bin/debug
LIBS    += -L$$PWD/bin/debug/ -lComponents
}

CONFIG( release, debug | release ){
DESTDIR = $$PWD/bin/release
}

SOURCES += \
    main.cpp \
    CMainFrame.cpp

HEADERS += \
    CMainFrame.h

FORMS += \
    CMainFrame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
