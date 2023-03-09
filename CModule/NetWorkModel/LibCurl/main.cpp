#include <QGuiApplication>
#include <iostream>
#include <QQmlApplicationEngine>
#include "CHttpGet.h"

using namespace std;
typedef struct {
    char *memory;
    size_t size;
} Memory;

// 回调函数，处理文件数据
static size_t on_write_data(void* buffer, size_t size, size_t nmemb, void *userp)
{
    Memory* mem = (Memory*)userp;

    size_t write_size = size * nmemb;
    mem->memory = (char*)realloc(mem->memory, mem->size + write_size + 1);
    if(mem->memory == NULL) return 0;

    memcpy(&(mem->memory[mem->size]), buffer, write_size);
    mem->size += write_size;
    mem->memory[mem->size] = 0;

    std::string ret( mem->memory );
    qDebug() << QString::fromStdString( ret );
    std::cout << ret << std::endl;

    return write_size;
}

void testGet()
{
    CURL *curl;
    CURLcode res;
    Memory mem = { 0 };

    char rets[ 1024 ];
    memset( rets, 0, 1024 );

    curl = curl_easy_init();
    if(curl) {
        // 设置访问 URL 和一些 GET 请求配置项
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
//        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");

        // 设置回调函数，保存返回数据到内存
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, on_write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, rets);

        // 执行 GET 请求
        res = curl_easy_perform(curl);

        // 处理返回结果
        if(res == CURLE_OK) {
            fprintf(stdout, "%s", mem.memory);
        }
        else {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
        }

        // 释放资源
        free(mem.memory);
        curl_easy_cleanup(curl);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    CHttpGet a;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
