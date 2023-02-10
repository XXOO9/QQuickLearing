#include "CHttpAbstractRequestElement.h"

CHttpAbstractRequestElement::CHttpAbstractRequestElement(const QString &targetRequestAddr)
{
    m_request.setUrl( QUrl( targetRequestAddr ) );
}

CHttpAbstractRequestElement::~CHttpAbstractRequestElement()
{
    if( nullptr != m_pReply ){
        if( m_pReply->isRunning() ){
            m_pReply->abort();
        }

        m_pReply->deleteLater();
    }

    m_pReply = nullptr;
}

RequestType CHttpAbstractRequestElement::requestType() const
{
    return m_requestType;
}

QByteArray CHttpAbstractRequestElement::sendData() const
{
    return m_sendData;
}

QNetworkRequest CHttpAbstractRequestElement::request() const
{
    return m_request;
}

QNetworkReply *CHttpAbstractRequestElement::reply() const
{
    return m_pReply;
}

void CHttpAbstractRequestElement::setReply(QNetworkReply *pReply)
{
    m_pReply = pReply;
}

QByteArray CHttpAbstractRequestElement::variantMap2JsonByteArray(const QVariantMap &srcInfoMap)
{
    QJsonObject jsObj = QJsonObject::fromVariantMap( srcInfoMap );
    QJsonDocument jsDoc( jsObj );

    return jsDoc.toJson();
}

void CHttpAbstractRequestElement::startRequestTimeoutTimer()
{
    m_requertTimeoutTimer.start( 3000 );
}

void CHttpAbstractRequestElement::initAbstractRequest()
{
    connect( &m_requertTimeoutTimer, &QTimer::timeout, this, &CHttpAbstractRequestElement::onRequestTimerTimeout );
}

void CHttpAbstractRequestElement::requestErrorHandler()
{
    if( nullptr == reply() ){
        return;
    }
}

void CHttpAbstractRequestElement::onRequestTimerTimeout()
{
    m_requertTimeoutTimer.stop();

    if( nullptr == m_pReply ){
        return;
    }

    if( m_pReply->isFinished() ){
        return;
    }

    m_pReply->abort();
}

QStringMap CHttpAbstractRequestElement::paraMap() const
{
    return m_paraMap;
}

void CHttpAbstractRequestElement::setParaMap(const QStringMap &paraMap)
{
    m_paraMap = paraMap;
}

void CHttpAbstractRequestElement::setRequestType(const RequestType &requestType)
{
    m_requestType = requestType;
}

void CHttpAbstractRequestElement::setRequestHeaderContent(const QByteArray &headerType, const QByteArray &headerContent)
{
    m_request.setRawHeader( headerType, headerContent );
}

void CHttpAbstractRequestElement::setRequestTokenString(const QString &tokenString)
{
    m_request.setRawHeader( HeaderContentKeys::contentTypeAuthorization, tokenString.toLocal8Bit() );
}

void CHttpAbstractRequestElement::setSendData(const QByteArray &sendData)
{
    m_sendData = sendData;
}
