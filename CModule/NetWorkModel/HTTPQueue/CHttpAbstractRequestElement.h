#ifndef CHTTPREQUESTELEMENT_H
#define CHTTPREQUESTELEMENT_H

#include <QDebug>
#include <QTimer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>

#include "CHttpCommondefine.h"

typedef QMap<QString, QString>  QStringMap;

using namespace HeaderContentKeys;

class CHttpAbstractRequestElement : public QObject
{
    Q_OBJECT
public:
    CHttpAbstractRequestElement( const QString &targetRequestAddr );
    virtual ~CHttpAbstractRequestElement() override;

    //设置请求类型
    RequestType requestType() const;
    void setRequestType(const RequestType &requestType);

    //如果是post请求，则设置需要发送的内容
    QByteArray sendData() const;
    void setSendData(const QByteArray &sendData);

    //如果是get请求，则设置请求参数
    QStringMap paraMap() const;
    void setParaMap(const QStringMap &paraMap);

    QNetworkRequest request() const;

    QNetworkReply *reply() const;
    void setReply(QNetworkReply *reply);

    static QByteArray variantMap2JsonByteArray( const QVariantMap &srcInfoMap );


protected:
    //开启请求超时定时器
    void startRequestTimeoutTimer();

    //设置请求头参数
    void setRequestHeaderContent( const QByteArray &headerType, const QByteArray &headerContent );

    //设置请求token
    void setRequestTokenString( const QString &tokenString );

private:
    void initAbstractRequest();


public slots:
    virtual void onNewReplyAvailable() = 0;
    virtual void startSendRequest( QNetworkAccessManager *pNetWorkMgr ) = 0;
    virtual void requestErrorHandler();
    virtual void onRequestTimerTimeout();

private:
    QNetworkReply      *m_pReply = nullptr;
    RequestType         m_requestType = RequestType::POST;
    QNetworkRequest     m_request;
    QTimer              m_requertTimeoutTimer;

    //用于post请求 发送的字节数据, Get请求用不上
    QByteArray          m_sendData = "";

    //用户GET请求拼接参数的数据
    QStringMap          m_paraMap;
};

#endif // CHTTPREQUESTELEMENT_H

