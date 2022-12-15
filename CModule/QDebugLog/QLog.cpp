#include "QLog.h"

#include <QTextStream>

QLog::QLog()
{
    init();
}

void QLog::init()
{
//    qInstallMessageHandler( myMessageHandler );
    qDebug() << "这个是QLogaisbdfiasbf";
}

void QLog::myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMutexLocker locker( &m_mutex );

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
   QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

   // 输出信息至文件中（读写、追加形式）
   QFile file("log.txt");
   file.open(QIODevice::WriteOnly | QIODevice::Append);
   QTextStream text_stream(&file);
   text_stream << message << "\r\n";
   file.flush();
   file.close();
}
