#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QQmlContext>

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

    QStringList Suggestions;

    Suggestions << "马孝权";
    Suggestions << "陈鹏程";
    Suggestions << "孙伟";
    Suggestions << "谢映";
    Suggestions << "陈磊";
    Suggestions << "吴世洲";
    Suggestions << "张三";
    Suggestions << "李四";
    Suggestions << "Oran6";

    QStringListModel SuggestionModel;
    SuggestionModel.setStringList( Suggestions);

    QSortFilterProxyModel ProxyModel;
    ProxyModel.setSourceModel(&SuggestionModel);
    ProxyModel.setFilterCaseSensitivity(Qt::CaseInsensitive);

    //按第一列排序
    ProxyModel.sort(0);
    engine.rootContext()->setContextProperty( "SuggestionsModel", &ProxyModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
