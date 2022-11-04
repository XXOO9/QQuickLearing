#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QDir>
#include <iostream>
#include <QProcess>
#include <QCoreApplication>
#include "CFileCopy.h"



namespace Keys {
    const QString updateFolderName = "/update";
    const QString targetExecuteName = "MainProcess.exe";
}


using namespace std;
class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    //检查是否有更新文件
    Q_INVOKABLE bool checkExistedUpdateFiles();

    Q_INVOKABLE void closeProcess();

    //将需要更新的文件复制到目标路径
    Q_INVOKABLE void copyNewExecuteToTargetDir( const QString targetDir, bool delAfterFinished = true );


    //替换完成后，启动新版进程
    Q_INVOKABLE void runTargetProcess();

public:


public:
    static void checkUpdateDirExisted( const QString &dirPath );


private:
    void init();
    void closeTargetProcess( const QString &targetExecuteName );
    QString queryRunningProcess();
    bool isTargetProcessRunning( const QString &executeName );

    void waitDeleteFinished( const QString &targetDelFilePath );



private:
    QString     m_newFileDir = "";
    QString     m_targetExeFilePath = "";

};

#endif // CINTERACTION_H
