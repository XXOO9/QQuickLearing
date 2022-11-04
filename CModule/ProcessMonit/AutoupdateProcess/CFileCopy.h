#ifndef CFILECOPY_H
#define CFILECOPY_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

const qint64 perMaxReadSize = 1024 * 1024;
const qint64 perMaxFileSize = 1024 * 1024 * 550;

class CFileCopy : public QObject
{
    Q_OBJECT
public:
    explicit CFileCopy(QObject *parent = nullptr);
    virtual ~CFileCopy() override;

    void copy( const QString &srcFilePath, const QString &targetFilePath );

private:
    void init();
    void resetFilePtr();
private:
    QFile   *m_pFile = nullptr;
};

#endif // CFILECOPY_H
