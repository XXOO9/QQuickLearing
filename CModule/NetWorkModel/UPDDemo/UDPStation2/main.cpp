#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "CUPDStation.h"
#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CUPDStation a;

    engine.rootContext()->setContextProperty( "UDP", &a );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    double b = 3.0000000000000000001;
    qDebug() << QString::number( b, 'f', 2 ).toDouble();


    return app.exec();
}
