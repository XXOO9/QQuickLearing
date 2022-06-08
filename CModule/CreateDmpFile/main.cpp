#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QApplication>
#include <QDateTime>
#include <QTextCodec>

#include "CTestMgr.h"

#ifdef Q_OS_WIN
#include <windows.h>
#include <dbghelp.h>
#endif

static LONG WINAPI exceptionCallback(struct _EXCEPTION_POINTERS* exceptionInfo)
{
    QCoreApplication *app = QApplication::instance();

    QString savePath = app->applicationDirPath() + "/";
    qDebug()<<"save path :"<<savePath;
    QDir dir(savePath);
    if (!dir.exists() && !dir.mkpath(savePath)) {
        app->exit(E_UNEXPECTED);
        return EXCEPTION_EXECUTE_HANDLER;
    }
    QString curTime = QDateTime::currentDateTime().toString("yyyy_MM_dd hh_mm_ss_zzz");
    qDebug() << "time = " << curTime;
    QString fileName = savePath + "DemoCreateDmp" + curTime + QString(".dmp");
    qDebug() << "save path = " << savePath;


    QString tmpFileName = QString::fromUtf8( fileName.toUtf8() );
    qDebug() << "tmpFileName name = " << tmpFileName;

    HANDLE dump = CreateFileW(tmpFileName.toStdWString().c_str(), GENERIC_WRITE,
                              0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == dump) {
        app->exit(E_UNEXPECTED);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    MINIDUMP_EXCEPTION_INFORMATION miniDumpExceptionInfo;
    miniDumpExceptionInfo.ExceptionPointers = exceptionInfo;
    miniDumpExceptionInfo.ThreadId = GetCurrentThreadId();
    miniDumpExceptionInfo.ClientPointers = TRUE;
    DWORD idProcess = GetCurrentProcessId();
    MiniDumpWriteDump(GetCurrentProcess(), idProcess, dump,
                      MiniDumpNormal, &miniDumpExceptionInfo, NULL, NULL);

    CloseHandle(dump);

    app->exit(E_UNEXPECTED);
    return EXCEPTION_EXECUTE_HANDLER;
}





int main(int argc, char *argv[])
{

#ifdef Q_OS_WIN
    SetUnhandledExceptionFilter(exceptionCallback);
#endif

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//或者"GBK",不分大小写
    QTextCodec::setCodecForLocale(codec);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    CTestMgr a;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty( "InterAction", &a );
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
