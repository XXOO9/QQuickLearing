#include "CInterAction.h"

#include <QJsonDocument>

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{

}

void CInterAction::testFunc()
{
    QVariantMap varMap;

//    for( int i = 0; i < 2; i++ ){
        varMap.insert( "name", "WDNMD" );
        varMap.insert( "age", "1111" );
//    }

    QJsonObject jsObj = QJsonObject::fromVariantMap( varMap );
    QJsonDocument jsDoc;
    jsDoc.setObject( jsObj );

    qDebug() << "size = " << varMap.size();
    emit sigPassJson( QString::fromLocal8Bit( jsDoc.toJson() ) );
}
