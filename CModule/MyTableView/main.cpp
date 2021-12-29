#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CDataModel.h"

void testFunc( CDataModel &dataModel )
{
    QHash<CDataModel::ColumnIndex, CUnitData> ret;

    CUnitData firstColumn;
    firstColumn.setDisplayContent( "first_column" );
    firstColumn.setUnique( "first_unique" );
    firstColumn.setDataContent( "true" );

    CUnitData secondColumn;
    secondColumn.setDisplayContent( "second_column" );
    secondColumn.setUnique( "second_unique" );
    secondColumn.setDataContent( "second_data" );

    CUnitData thirdColumn;
    thirdColumn.setDisplayContent( "third_column" );
    thirdColumn.setUnique( "third_unique" );
    thirdColumn.setDataContent( "third_data" );

    CUnitData forthColumn;
    forthColumn.setDisplayContent( "forth_column" );
    forthColumn.setUnique( "forth_unique" );
    forthColumn.setDataContent( "forth_data" );

    CUnitData fifthColumn;
    fifthColumn.setDisplayContent( "fifth_column" );
    fifthColumn.setUnique( "fifth_unique" );
    fifthColumn.setDataContent( "fifth_data" );

    ret.insert( CDataModel::FirstColumn, firstColumn );
    ret.insert( CDataModel::SecondColumn, secondColumn );
    ret.insert( CDataModel::ThirdColumn, thirdColumn );
    ret.insert( CDataModel::ForthColumn, forthColumn );
    ret.insert( CDataModel::FifthColumn, fifthColumn );

    dataModel.appendRow( ret );
}

int main(int argc, char *argv[])
{
    CDataModel  dataModel;
    testFunc( dataModel );
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<CDataModel>( "com.TME.CDataModel", 1, 0, "CDataModel" );


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty( "DataModel", &dataModel );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
