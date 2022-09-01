#include "CEnumClass.h"

CEnumClass::CEnumClass(QObject *parent) : QObject(parent)
{
    m_dayEnum = QMetaEnum::fromType< CEnumClass::Day >();

    qDebug() << "name = " << m_dayEnum.name();
    qDebug() << "enumName = " << m_dayEnum.enumName();
    qDebug() << "scope = " << m_dayEnum.scope();

    qDebug() << "val 0 name = " <<m_dayEnum.valueToKey( Day::MonDay );
    qDebug() << "key 0 name = " <<m_dayEnum.keyToValue( "SunDayyy" );

}

void CEnumClass::Int2Enum(int val)
{

}
