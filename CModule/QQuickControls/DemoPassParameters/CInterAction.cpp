#include "CInterAction.h"

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{

}

void CInterAction::test_variant(QVariantMap val)
{
    qDebug() << val;
}

void CInterAction::test_vector()
{

}

void CInterAction::test_variantList(QVariantList list)
{
    qDebug() << list;
}
