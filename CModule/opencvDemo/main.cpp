﻿#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CCameraControler.h"
#include "CInterAction.h"
#include "CVideoFrameProvider.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    CInterAction a;

    QQmlApplicationEngine engine;

    qmlRegisterType<CVideoFrameProvider>( "videoFrameProvider", 1, 0, "FrameProvider" );

    engine.rootContext()->setContextProperty( "InterAction", &a );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
