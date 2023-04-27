QT += quick
CONFIG += c++11

INCLUDEPATH += $$PWD/oatpp

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/bin/debug
        LIBS       += -L$$PWD/ -loatpp  \
                               -lwsock32    \
                               -lws2_32
}else
{
        DESTDIR     = $$PWD/bin/release
        LIBS       += -L$$PWD/ -loatpp
}


DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CCodeGen.cpp \
        CHttpGetHandler.cpp \
        CHttpPostHandle.cpp \
        CServer.cpp \
        CUserInfo.cpp \
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
    CCodeGen.h \
    CHttpGetHandler.h \
    CHttpPostHandle.h \
    CServer.h \
    CUserInfo.h
