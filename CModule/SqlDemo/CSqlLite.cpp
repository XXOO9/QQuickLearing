#include "CSqlLite.h"

CSqlLite::CSqlLite(QObject *parent) : QObject(parent)
{
    initDataBase();
}

void CSqlLite::initDataBase()
{
    m_dataBase = QSqlDatabase::addDatabase( "QSQLITE" );
    qDebug() << "ret = " << m_dataBase.isValid();
    m_dataBase.setDatabaseName( "demo.db" );
    if( !m_dataBase.open() ){
        qDebug() << "Error::failed to open database, errorstring is::" << m_dataBase.lastError();
    }

    qDebug() << "Successd to open dataBase...";
}
