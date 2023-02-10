#include "CHttpMultiHeartBeat.h"

CHttpMultiHeartBeat::CHttpMultiHeartBeat(const QString &url, const QString &tokenString) : CHttpAbstractRequestElement( url )
{
    setRequestType( RequestType::POST );
    setRequestTokenString( tokenString );
    setRequestHeaderContent( HeaderContentKeys::contentType, HeaderContentKeys::contentTypeJson );
}

CHttpMultiHeartBeat::~CHttpMultiHeartBeat()
{

}

void CHttpMultiHeartBeat::setHeartbeatInfo(const QVariantMap &srcInfoMap)
{
    QByteArray &&jsonData = variantMap2JsonByteArray( srcInfoMap );
    this->setSendData( jsonData );
}

void CHttpMultiHeartBeat::onNewReplyAvailable()
{

}

void CHttpMultiHeartBeat::startSendRequest(QNetworkAccessManager *pNetWorkMgr)
{
    if( this->sendData().isEmpty() ){
        return;
    }

    QNetworkReply *pReply = pNetWorkMgr->post( request(), this->sendData() );
    connect( pReply, &QNetworkReply::finished, this, &CHttpMultiHeartBeat::onNewReplyAvailable, Qt::QueuedConnection );
    setReply( pReply );
    startRequestTimeoutTimer();
}
