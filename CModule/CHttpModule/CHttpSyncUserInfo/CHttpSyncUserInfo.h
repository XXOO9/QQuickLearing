#ifndef CHTTPSYNCUSERINFO_H
#define CHTTPSYNCUSERINFO_H

#include <QObject>
#include <QVector>
#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include "../CHttpAbstractNetWork/CHttpConfigCommonDefine.h"
#include "../CHttpResult/CAbstractResult.h"
#include "../chttpmodule_global.h"
#include "CSyncUserInfoRet.h"


class CHTTPMODULESHARED_EXPORT CHttpSyncUserInfo : public CHttpAbstractNetWork
{
    Q_OBJECT
public:
    CHttpSyncUserInfo( QString timeStamp );
    virtual ~CHttpSyncUserInfo() override;

    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    int userInfoCount();
    QMap<QString, QString> getInfos( int index );
    QString getSingleInfo( int index, QString key );

public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;

private:
    CSyncUserInfoRet   m_ret;

};

#endif // CHTTPSYNCUSERINFO_H
