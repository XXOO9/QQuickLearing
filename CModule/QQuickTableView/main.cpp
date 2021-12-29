#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include "CustTableModel.h"
#include "CDataModel.h"
#include <QHash>
#include <QQmlContext>
#include <QDebug>

//using namespace DataModel;

void testFunc( CDataModel &dataModel )
{
    QHash<ColumnIndex, QString> rets;
    rets[RowUnique]    = "339";
    rets[Check]        = "666";
    rets[FirstColumn]  = "first";
    rets[SecondColumn] = "second";
    rets[ThirdColumn]  = "third";
    rets[ForthColumn]  = "forth";
    rets[FifthColumn]  = "fifth";
    rets[SixthColumn]  = "sixth";
    rets[seventhColumn]  = "seventh";
    rets[eigthColumn]  = "eight";
    dataModel.appendRow( rets );
}



int main(int argc, char *argv[])
{
    CDataModel tableModel;
    testFunc( tableModel );
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<CDataModel>( "com.TME.CAbstractTableModel", 1, 0, "TABLE" );

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty( "tableModel", &tableModel );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
