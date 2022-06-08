#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QDebug>

class Car
{
public:
    Car( QString brand = "null", int wheels = 0, QString color = "orgin" );

    QString brand() const;

    int wheels() const;

    QString color() const;

private:
    QString m_brand  = "TSL";
    int     m_wheels = 4;
    QString m_color  = "gray";
};

#endif // CAR_H
