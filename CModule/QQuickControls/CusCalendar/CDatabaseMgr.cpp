#include "CDatabaseMgr.h"

CDatabaseMgr::CDatabaseMgr()
{
    initDatabase();
}

CDatabaseMgr::~CDatabaseMgr()
{
    if( m_database.isOpen() ){
        m_database.close();
    }
}

bool CDatabaseMgr::insertNewDateInfo(const QString &date, const double &hour, const double &timeCnt)
{
    QString sqlString = QString( "insert into dateInfo values(?, ?, ?)" );

    m_pSqlExecute->prepare( sqlString );
    m_pSqlExecute->addBindValue( date );
    m_pSqlExecute->addBindValue( hour );
    m_pSqlExecute->addBindValue( timeCnt );

    if( !m_pSqlExecute->exec() ){
        qDebug() << "insert new dateInfo failed, err str = " << m_pSqlExecute->lastError().text();
        return false;
    }

    return true;
}

QVariantList CDatabaseMgr::queryRangeDateInfo(const QString &startDayDate, const QString &endDayDate) const
{
    QVariantList retList;
    QString sqlString = "select * from dateInfo where date >= ? and date <= ?";

    bool ok = m_pSqlExecute->prepare( sqlString );
    m_pSqlExecute->addBindValue( startDayDate );
    m_pSqlExecute->addBindValue( endDayDate );

    if( !m_pSqlExecute->exec() ){
        qDebug() << "query target table existed failed, err str = " << m_pSqlExecute->lastError().text();
        return retList;
    }

    QVariantMap tmpRetMap;
    while( m_pSqlExecute->next() ){
        tmpRetMap.clear();
        tmpRetMap = {
            { Keys::dayIndex, m_pSqlExecute->value( DateTime ).toInt() },
            { Keys::hours, m_pSqlExecute->value( Hours ).toDouble() },
            { Keys::timeCnt, m_pSqlExecute->value( TimeCnt ).toDouble() }
        };

        retList << tmpRetMap;
//        qDebug() << "ret = " << tmpRetMap;
    }

    return retList;
}

void CDatabaseMgr::initDatabase()
{
    m_database = QSqlDatabase::addDatabase( "QSQLITE", Keys::databaseName );
    m_database.setDatabaseName( QCoreApplication::applicationDirPath() + '/' + Keys::databaseName + ".db" );

    bool ok = m_database.open();

    if( !ok ){
        qDebug() << "database opem failed!";
        return;
    }

    checkTablesExisted();
    resetSqlExecute();

    m_pSqlExecute = new QSqlQuery( m_database );
    qDebug() << "data open success...";
}

void CDatabaseMgr::initTables()
{
    const QString createDateInfoTable = "create table dateInfo( date integer primary key, hours real, timeCnt real )";
    QSqlQuery sqlCmd( m_database );
    //    sqlCmd.prepare()
    if( !sqlCmd.exec( createDateInfoTable ) ){
        qDebug() << "create table failed, error str = " << sqlCmd.lastError().text();
        return;
    }

    qDebug() << "create table success...";

}

void CDatabaseMgr::resetSqlExecute()
{
    if( nullptr != m_pSqlExecute ){
        delete m_pSqlExecute;
        m_pSqlExecute = nullptr;
    }
}

void CDatabaseMgr::checkTablesExisted()
{
    bool ok = isTargetTableExisted( "dateInfo" );

    if( !ok ){
        initTables();
    }
}

bool CDatabaseMgr::isTargetTableExisted( const QString &tableName )
{
    QString sqlString = QString( "select count( * ) from sqlite_master where type = 'table' and name = '%1'" ).arg( tableName );
    QSqlQuery sql( m_database );

    if( !sql.exec( sqlString ) ){
        qDebug() << "query target table existed failed, err str = " << sql.lastError().text();
        return false;
    }

    while( sql.next() ){
        int ret = sql.value( 0 ).toInt();

        if( ret > 0 ){
            return true;
        }

        return false;
    }

}
