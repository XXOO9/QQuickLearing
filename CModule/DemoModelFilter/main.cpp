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

void testQStringList()
{
    QStringList list;
    QElapsedTimer timer;

    timer.start();

    for( int i = 0; i < 10; i++ ){
        list << "this is number:: " + QString::number( i );
    }

    qDebug() << "load cost = " << timer.restart();

    qDebug() << "index = " << list.indexOf( "this is number:: 99999" );

    qDebug() << "cost 1 = " << timer.restart();

    qDebug() << "index = " << list.indexOf( "this is number:: 50000" );

    qDebug() << "cost 1 = " << timer.elapsed();
}

QSortFilterProxyModel* initFilterModel()
{
    QStringList Suggestions;
    Suggestions << "Blue";
    Suggestions << "Red";
    Suggestions << "Orange";
    Suggestions << "Ass";
    Suggestions << "Apple";
    Suggestions << "Apple1";
    Suggestions << "Apple2";
    Suggestions << "Oran";
    Suggestions << "Oran6";

    QStringListModel SuggestionModel;
    SuggestionModel.setStringList(Suggestions);

    QSortFilterProxyModel *ProxyModel = new QSortFilterProxyModel();
    ProxyModel->setSourceModel( &SuggestionModel );
    ProxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ProxyModel->sort( 0 );

    return ProxyModel;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    CModelDataFilter a;
    CModelUserSelect b;

    testQStringList();

    engine.rootContext()->setContextProperty( "SuggestionsModel", a.m_proxyModel );
    engine.rootContext()->setContextProperty( "CModelUserSelect", &b );

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
