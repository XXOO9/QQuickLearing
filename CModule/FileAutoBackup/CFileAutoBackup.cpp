#include "CFileAutoBackup.h"

CFileAutoBackup::CFileAutoBackup(const QString &backupDir, QObject *parent)
{
    qDebug() << "exe dir = " << QCoreApplication::applicationDirPath();
    m_backupDir = translatePath( backupDir );

    isExisted( backupDir, true );
    init();

//    deleteDir( "../srcDir" );
    test();
}

CFileAutoBackup::~CFileAutoBackup()
{

}

bool CFileAutoBackup::isExisted(const QString &path, bool create)
{
    bool ok = QFileInfo::exists( path );

    //如果不存在并且需要创建
    if( !ok && create ){
        QDir dir;
        return dir.mkpath( path );
    }

    return ok;
}

void CFileAutoBackup::test()
{
//    copyDir( "../srcDir/", "../backup/" );
    QString path = "../srcDir";

    appendMonitorPath( path );

    QString filePath = "../1.txt";
    appendMonitorFile( filePath );
}

void CFileAutoBackup::appendMonitorPath(QString &path)
{
    path = translatePath( path );
    bool ok = m_sysFileWatcher.addPath( path );
    if( !ok ){
        qDebug() << "monitor failed...";
        return;
    }
    m_monitPaths.append( path );
    qDebug( "monitor %1 success...", path );

}

void CFileAutoBackup::appendMonitorFile(QString &filePath)
{
    filePath = translatePath( filePath );
    bool ok = m_sysFileWatcher.addPath( filePath );
    if( !ok ){
        qDebug() << "monitor path failed...";
        return;
    }

    qDebug( "monitor %1 success...", filePath );
}

void CFileAutoBackup::copyFile(const QString &srcFile, const QString &dstFile)
{
    //先检查文件是否存在, 如果存在则直接删除
    bool ok = QFileInfo::exists( dstFile );
    if( ok ){
        qDebug() << "file is already exist, going to remove it...";
        QFile::remove( dstFile );
    }
    ok = QFile::copy( srcFile, dstFile );
    if( !ok ){
        qDebug() << "copy file failed...";
        return;
    }

    qDebug() << "copy file ok...";
}

void CFileAutoBackup::copyDir(const QString &srcDir, const QString &dstDir)
{
    QDir dir( srcDir );
    isExisted( dstDir + "/" + dir.dirName(), true );
    QString tmplate = "%1/%2";
    QString dstFilePath = "";
    qDebug() << dir.dirName();
    QFileInfoList fileInfoList = dir.entryInfoList( QDir::Dirs | QDir::Files | QDir::NoDot | QDir::NoDotAndDotDot );
    foreach (auto &ele, fileInfoList) {
        //如果是文件夹,则开始递归
        dstFilePath = tmplate.arg( dstDir ).arg( ele.fileName() );
        qDebug() << dstFilePath;
        if( ele.isDir() ){
            copyDir( ele.filePath(), dstFilePath );
            continue;
        }
        QFile::copy( ele.filePath(), dstFilePath );
    }
}

void CFileAutoBackup::deleteDir(const QString &dirPath)
{
    qDebug() << "dst dir path = " << dirPath;
    QDir dir( dirPath );
    QFileInfoList fileInfos = dir.entryInfoList( QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot );

    foreach (auto &ele, fileInfos) {
        if( ele.isFile() ){
            QFile::remove( ele.absoluteFilePath() );
        }

        if( ele.isDir() ){
            qDebug() << "dir name = " << ele.fileName();
            deleteDir( ele.absolutePath() + "/" + ele.fileName() );
        }
    }

    if( dir.isEmpty() ){
        dir.rmpath( dirPath );
    }
}

void CFileAutoBackup::init()
{
    initConnection();
}

void CFileAutoBackup::initConnection()
{
    connect( &m_sysFileWatcher, &QFileSystemWatcher::directoryChanged, this, &CFileAutoBackup::onDirContentChanged );
    connect( &m_sysFileWatcher, &QFileSystemWatcher::fileChanged, this, &CFileAutoBackup::onFileChanged );
}

void CFileAutoBackup::createBackupDir(const QString &dstPath)
{
    //如果备份路径不存在，则创建
    if( !QFileInfo::exists( dstPath ) ){

    }
}

