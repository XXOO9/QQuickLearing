#include "CInterAction.h"

#include <QFileInfoList>

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{
    init();
    qInfo( "qinfo" );
    qWarning( "qwaring" );
}

void CInterAction::init()
{
    m_targetExeFilePath = QCoreApplication::applicationDirPath() + '/' + Keys::targetExecuteName;
    m_newFileDir = QCoreApplication::applicationDirPath() + Keys::updateFolderName;
    checkUpdateDirExisted( m_newFileDir );
}

void CInterAction::closeTargetProcess(const QString &targetExecuteName)
{
    if( isTargetProcessRunning( targetExecuteName ) ){
        //关闭进程
        QProcess tmpProcess;
        tmpProcess.start( "taskkill /im " + targetExecuteName );
        tmpProcess.waitForFinished( 3000 );

        return;
    }
}

bool CInterAction::checkExistedUpdateFiles()
{
    QDir dir( m_newFileDir );

    if( dir.count() < 2 ){
        qDebug() << "no update files...";
        return false;
    }else{
        qDebug() << dir.count() << " update files...";
        return true;
    }
}

void CInterAction::closeProcess()
{
    closeTargetProcess( Keys::targetExecuteName );
}

void CInterAction::copyNewExecuteToTargetDir(const QString targetDir, bool delAfterFinished)
{
//    checkUpdateDirExisted( targetDir );

    closeTargetProcess( Keys::targetExecuteName );

    QThread::msleep( 1000 );

    QDir updateFileDir( m_newFileDir );
    qDebug() << "whole dir = " << updateFileDir.absolutePath();
    QFileInfoList infoList = updateFileDir.entryInfoList( QStringList() << "*.exe" << "*.dll" );


    for( auto &ele : infoList ){
        qDebug() << "file name = " << ele.fileName();

        waitDeleteFinished( targetDir + ele.fileName() );

        bool ok1 = QFile::copy( ele.filePath(), targetDir + ele.fileName() );
        qDebug() << "copy ret = " << ok1;
    }
}

bool CInterAction::isTargetProcessRunning(const QString &executeName)
{
    QString retString = queryRunningProcess();

    if( retString.contains( executeName ) ){
        return true;
    }

    return false;
}

void CInterAction::waitDeleteFinished(const QString &targetDelFilePath)
{
    QTimer tmpQueryTimer;
    tmpQueryTimer.setInterval( 500 );
    QEventLoop *loop = new QEventLoop();

    connect( &tmpQueryTimer, &QTimer::timeout, [ = ](){
        if( !QFileInfo::exists( targetDelFilePath ) ){
            qDebug() << QString::fromLocal8Bit( "不在了..." );
            cout << "cout -> 不在了..." << endl;
            loop->quit();
            return;
        }

        qDebug() << QString::fromLocal8Bit( "还在" );
        cout << "cout -> 还在..." << endl;
    });

    bool ok = QFile::remove( targetDelFilePath );

    //如果没有删除成功，则直接返回
    if( !ok ){
        return;
    }

    tmpQueryTimer.start();

    //如果删除成功, 文件可能比较大, 删除需要一定的时间， 开启事件循环，直到完成删除操作
    loop->exec();
    loop->deleteLater();
    loop = nullptr;
    qDebug() << "del finished...";
}

void CInterAction::runTargetProcess()
{
    bool ok = QProcess::startDetached( m_targetExeFilePath );
}

bool CInterAction::isTargetProcessRunning()
{
    return true;
}

void CInterAction::checkUpdateDirExisted(const QString &dirPath)
{
    QDir tmpDir( dirPath );
    if( !tmpDir.exists() ){
        cout << "folder to store update files is not existed, going to create it..." << endl;
        bool ok = tmpDir.mkdir( dirPath );
        cout << "create update folder ret = " << ok << endl;
    }else{
        cout << "folder to store new files has existed..." << endl;
    }

}

QString CInterAction::queryRunningProcess()
{
    QProcess tmpProcess;
    tmpProcess.start( "tasklist" );
    tmpProcess.waitForFinished( 1000 );
    QString ret = QString::fromLocal8Bit( tmpProcess.readAllStandardOutput() );

//    qDebug() << "recv standard str = " << ret;

    return ret;
}


