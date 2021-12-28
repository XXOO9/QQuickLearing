#include "CInteraction.h"

CInteraction::CInteraction(QObject *parent) : QObject(parent)
{

}

void CInteraction::settColor(CInteraction::ColorEnum color)
{
    switch (color) {
    case ColorEnum::BLUE:
        qDebug() << "bbbbbbbbbbbbbbbbbbb";
        break;
    default:
        break;
    }
}

QString CInteraction::name()
{
    return m_name;
}

void CInteraction::setName(QString _name)
{
    m_name = _name;
    emit sigNameChenged( m_name );
}

CInteraction::ColorEnum CInteraction::color()
{
    return m_color;
}

void CInteraction::setColor(CInteraction::ColorEnum color)
{
    m_color = color;
    QMetaEnum metaEnum = QMetaEnum::fromType<CInteraction::ColorEnum>();
    qDebug() << "key = " << metaEnum.valueToKey( static_cast<int>(m_color) );
    emit sigColorChanged( m_color );
}

QString CInteraction::colorName()
{
    QMetaEnum meta = QMetaEnum::fromType<CInteraction::ColorEnum>();
    QString colorName = meta.valueToKey( static_cast<int>(m_color) );
    return colorName;
}
