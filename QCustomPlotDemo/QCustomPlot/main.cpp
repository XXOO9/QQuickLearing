#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>
#include <QOpenGLContext>
#include "./BasesicPlot/CBasesicPlot.h"
#include "./BasesicPlot/MultiPlot.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QOpenGLContext *glContext = QOpenGLContext::currentContext();
    if (glContext) {
        qDebug() << "OpenGL rendering is enabled";
    } else {
        qDebug() << "OpenGL rendering is not enabled";
    }

    qmlRegisterType<CBasesicPlot>( "CustPlot", 1, 0, "CustPlotItem" );
    qmlRegisterType<MultiPlot>( "CustPlotMulti", 1, 0, "CustPlotItemMulti" );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
