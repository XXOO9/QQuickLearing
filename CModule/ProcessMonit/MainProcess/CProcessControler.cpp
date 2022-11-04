#include "CProcessControler.h"

CProcessControler::CProcessControler(QObject *parent) : QObject( parent )
{
    init();
    test();
}

CProcessControler::~CProcessControler()
{

}

void CProcessControler::test()
{
    if( isUpdateProcessRunning() ){
        qDebug() << "autp update process is running...";
        return;
    }

    runDetachedUpdateProcess();
}

void CProcessControler::runDetachedUpdateProcess()
{
    QProcess updateProcess;
    bool ok = QProcess::startDetached( m_exeDir + "/" + Keys::updateProcessName );
    qDebug() << "run update process in detach way...";
}

void CProcessControler::runChildProcess()
{
    m_childProcess.start( m_exeDir + "/" + Keys::updateProcessName );
    m_childProcess.setReadChannel( QProcess::StandardOutput );
}

void CProcessControler::onReadyReadStanardOutput()
{
    QString standardOut = QString::fromLocal8Bit( m_childProcess.readAll() );
    qDebug() << "child output = " << standardOut;
}

void CProcessControler::init()
{
    m_exeDir = QCoreApplication::applicationDirPath();
    initConnection();
}

void CProcessControler::initConnection()
{
    connect( &m_childProcess, &QProcess::readyRead, this, &CProcessControler::onReadyReadStanardOutput );
}

bool CProcessControler::isUpdateProcessRunning() const
{
    QProcess tmpProcess;
    tmpProcess.start( "tasklist" );
    tmpProcess.waitForFinished( 1000 );

    QString retString = QString::fromLocal8Bit( tmpProcess.readAllStandardOutput() );

    if( retString.contains( Keys::updateProcessName ) ){
        return true;
    }

    return false;
}
