#include <QFile>
#include <QGuiApplication>
#include <QDebug>
#include <QMutex>
#include <QQmlApplicationEngine>
#include <QTextStream>
#include <QTextCodec>
#include "QLog.h"


void cusMessageOutHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    QMutexLocker locker( &mutex );

    QString text = "";
    switch (type) {
    case QtMsgType::QtDebugMsg:
        text = QString( "Debug::" );
        break;

    case QtMsgType::QtWarningMsg:
        text = QString( "Waring::" );
        break;

    case QtMsgType::QtCriticalMsg:
        text = QString( "Critical::" );
        break;

    case QtMsgType::QtFatalMsg:
        text = QString( "Fatal::" );
        break;
    default:
        text = QString( "Debug::" );
        break;
    }

    // 设置输出信息格式
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(current_date).arg(text).arg(context_info).arg(msg);

    // 输出信息至文件中（读写、追加形式）
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
}

void setLcoalTextCodec()
{
    QTextCodec *pCodec = QTextCodec::codecForName( "utf-8" );
    QTextCodec::setCodecForLocale( pCodec );
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler( cusMessageOutHandler );

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    setLcoalTextCodec();

    QLog j;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    qDebug() << "WDNMD";

    return app.exec();
}
