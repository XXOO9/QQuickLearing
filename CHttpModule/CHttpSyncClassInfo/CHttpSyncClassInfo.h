#ifndef CHTTPSYNCCLASSINFO_H
#define CHTTPSYNCCLASSINFO_H

#include <QObject>
#include <QObject>
#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include "../chttpmodule_global.h"
#include "CSyncClassInfoRet.h"

class CHTTPMODULESHARED_EXPORT CHttpSyncClassInfo : public CHttpAbstractNetWork
{
public:
    CHttpSyncClassInfo( QString timeSatmp = "" );
    virtual ~CHttpSyncClassInfo() override;
    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    int classInfoCount();
    QMap<QString, QString> getClassGroupInfo( int index );
    QString getSingleRet( int index, QString key );

public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;

private:
    CSyncClassInfoRet m_ret;
};

#endif // CHTTPSYNCCLASSINFO_H
