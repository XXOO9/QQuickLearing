QT -= gui
QT += sql core

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#参考文章: 1.几种ORM的对比  http://blog.sina.com.cn/s/blog_999d1f4c0101e12l.html
#        2. QxORM 主页: https://www.qxorm.com/qxorm_en/home.html
#        3. QxORM的一个教程: https://www.ljjyy.com/archives/2021/03/100647.html


include( $$PWD/liteSql/liteSql.pri )
## 网上下载的只有debug下的库， 没有release的库，有时间研究编译源码编出来

CONFIG( debug, debug | release ){
        DESTDIR     =   $$PWD/bin/debug
        LIBS       += -L$$PWD/thirdParty/liteSql/lib/x64/ -llitesqld
}else
{
        DESTDIR     = $$PWD/bin/release
}


SOURCES += \
        CDataBase.cpp \
        CSqlLite.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CDataBase.h \
    CSqlLite.h
