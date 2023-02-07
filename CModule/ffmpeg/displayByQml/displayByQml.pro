QT += quick core gui multimedia
CONFIG += c++17

INCLUDEPATH += $$PWD/../thirdPart/ffmpeg/include/

MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj

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
        CAudioPlayer.cpp \
        CFFmpegAudioDecoder.cpp \
        CFFmpegLevel1.cpp \
        CFFmpegVideoDecoder.cpp \
        CVideoFrameProvider.cpp \
        main.cpp \
        videoDecoder.cpp

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
    CAudioPlayer.h \
    CFFmpegAudioDecoder.h \
    CFFmpegLevel1.h \
    CFFmpegVideoDecoder.h \
    CVideoFrameProvider.h \
    videoDecoder.h
