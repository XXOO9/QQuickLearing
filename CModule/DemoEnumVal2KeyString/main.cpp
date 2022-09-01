#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CEnumClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CEnumClass a;

    //将枚举注册进qml
    qmlRegisterUncreatableMetaObject( CEnumClass::staticMetaObject, "MyEnums", 1, 0, "MyEnums", "ErrorMsg:: only enums..." );

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
