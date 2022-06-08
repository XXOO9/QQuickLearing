QT += quick core  network webengine
CONFIG += c++11

#要使用webengine这个模块，目前调查出来的情况来看，只有MSVC2017及以上才能用的模块


DEFINES += QT_DEPRECATED_WARNINGS


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
}else
{
        DESTDIR     = $$PWD/release
}

SOURCES += \
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
