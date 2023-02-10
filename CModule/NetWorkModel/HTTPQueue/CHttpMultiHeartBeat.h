#ifndef CHTTPMULTIHEARTBEAT_H
#define CHTTPMULTIHEARTBEAT_H

#include "CHttpAbstractRequestElement.h"
#include <QObject>

class CHttpMultiHeartBeat : public CHttpAbstractRequestElement
{
    Q_OBJECT
public:
    CHttpMultiHeartBeat( const QString &url, const QString &tokenString );
    virtual ~CHttpMultiHeartBeat() override;

    //设置心跳信息
    void setHeartbeatInfo( const QVariantMap &srcInfoMap );

public slots:
    virtual void onNewReplyAvailable() override;
    virtual void startSendRequest( QNetworkAccessManager *pNetWorkMgr ) override;
};

#endif // CHTTPMULTIHEARTBEAT_H
