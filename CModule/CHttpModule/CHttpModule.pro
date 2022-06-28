#-------------------------------------------------
#
# Project created by QtCreator 2021-12-21T16:18:04
#
#-------------------------------------------------

SUBDIRS += \
            unitTest

QT       += network

QT       -= gui

TARGET = CHttpModule
TEMPLATE = lib

DEFINES += CHTTPMODULE_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

include($$PWD/CHttpAbstractNetWork/CHttpAbstractNetWork.pri)
include($$PWD/CHttpConfigReader/CHttpConfigReader.pri)
include($$PWD/CHttpSyncUserInfo/CHttpSyncUserInfo.pri)
include($$PWD/CHttpResult/CHttpResult.pri)
include($$PWD/CHttpUserIdentify/CHttpUserIdentify.pri)
include($$PWD/CHttpSyncScoreStd/CHttpSyncScoreStd.pri)
include($$PWD/CHttpHeartBeat/CHttpHeartBeat.pri)
include($$PWD/CHttpUpLoadCommonScore/CHttpUpLoadCommonScore.pri)
include($$PWD/CHttpSyncClassInfo/CHttpSyncClassInfo.pri)
include($$PWD/CHttpQueryHistoryScore/CHttpQueryHistoryScore.pri)
include($$PWD/CHttpUpLoadBodyScore/CHttpUpLoadBodyScore.pri)
include($$PWD/CHttpTouristRecord/CHttpTouristRecord.pri)
include($$PWD/CHttpQueryBodyElement/CHttpQueryBodyElement.pri)
include($$PWD/CHttpGetVideoUrls/CHttpGetVideoUrls.pri)
include($$PWD/CHttpDownLoadFile/CHttpDownLoadFile.pri)
include($$PWD/CHttps/CHttps.pri)


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/MOC
        RCC_DIR     = $$PWD/debug/RCC
        OBJECTS_DIR = $$PWD/debug/OBJ
}else
{
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/MOC
        RCC_DIR     = $$PWD/release/RCC
        OBJECTS_DIR = $$PWD/release/OBJ
}



SOURCES += \
        CHttpModule.cpp

HEADERS += \
        CHttpModule.h \
        chttpmodule_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    CHttps/CHttps.pri
