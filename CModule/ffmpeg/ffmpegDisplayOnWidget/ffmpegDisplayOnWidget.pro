QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


INCLUDEPATH += $$PWD/../thirdPart/ffmpeg/include/
CONFIG( debug, debug | release ){
        DESTDIR = $$PWD/debug
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavcodec
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavdevice
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavfilter
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavformat
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavutil
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lpostproc
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lswresample
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lswscale
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavutil
}else{
        DESTDIR = $$PWD/release
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavcodec
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavdevice
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavfilter
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavformat
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavutil
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lpostproc
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lswresample
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lswscale
        LIBS   += -L$$PWD/../thirdPart/ffmpeg/lib/ -lavutil
}

SOURCES += \
    main.cpp \
    Widget.cpp

HEADERS += \
    Widget.h

FORMS += \
    Widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
