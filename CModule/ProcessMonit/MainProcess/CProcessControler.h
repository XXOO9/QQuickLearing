#ifndef CPROCESSCONTROLER_H
#define CPROCESSCONTROLER_H

#include <QProcess>
#include <QDebug>
#include <QCoreApplication>

namespace Keys {
    const QString updateProcessName = "AutoupdateProcess.exe";
}



class CProcessControler : public QObject
{
public:
    CProcessControler( QObject *parent = nullptr );
    virtual ~CProcessControler() override;

    void test();

    //以分离形式调用一个新的进程， 调用进程与目标进程互不干扰
    void runDetachedUpdateProcess();

    //以子进程的方式打开一个新的进程，  调用进程为父进程， 父进程退出时，子进程随之退出
    void runChildProcess();
    QString m_exeDir = "";

protected slots:
    void onReadyReadStanardOutput();

private:
    void init();
    void initConnection();
    bool isUpdateProcessRunning() const;

private:
    QProcess m_childProcess;
};

#endif // CPROCESSCONTROLER_H
