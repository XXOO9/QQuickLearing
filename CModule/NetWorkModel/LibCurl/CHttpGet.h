#ifndef CHTTPGET_H
#define CHTTPGET_H

#include <QObject>
#include <QDebug>

#include "libcurl/include/curl/curl.h"

class CHttpGet : public QObject
{
    Q_OBJECT
public:
    explicit CHttpGet(QObject *parent = nullptr);

    void testGet();

    size_t on_receive_response(void *data, size_t size, size_t nmemb, void* userdata);

signals:

public slots:
};

#endif // CHTTPGET_H
