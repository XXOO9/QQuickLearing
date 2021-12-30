#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CDataModel.h"
#include "CAbstractTableModel.h"

void testFunc( CAbstractTableModel &dataModel )
{
////    QHash<CDataModel::ColumnIndex, CUnitData> ret;
//    QStringList row;
//    row << "fior"

}

int main(int argc, char *argv[])
{

    CAbstractTableModel DataModel(5);
//    DataModel.testfunc1();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<CDataModel>( "com.TME.CDataModel", 1, 0, "CDataModel" );


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty( "Model", &DataModel );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
