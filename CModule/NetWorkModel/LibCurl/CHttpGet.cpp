#include "CHttpGet.h"

CHttpGet::CHttpGet(QObject *parent) : QObject(parent)
{
    testGet();
}

void CHttpGet::testGet()
{
    curl_global_init( CURL_GLOBAL_ALL );
    CURL *pCurl = curl_easy_init();
    CURLcode    retCode;

    char response[1024] = { '\0' };
    curl_easy_setopt( pCurl, CURLOPT_URL, "http://www.baidu.com" );
    curl_easy_setopt( pCurl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_setopt( pCurl, CURLOPT_WRITEFUNCTION, &CHttpGet::on_receive_response );
    curl_easy_setopt( pCurl, CURLOPT_WRITEDATA, response );

    retCode = curl_easy_perform( pCurl );

//    qDebug() << "ret = " << QString::fromStdString( response_string );

    curl_easy_cleanup( pCurl );
}

size_t CHttpGet::on_receive_response(void *data, size_t size, size_t nmemb, void *userdata)
{
    // 处理从服务器接收到的数据
    return size*nmemb;
}
