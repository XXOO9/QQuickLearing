#include "CInterAction.h"

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{

}

void CInterAction::testVariantMap(QVariantMap map)
{
    qDebug() << map;
}
