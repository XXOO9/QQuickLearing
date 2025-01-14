QT -= gui

CONFIG += c++11
CONFIG -= app_bundle

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CFastSort.cpp \
        StringAlgorithm.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CFastSort.h \
    StringAlgorithm.h
