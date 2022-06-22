#include "CInterAction.h"

#include <QJsonDocument>

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{

}

void CInterAction::testFunc()
{
    QVariantMap varMap;

    varMap.insertMulti( "name", "zmc" );
    varMap.insertMulti( "age", "1111" );

    QJsonObject jsObj = QJsonObject::fromVariantMap( varMap );
    QJsonDocument jsDoc;

    jsDoc.setObject( jsObj );

//    qDebug() << "size = " << varMap.size();

    QString jsString = QString::fromLocal8Bit( jsDoc.toJson() );
    emit sigPassJson( jsString );
}
