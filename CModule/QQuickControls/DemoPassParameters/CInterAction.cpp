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

QJsonArray CInterAction::test_JsonArray_to_qml()
{
    QJsonArray jsArray;
    QVariantList varList;

    varList << "W" << "D" << "N" << "M" << "D";

    jsArray = QJsonArray::fromVariantList( varList );

    return jsArray;
}

QVariantMap CInterAction::test_JsonObject_to_qml()
{
    QJsonObject jsObj;

    QVariantMap varMap;

    varMap[ "index" ] = 1;
    varMap[ "index" ] = 2;
    varMap[ "index" ] = 3;
    varMap[ "index" ] = 4;
    varMap[ "index" ] = 5;

    return varMap;


}

QJsonArray CInterAction::test_JsonArrayObject_to_qml()
{
    QJsonArray jsArr;
    QVariantList varList;

    for( int i = 0; i < 5; i++ ){
        QVariantMap tmpMap;
        tmpMap[ "index" ] = i;

        varList << tmpMap;
    }

    jsArr = QJsonArray::fromVariantList( varList );

    return jsArr;
}
