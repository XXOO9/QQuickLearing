#ifndef CHTTPSYNCSCORESTD_H
#define CHTTPSYNCSCORESTD_H

#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include <QObject>
#include "CSyncScoreStdRet.h"
#include "../chttpmodule_global.h"

class CHTTPMODULESHARED_EXPORT CHttpSyncScoreStd : public CHttpAbstractNetWork
{
public:
    CHttpSyncScoreStd();
    virtual ~CHttpSyncScoreStd() override;

    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    int retultCount();
    QMap<QString, QString> getRetGroup( int index );
    QString getSingleRet( int index, QString key );

public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;

private:
    CSyncScoreStdRet    m_ret;
};

#endif // CHTTPSYNCSCORESTD_H
