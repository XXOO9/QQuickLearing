#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CInterAction.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CInterAction a;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty( "InterAction", &a );
    engine.rootContext()->setContextProperty( "CusDateModel", a.dateMdoel() );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
