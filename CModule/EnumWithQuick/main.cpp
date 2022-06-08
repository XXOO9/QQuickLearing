#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "CInteraction.h"
#include "CProjectEnums.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    int i = qmlRegisterType<CProjectEnums> ( "com.MyCompany.Enum", 1, 0, "CPPENUM" );
    qDebug() << "i = " << i;

    QQmlApplicationEngine engine;
    CInteraction inter;
    engine.rootContext()->setContextProperty( "CInteraction",  &inter );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
