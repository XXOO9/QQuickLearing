#ifndef CHTTPSDEMO_H
#define CHTTPSDEMO_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>

class CHttpsDemo : public QObject
{
    Q_OBJECT
public:
    explicit CHttpsDemo(QObject *parent = nullptr);
    void test();

    void testInsertMulti();
signals:

public slots:
    void onNewReplyAvaulable( QNetworkReply *pReply );

private:
    QNetworkAccessManager   *m_pNetWorkMgr = nullptr;

};

#endif // CHTTPSDEMO_H
