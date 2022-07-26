QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

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
        CFFmpegLevel1.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CFFmpegLevel1.h
