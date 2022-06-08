#include "CInteraction.h"

CInteraction::CInteraction(QObject *parent) : QObject(parent)
{

}

void CInteraction::setEnum(short color)
{
    qDebug() << "ret = " << color;
}
