#ifndef CHTTPREQUESTMGR_H
#define CHTTPREQUESTMGR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include "CHttpAbstractRequestElement.h"

class CHttpRequestMgr : public QObject
{
    Q_OBJECT
public:
    CHttpRequestMgr *getInstance();
    virtual ~CHttpRequestMgr() override;

    void appendRequest( CHttpAbstractRequestElement *srcRequestElement );

    bool isRequestQueueEmpty() const;

private:
    explicit CHttpRequestMgr(QObject *parent = nullptr);
    void init();
    void initRequestAddr();
    void startRequest(CHttpAbstractRequestElement *srcRequestElement);

private:
    static CHttpRequestMgr  *m_pNetWorkMgr;
    static QMutex            m_mutex;

    QQueue< CHttpAbstractRequestElement* >   m_requestQueue;
    QNetworkAccessManager                   *m_pNetWorkAccessMgr = nullptr;

};

#endif // CHTTPREQUESTMGR_H