QStringList CFileAutoBackup::getSpecificDirFileList( const QString &path )
{
    QDir dir( path );
//    QFileInfoList fileInfos = dir.entryInfoList( QDir::Dirs | QDir::Files | QDir::NoDot | QDir::NoDotDot);

    QStringList fileInfos = dir.entryList( QDir::Dirs | QDir::Files | QDir::NoDot | QDir::NoDotDot);
    return fileInfos;
}

QString CFileAutoBackup::translatePath(const QString &path)
{
    QDir dir( path );
    //相对路径转绝对路径
    if( dir.isRelative() ){
        return dir.absolutePath();
    }

    return "";
}

QVector<CDifferFile> CFileAutoBackup::compareFileInfos(const QString &rootMonitPath, const QStringList &monitPath, const QStringList &backupPath )
{
    CDifferFile tmpDifferFile;
    QVector<CDifferFile> vecDifferFiles;
    QFileInfo tmpFileInfo;
    QString tmpPath;
    QString templateString = QString( "%1/%2" );

    //用变动后的文件列表去对比备份的文件列表 以获取新添加的文件
    foreach (auto &ele, monitPath) {
        if( !backupPath.contains( ele ) ){
            tmpDifferFile.m_flag = true;

            //判断是文件还是路径
            tmpPath = templateString.arg( rootMonitPath ).arg( ele );
            tmpFileInfo.setFile( tmpPath );
            if( tmpFileInfo.isDir() ){
                tmpDifferFile.m_isDir = true;
            }else{
                tmpDifferFile.m_isDir = false;
            }

            tmpDifferFile.m_name = ele;
            tmpDifferFile.m_path = rootMonitPath + "/" + ele;
            vecDifferFiles << tmpDifferFile;
        }
    }

    //用变动后的备份列表去对比变动后的监测文件列表 以获取已经删除添加的文件
    foreach (auto &ele, backupPath) {
        if( !monitPath.contains( ele ) ){
            tmpDifferFile.m_flag = false;

            //判断是文件还是路径
            tmpPath = templateString.arg( m_backupDir ).arg( ele );
            tmpFileInfo.setFile( tmpPath );
            if( tmpFileInfo.isDir() ){
                tmpDifferFile.m_isDir = true;
            }else{
                tmpDifferFile.m_isDir = false;
            }

            tmpDifferFile.m_name = ele;
            tmpDifferFile.m_path = m_backupDir + "/" + ele;
            vecDifferFiles << tmpDifferFile;
        }
    }

    return vecDifferFiles;
}

void CFileAutoBackup::dirFilesChangedHandler(QVector<CDifferFile> &vecDifferFiles)
{
    CDifferFile tmpFile;
    for( int i = 0; i < vecDifferFiles.size(); i++ ){
        tmpFile = vecDifferFiles.at( i );

        //如果是新增
        if( tmpFile.m_flag ){
            //新增的是文件
            if( !tmpFile.m_isDir ){
                copyFile( tmpFile.m_path, m_backupDir + "/" + tmpFile.m_name );
            }else{
                copyDir( tmpFile.m_path, m_backupDir + "/" + tmpFile.m_name );
            }
        }

        //如果是删除文件
        else{
            if( !tmpFile.m_isDir ){
                bool ok = QFile::remove( tmpFile.m_path );
                qDebug() << "ret = " << ok;
            }
            else{
                deleteDir( m_backupDir + "/" + tmpFile.m_name );
            }
        }
    }
}

void CFileAutoBackup::onDirContentChanged(const QString &dirPath)
{
    //检测到文件夹有变动（一般是增加或者减少文件），
    qDebug() << "dir chanegd, dirpath = " << dirPath;

    //获取变动后备份路径下的文件列表
    QStringList backupPathFileInfoList = getSpecificDirFileList( m_backupDir );

    //获取变动后该路径下的文件列表
    QStringList monitPathInfoList = getSpecificDirFileList( dirPath );

    QVector<CDifferFile> vecDifferFiles = compareFileInfos( dirPath, monitPathInfoList, backupPathFileInfoList );

    dirFilesChangedHandler( vecDifferFiles );
}

void CFileAutoBackup::onFileChanged(const QString &filePath)
{
    QFileInfo fileInfo( filePath );
    copyFile( filePath, m_backupDir + "/" + fileInfo.fileName() );
    qDebug() << "file chanegd, file path = " << filePath;
}
