#ifndef CHTTPUSERIDENTIFY_H
#define CHTTPUSERIDENTIFY_H

#include <QObject>

#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include "../CHttpAbstractNetWork/CHttpConfigCommonDefine.h"
#include "../CHttpResult/CUserIdentifyRet.h"
#include "../chttpmodule_global.h"

namespace userIdentifyParaKey {
          const QString faceFeature = "faceFeature";
          const QString cardNo = "cardNo";
}

class CHTTPMODULESHARED_EXPORT CHttpUserIdentify : public CHttpAbstractNetWork
{
public:
    CHttpUserIdentify( QString faceFeature , QString cardNo = "");
    virtual ~CHttpUserIdentify() override;

    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    int userInfoCount();
    QString getUserInfoByKey( QString key );

public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;

private:
    CUserIdentifyRet    m_ret;
};

#endif // CHTTPUSERIDENTIFY_H
