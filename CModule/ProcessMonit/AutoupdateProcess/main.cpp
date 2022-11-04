#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CInterAction.h"

int main(int argc, char *argv[])
{
    setvbuf(stdout, (char *)NULL, _IONBF, 0);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    CInterAction interaction;
    engine.rootContext()->setContextProperty( "CInterAction", &interaction );


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
