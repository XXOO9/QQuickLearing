#include "CFileAutoBackup.h"

CFileAutoBackup::CFileAutoBackup(const QString &backupDir, const BackupPolicy &policy, QObject *parent)
{
    qDebug() << "exe dir = " << QCoreApplication::applicationDirPath();

    m_backupDir = translatePath( backupDir );
    setBackupPolicy( AutoDetectedChange );
    isExisted( backupDir, true );

    init();

//    test();
    //    startBackup();
}

CFileAutoBackup::~CFileAutoBackup()
{

}

void CFileAutoBackup::startBackup()
{
    QFileInfo tmpFileInfo;
    foreach (auto &ele, m_monitPaths) {

        tmpFileInfo.setFile( ele );

        //如果是文件夹，则直接对比文件差异
        if( tmpFileInfo.isDir() ){
            onDirContentChanged( ele );
        }

        //如果是文件，则对比修改时间是否一致
        if( tmpFileInfo.isFile() ){
            if( isSpecificFileChanged( ele ) ){
                onFileChanged( ele );
            }
        }
    }
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

void CFileAutoBackup::appendPath(QString path)
{
    appendMonitorPath( path );
}

void CFileAutoBackup::appendFile(QString filePath)
{
    appendMonitorFile( filePath );
}

void CFileAutoBackup::manualBackup()
{
    startBackup();
}

void CFileAutoBackup::test()
{
    QString path = "../srcDir";
    appendMonitorPath( path );

    QString filePath = "../1.txt";
    appendMonitorFile( filePath );

}

void CFileAutoBackup::appendMonitorPath(QString &path)
{
    QDir dir( path );
    if( dir.isRelative() ){
        path = translatePath( path );
    }

    bool ok = m_sysFileWatcher.addPath( path );
    if( !ok ){
        qDebug() << "monitor failed...";
        return;
    }

    m_monitPaths.append( path );
    qDebug() << "success monit path " << path;
}

void CFileAutoBackup::appendMonitorFile(QString &filePath)
{
    QDir dir( filePath );
    if( dir.isRelative() ){
        filePath = translatePath( filePath );
    }

    bool ok = m_sysFileWatcher.addPath( filePath );
    if( !ok ){
        qDebug() << "monitor path failed...";
        return;
    }
    m_monitPaths.append( filePath );
    m_mapFileChangeTimeStamp.insert( filePath, getFileRecentlyChangedTime( filePath ) );
    qDebug() << "success monit file " << filePath;
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
        qDebug() << "copy file failed, src = " << srcFile;
        return;
    }

    qDebug() << "copy file ok...";
}

void CFileAutoBackup::copyDir(const QString &srcDir, const QString &dstDir)
{
    qDebug() << "going to copy dir " << srcDir << " to " << dstDir;
    //如果目标文件夹不存在，则创建
    QDir dir( srcDir );
//    isExisted( dstDir + "/" + dir.dirName(), true );
    isExisted( dstDir, true );

    QString tmplate = "%1/%2";
    QString dstFilePath = "";

    qDebug() << "src dir name" << dir.path();

    //获取文件列表前延时500ms,防止太快读不出文件列表信息
    QEventLoop eveLoop;
    QTimer::singleShot( 200, &eveLoop, &QEventLoop::quit );
    eveLoop.exec();
    QFileInfoList fileInfoList = dir.entryInfoList( QDir::Dirs | QDir::Files | QDir::NoDot | QDir::NoDotAndDotDot );
    qDebug() << "size = " << fileInfoList.size();

    foreach (auto &ele, fileInfoList) {
        qDebug() << "WDNMD";
        //如果是文件夹,则开始递归
        dstFilePath = tmplate.arg( dstDir ).arg( ele.fileName() );
        qDebug() << dstFilePath;
        if( ele.isDir() ){
            copyDir( ele.filePath(), dstFilePath );
            continue;
        }

        //如果是文件,则直接复制到目标路径下
        bool ok = QFile::copy( ele.filePath(), dstFilePath );
        QString logIngo = QString( "copy file %1, src path: %2, dst path: %3" );
        qDebug() << logIngo.arg( ok ).arg( ele.filePath() ).arg( dstFilePath );
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

}

void CFileAutoBackup::initConnection()
{
    connect( &m_sysFileWatcher, &QFileSystemWatcher::directoryChanged, this, &CFileAutoBackup::onDirContentChanged );
    connect( &m_sysFileWatcher, &QFileSystemWatcher::fileChanged, this, &CFileAutoBackup::onFileChanged );
}

QStringList CFileAutoBackup::getSpecificDirFileList( const QString &path )
{
    QDir dir( path );
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

QString CFileAutoBackup::getFileRecentlyChangedTime(const QString &filePath)
{
    QFileInfo fileInfo( filePath );
    return fileInfo.fileTime( QFileDevice::FileModificationTime ).toString( "yyyy-MM-dd_hh:mm:ss" );
}

bool CFileAutoBackup::isSpecificFileChanged(const QString &filePath)
{
    if( m_mapFileChangeTimeStamp.contains( filePath ) ){
        QString curChangedTime = getFileRecentlyChangedTime( filePath );

        if( curChangedTime == m_mapFileChangeTimeStamp.value( filePath ) ){
            return false;
        }else{
            return true;
        }
    }

    //如果没有监测这个文件，则直接返回false
    return false;
}

void CFileAutoBackup::onDirContentChanged(const QString &dirPath)
{
    //检测到文件夹有变动（一般是增加或者减少文件），
    qDebug() << "dir content chanegd, dirpath = " << dirPath;

    //获取变动后备份路径下的文件列表
    QStringList backupPathFileInfoList = getSpecificDirFileList( m_backupDir );

    //获取变动后该路径下的文件列表
    QStringList monitPathInfoList = getSpecificDirFileList( dirPath );

    //对比备份路径与监测路径下的文件信息，以监测路径下的文件信息为依据获取备份路径下需要新增或删除的文件
    QVector<CDifferFile> vecDifferFiles = compareFileInfos( dirPath, monitPathInfoList, backupPathFileInfoList );

    dirFilesChangedHandler( vecDifferFiles );
}

void CFileAutoBackup::onFileChanged(const QString &filePath)
{
    QFileInfo fileInfo( filePath );
    copyFile( filePath, m_backupDir + "/" + fileInfo.fileName() );
    qDebug() << "file chanegd, file path = " << filePath;
}

QString CFileAutoBackup::getBackupDir() const
{
    return m_backupDir;
}

void CFileAutoBackup::setBackupDir(const QString &backupDir)
{
    QDir dir( backupDir );

    if( !dir.exists() ){
        return;
    }

    if( !dir.isAbsolute() ){
        m_backupDir = dir.absolutePath();
    }

    m_backupDir = backupDir;
}

CFileAutoBackup::BackupPolicy CFileAutoBackup::getBackupPolicy() const
{
    return m_backupPolicy;
}

void CFileAutoBackup::setBackupPolicy(const BackupPolicy &backupPolicy)
{
    m_backupPolicy = backupPolicy;
    if( ManualOnceRunning == m_backupPolicy ){
        disconnect( &m_sysFileWatcher, 0, 0, 0 );
    }

    if( AutoDetectedChange == m_backupPolicy ){
        initConnection();
    }
}
