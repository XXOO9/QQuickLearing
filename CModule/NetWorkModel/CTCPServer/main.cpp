#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CTCPServer.h"

using namespace std;

string getString()
{
    string a = "aaaa";
    qDebug() << "a = " << &a;

    int aa = 4;
    int b = 2;
    auto c = aa | b;
    qDebug()  << c;
    return a;
}

int main(int argc, char *argv[])
{
    string &&aa = getString();
    qDebug() << "aa = " << &aa;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CTCPServer server;
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
