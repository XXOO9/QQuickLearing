#ifndef CFILEAUTOBACKUP_H
#define CFILEAUTOBACKUP_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QFileSystemWatcher>
#include <QCoreApplication>
#include <QDir>
#include <QDateTime>
#include <QTimer>

/*设计目的：
 * 1.自动备份目标目录和文件
 * 2.
 *
 *
 * 设计思路：
 * 1.创建备份文件夹
 * 1.首先设置需要监控的目录和文件
 * 2.当目录或者文件发生变动时，将备份文件夹里面的旧文件删除，再将新的文件复制进备份文件夹
 *
*/
class CDifferFile;
class CFileAutoBackup : public QObject
{
    Q_OBJECT
    enum BackupPolicy{
        AutoDetectedChange = 0,
        ManualOnceRunning
    };

public:
    static bool isExisted( const QString &path, bool create = false );

public:
    Q_INVOKABLE void appendPath( QString path );
    Q_INVOKABLE void appendFile( QString filePath );
    Q_INVOKABLE void manualBackup();

public:
    CFileAutoBackup( const QString &backupDir = "../backup", const BackupPolicy &policy = ManualOnceRunning, QObject *parent = nullptr );
    virtual  ~CFileAutoBackup() override;

    void startBackup();

    void appendMonitorPath( QString &path );
    void appendMonitorFile( QString &filePath );

    CFileAutoBackup::BackupPolicy getBackupPolicy() const;
    void setBackupPolicy(const BackupPolicy &backupPolicy);

    QString getBackupDir() const;
    void setBackupDir(const QString &backupDir);

private:
    //文件操作
    //备份单个文件
    void copyFile( const QString &srcFile, const QString &dstFile );

    //备份单个文件夹
    void copyDir( const QString &srcDir, const QString &dstDir );

    //删除单个文件夹
    void deleteDir( const QString &dirPath );

private:
    void test();

private:
    void init();
    void initConnection();

    QStringList getSpecificDirFileList(const QString &path);
    QString translatePath( const QString &path );
    QVector<CDifferFile> compareFileInfos(const QString &rootMonitPath, const QStringList &monitPath, const QStringList &backupPath);
    void dirFilesChangedHandler( QVector<CDifferFile> &vecDifferFiles );
    inline QString getFileRecentlyChangedTime( const QString &filePath );
    bool isSpecificFileChanged( const QString &filePath );


private slots:
    void onDirContentChanged( const QString &dirPath );
    void onFileChanged( const QString &filePath );

private:
    QFileSystemWatcher          m_sysFileWatcher;
    QString                     m_backupDir = "";
    BackupPolicy                m_backupPolicy = BackupPolicy::AutoDetectedChange;
    QStringList                 m_monitPaths;
    QMap<QString, QString>      m_mapFileChangeTimeStamp;
};

class CDifferFile{
public:
    bool     m_flag = false; // true标记为新增的文件
    bool     m_isDir = false;
    QString  m_path = "";
    QString  m_name = "";
};

#endif // CFILEAUTOBACKUP_H
