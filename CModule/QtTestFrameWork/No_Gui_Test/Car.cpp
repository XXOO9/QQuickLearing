#include "Car.h"

Car::Car(QString brand, int wheels, QString color)
{
    m_brand = brand;
    m_wheels = wheels;
    m_color = color;
}

QString Car::brand() const
{
    return m_brand;
}

int Car::wheels() const
{
    return m_wheels;
}

QString Car::color() const
{
    return m_color;
}
