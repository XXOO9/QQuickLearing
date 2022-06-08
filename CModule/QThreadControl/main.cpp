#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ThreadPrint.h"
#include "ThreadMgr.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    ThreadMgr *th1 = new ThreadMgr();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty( "ThreadMgr", th1 );

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
