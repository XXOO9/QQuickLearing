#include "CFileCopy.h"

CFileCopy::CFileCopy(QObject *parent) : QObject(parent)
{

}

CFileCopy::~CFileCopy()
{
    if( nullptr != m_pFile ){
        if( m_pFile->isOpen() ){
            m_pFile->flush();
            m_pFile->close();
        }

        delete m_pFile;
        m_pFile = nullptr;
    }
}

void CFileCopy::copy(const QString &srcFilePath, const QString &targetFilePath)
{
    resetFilePtr();
    m_pFile = new QFile( srcFilePath );

    bool ok = m_pFile->open( QIODevice::ReadOnly );

    if( !ok ){
        qDebug() << "target file open failed!!!!" << m_pFile->errorString();
        return;
    }

    qint64 fileSize = m_pFile->size();

    //如果文件大小小于 perMaxFileSize( 500 M ),直接调用QFIle::Copy
    if( fileSize < perMaxFileSize ){
        QFile::copy( srcFilePath, targetFilePath );
        return;
    }


}

void CFileCopy::init()
{

}

void CFileCopy::resetFilePtr()
{
    if( nullptr != m_pFile ){
        m_pFile->close();
        delete m_pFile;
        m_pFile = nullptr;
    }
}
