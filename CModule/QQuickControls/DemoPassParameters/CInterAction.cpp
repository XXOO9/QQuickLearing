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

    varMap[ "index1" ] = 11111111;
    varMap[ "index2" ] = 222222;
    varMap[ "index3" ] = 33333;
    varMap[ "index4" ] = 444;
    varMap[ "index5" ] = 5;

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

QVariantMap CInterAction::test_VariantList_to_qml()
{
    QVariantMap list;

    QVariantMap map1 = {
        { "map1_1", "map1_value1" },
        { "map1_2", "map1_value2" },
        { "map1_3", "map1_value3" }
    };

    QVariantMap map2 = {
        { "map2_1", "map2_value1" },
        { "map2_2", "map2_value2" },
        { "map2_3", "map2_value3" }
    };

    QVariantMap map3 = {
        { "map3_1", "map3_value1" },
        { "map3_2", "map3_value2" },
        { "map3_3", "map3_value3" }
    };

    list[ "devList1" ] = map1;
    list[ "devList2" ] = map2;
    list[ "devList3" ] = map3;


    return list;
}
