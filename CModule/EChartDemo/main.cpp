#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>

void test()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    QVector<int> vecInt;
    vecInt << a << b << c << d;

    for( auto &each: vecInt) {
        each = a;
    }
    qDebug() << "ret = " << vecInt;
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QtWebEngine::initialize();

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
