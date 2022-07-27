#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QDebug>

void testCallQmlFunc( QQmlApplicationEngine &engine )
{
    QObject *pRoot = engine.rootObjects().first();

    QObject *targetComponent = pRoot->findChild<QObject*>( "someFuncs" );
    QVariant qmlFuncRet;
    bool ret = QMetaObject::invokeMethod( targetComponent, "display",
                                          Qt::AutoConnection,
                                          Q_RETURN_ARG( QVariant, qmlFuncRet ),
                                          Q_ARG( QVariant, "WDNMD" ) );

    qDebug() << "ret = " << ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    testCallQmlFunc( engine );

    return app.exec();
}
