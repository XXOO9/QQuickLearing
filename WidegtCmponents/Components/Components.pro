QT += gui core widgets

TEMPLATE = lib
DEFINES += COMPONENTS_LIBRARY

CONFIG += c++17

include( $$PWD/Tables/Tables.pri )

CONFIG( debug, debug | release ){
DESTDIR = $$PWD/../ComponentsTest/bin/debug
}

CONFIG( release, debug | release ){
DESTDIR = $$PWD/../ComponentsTest/bin/release
}

SOURCES += \
    Components.cpp \
    LoginWidget.cpp

HEADERS += \
    Components_global.h \
    Components.h \
    LoginWidget.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    LoginWidget.ui
