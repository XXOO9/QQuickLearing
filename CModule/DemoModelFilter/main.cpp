#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QQmlContext>
#include <QStringList>
#include <QDebug>
#include <QElapsedTimer>
#include "CModelDataFilter.h"
#include "CModelUserSelect.h"
#include "CInteraction.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    CInteraction interaction;
    interaction.setEnigne( &engine );
    engine.rootContext()->setContextProperty( "InterAction", &interaction );

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
