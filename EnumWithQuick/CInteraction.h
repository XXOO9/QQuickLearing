#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include <QMetaEnum>
/*
 *要在QML中使用C++的枚举类型 ，首先要使用qmlResgistertype注册目标枚举类型所在的类到元系统,
 *  如果使用 rootContext()->setContextProperty() 注册到上下文这种方法就不能访问枚举类型
 *
 *
*/
class CInteraction : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString   name READ name WRITE setName NOTIFY sigNameChenged )
    Q_PROPERTY( QString   colorName READ colorName  CONSTANT )
    Q_PROPERTY( ColorEnum color READ color WRITE setColor NOTIFY sigColorChanged )

public:
    explicit CInteraction(QObject *parent = nullptr);
    enum class ColorEnum{
        RED = 0,
        GREEN,
        YELLOW,
        BLUE
    };
    Q_ENUM( ColorEnum )

    Q_INVOKABLE void settColor( const CInteraction::ColorEnum color );

    QString name();
    void setName( QString _name );

    ColorEnum color();
    void setColor( ColorEnum color );

    Q_INVOKABLE QString colorName();

signals:
    void sigNameChenged( QString _name );
    void sigColorChanged( const CInteraction::ColorEnum color );

public slots:

private:
    QString m_name;
    ColorEnum m_color;
    QString m_colorName;
};

#endif // CINTERACTION_H
