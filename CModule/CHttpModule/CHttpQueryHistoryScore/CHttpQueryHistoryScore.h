#ifndef CHTTPQUERYHISTORYSCORE_H
#define CHTTPQUERYHISTORYSCORE_H

#include <QObject>
#include <QObject>
#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include "../chttpmodule_global.h"
#include "CQueryCommonHistoryRet.h"

class CHTTPMODULESHARED_EXPORT CHttpQueryHistoryScore : public CHttpAbstractNetWork
{
public:
    CHttpQueryHistoryScore();
    virtual ~CHttpQueryHistoryScore() override;
    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    void setUserId( QString userId );
    void setTestItem(TEST_ITEM testItem );
    void setTimeInterval( queryTimeInterval  timeInterval );
    void setTestScoreType( testType type );

    int historyCount();
    QMap<QString,QString> getGroupInfo( int index );
    QString getSingleRet( int index, QString key );


public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;

private:
    CQueryCommonHistoryRet   m_ret;
};

#endif // CHTTPQUERYHISTORYSCORE_H
