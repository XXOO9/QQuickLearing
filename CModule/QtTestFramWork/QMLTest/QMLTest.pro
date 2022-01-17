CONFIG += warn_on qmltestcase


CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/debug
        MOC_DIR     = $$PWD/debug/tmp
        RCC_DIR     = $$PWD/debug/tmp
        OBJECTS_DIR = $$PWD/debug/tmp
}else
{
        DESTDIR     = $$PWD/release
        MOC_DIR     = $$PWD/release/tmp
        RCC_DIR     = $$PWD/release/tmp
        OBJECTS_DIR = $$PWD/release/tmp
}

TEMPLATE = app

DISTFILES += \
    tst_demotest.qml

SOURCES += \
    main.cpp
