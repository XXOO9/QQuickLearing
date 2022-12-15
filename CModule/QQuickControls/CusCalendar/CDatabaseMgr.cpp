#include "CDatabaseMgr.h"

#include <QDate>

CDatabaseMgr::CDatabaseMgr()
{
//    testCDir();
    initDatabase();
}

CDatabaseMgr::~CDatabaseMgr()
{
    resetSqlExecute();

    if( m_database.isOpen() ){
        m_database.close();
    }
}

bool CDatabaseMgr::insertNewDateInfo(const QString &date, const double &hour, const double &timeCnt, const double &cost) const
{
    return insertNewDateInfo( date.toInt(), hour, timeCnt, cost );
}

bool CDatabaseMgr::insertNewDateInfo(const int &date, const double &hour, const double &timeCnt, const double &cost) const
{
    QString sqlString = QString( "insert into dateInfo values(?, ?, ?, ?)" );

    m_pSqlExecute->prepare( sqlString );
    m_pSqlExecute->addBindValue( date );
    m_pSqlExecute->addBindValue( hour );
    m_pSqlExecute->addBindValue( timeCnt );
    m_pSqlExecute->addBindValue( cost );

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
            { Keys::dayIndex, getDayIndex( m_pSqlExecute->value( DateTime ).toInt() ) },
            { Keys::hours, m_pSqlExecute->value( Hours ).toDouble() },
            { Keys::timeCnt, m_pSqlExecute->value( TimeCnt ).toDouble() },
            { Keys::cost, m_pSqlExecute->value( Cost ).toDouble() }
        };

        retList << tmpRetMap;
//        qDebug() << "ret = " << tmpRetMap;
    }

    return retList;
}

bool CDatabaseMgr::changeTargetDateInfo(const int &targetDate, const double &hour, const double &timeCnt, const double &cost) const
{
    if( !isTargetDateRecordExisted( targetDate ) ){
        qDebug() << "no target date info in database...";
        return insertNewDateInfo( targetDate, hour, timeCnt, cost );
    }

    const QString sqlString = "update dateInfo set hours = ?, timeCnt = ? where date = ?";

    m_pSqlExecute->prepare( sqlString );

    m_pSqlExecute->addBindValue( hour );
    m_pSqlExecute->addBindValue( timeCnt );
    m_pSqlExecute->addBindValue( targetDate );

    if( !m_pSqlExecute->exec() ){
        qDebug() << "change hour failed, error string = " << m_pSqlExecute->lastError().text();
        return false;
    }

    return true;
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
    const QString createDateInfoTable = "create table dateInfo( date integer primary key, hours real, timeCnt real, cost real )";
    QSqlQuery sqlCmd( m_database );

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
        qDebug() << "query target table existed failed, error string = " << sql.lastError().text();
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

bool CDatabaseMgr::isTargetDateRecordExisted(const int &targetDate) const
{
    QString sqlString = "select count( * ) from dateInfo where date = ?";
    m_pSqlExecute->prepare( sqlString );
    m_pSqlExecute->addBindValue( targetDate );

    if( !m_pSqlExecute->exec() ){
        qDebug() << "query target date info failed, erorr string = " << m_pSqlExecute->lastError().text();
        return false;
    }

    while ( m_pSqlExecute->next() ) {
        if( m_pSqlExecute->value( 0 ).toInt() <= 0 ){
            qDebug() << "there is no target date info...";
            return false;
        }
    }

    return true;
}

int CDatabaseMgr::getDayIndex(const int &date) const
{
    QDate tmpDate = QDate::fromString( QString::number( date ), "yyyyMMdd" );
    return tmpDate.day();
}

void CDatabaseMgr::testCDir()
{
    QDir dir( "C:/CXK/" );
    if( !dir.exists() ){
        bool ok = dir.mkdir( dir.dirName() );
        if( !ok ){
            qDebug() << "ok = " << ok;
        }
    }

    qDebug() << "ret = " << dir.exists();

}
