#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>
#include "./BasesicPlot/CBasesicPlot.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;\

    qmlRegisterType<CBasesicPlot>( "CustPlot", 1, 0, "CustPlotItem" );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
