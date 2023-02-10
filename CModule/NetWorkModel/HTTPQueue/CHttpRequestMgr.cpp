#include "CHttpRequestMgr.h"

CHttpRequestMgr::CHttpRequestMgr(QObject *parent) : QObject(parent)
{
    m_requestQueue.clear();
    init();
}

CHttpRequestMgr *CHttpRequestMgr::getInstance()
{
    QMutexLocker locker( &m_mutex );
    if( nullptr == m_pNetWorkMgr ){
        m_pNetWorkMgr = new CHttpRequestMgr();
    }

    return m_pNetWorkMgr;
}

CHttpRequestMgr::~CHttpRequestMgr()
{

}

void CHttpRequestMgr::appendRequest(CHttpAbstractRequestElement *srcRequestElement)
{
    m_requestQueue.enqueue( srcRequestElement );
}

bool CHttpRequestMgr::isRequestQueueEmpty() const
{
    return m_requestQueue.isEmpty();
}

void CHttpRequestMgr::init()
{
    if( nullptr == m_pNetWorkAccessMgr ){
        m_pNetWorkAccessMgr = new QNetworkAccessManager( this );
    }
}

void CHttpRequestMgr::initRequestAddr()
{

}

void CHttpRequestMgr::startRequest( CHttpAbstractRequestElement *srcRequestElement )
{
    srcRequestElement->startSendRequest( m_pNetWorkAccessMgr );
}


CHttpRequestMgr *CHttpRequestMgr::m_pNetWorkMgr = nullptr;
QMutex           CHttpRequestMgr::m_mutex;
