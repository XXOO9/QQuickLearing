#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include <QMetaEnum>
#include "CProjectEnums.h"
/*
 *要在QML中使用C++的枚举类型 ，首先要使用qmlResgistertype注册目标枚举类型所在的类到元系统,
 *  如果使用 rootContext()->setContextProperty() 注册到上下文这种方法就不能访问枚举类型
 *  在C++定义函数的时候，貌似不能直接写枚举变量类型，没办法只好写short 或者int类型，在C++函数中进行强转成对应的枚举变量
 *
*/
class CInteraction : public QObject
{
    Q_OBJECT
public:
    CInteraction( QObject *parent = nullptr );

    Q_INVOKABLE void setEnum( short color );
};

#endif // CINTERACTION_H
