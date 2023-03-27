##主要运用了opencv打开摄像头，打开摄像头是在线程中，
QT += quick
CONFIG += c++11

INCLUDEPATH += $$PWD/../opencv3.4.1/opencvInclude

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/bin/debug
        MOC_DIR     = $$PWD/bin/debug/temp/moc
        RCC_DIR     = $$PWD/bin/debug/temp/rcc
        UI_DIR      = $$PWD/bin/debug/temp/ui
        OBJECTS_DIR = $$PWD/bin/debug/temp/obj
        LIBS       += -L$$PWD/../opencv3.4.1/bin -lopencv_world341d
}else
{
        DESTDIR     = $$PWD/bin/release
        MOC_DIR     = $$PWD/bin/release/temp/moc
        RCC_DIR     = $$PWD/bin/release/temp/rcc
        UI_DIR      = $$PWD/bin/release/temp/ui
        OBJECTS_DIR = $$PWD/bin/release/temp/obj
        LIBS       +=-L$$PWD/../opencv3.4.1/bin -lopencv_world341
        LIBS       +=-L$$PWD/../opencv3.4.1/opencvlib -lopencv_world341
}

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CCameraFrameDisplay.cpp \
        CCameraThreadControler.cpp \
        COpencvBase.cpp \
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
    CCameraFrameDisplay.h \
    CCameraThreadControler.h \
    COpencvBase.h
