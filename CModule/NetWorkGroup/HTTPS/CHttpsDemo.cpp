#include "CHttpsDemo.h"

CHttpsDemo::CHttpsDemo(QObject *parent)
    : QObject{parent}
{
    testInsertMulti();
}

void CHttpsDemo::test()
{
    m_pNetWorkMgr = new QNetworkAccessManager( this );
    connect( m_pNetWorkMgr, &QNetworkAccessManager::finished, this, &CHttpsDemo::onNewReplyAvaulable );
    QNetworkRequest request;
    request.setUrl( QUrl( "https://localhost:444/http-test/param?id=100" ) );


    m_pNetWorkMgr->get( request );
}

void CHttpsDemo::testInsertMulti()
{
    QVariantMap map;
    map.insertMulti( "key", 1 );
    map.insertMulti( "key", 2 );

    auto ret = map.value( "key" );
    auto rets = map.values( "key" );
    qDebug() << "ret = " << ret;
    qDebug() << "rets = " << rets;
}

void CHttpsDemo::onNewReplyAvaulable(QNetworkReply *pReply)
{
    if( pReply->error() != QNetworkReply::NoError ){
        qDebug() << "error" << pReply->errorString();
        pReply->deleteLater();
        pReply = nullptr;
        return;
    }

    qDebug() << "ret = " << QString::fromUtf8( pReply->readAll() ) ;
}
