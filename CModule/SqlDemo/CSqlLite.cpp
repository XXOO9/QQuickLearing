#include "CSqlLite.h"

CSqlLite::CSqlLite(QObject *parent) : QObject(parent)
{
    initDataBase();
    //    insertIntoStudent( 20220101, "张三", "2020级99班" );
    //    deleteFromStudent( 20220101 );
    //    updateStudent( 20220101, "name", "张三" );
    //    query( 20220101, "name" );
    //    testFunc();
    //    queryTables();

//    testFunc();
    insertIntoCppDepartment();



}

void CSqlLite::testFunc()
{
    QSqlQuery sql;
    QString sqlString = QString( "select count(*) from PersonnelInfoTable_" );
    bool ok = sql.exec( sqlString );

    if( !ok ){
        qDebug() << "error string = " << sql.lastError();
        return;
    }

    int count = 0;
    while( sql.next() ){
        qDebug() << "ret 1 = " << sql.value( 0 );
        qDebug() << "ret 2 = " << sql.value( 1 );
        qDebug() << "ret 3 = " << sql.value( 2 );
        qDebug() << "ret 4 = " << sql.value( 3 );
    }
}

void CSqlLite::queryTables()
{
    QSqlQuery sql;
    QString sqlString = QString( "select * from sqlite_master" );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "error string = " << sql.lastError();
        return;
    }
    while( sql.next() ){
        qDebug() << "table name = " << sql.value( "name" );
    }
}

bool CSqlLite::insertIntoStudent(int id, QString stuName, QString className)
{
    QSqlQuery sql;
    QString sqlString = \
            QString( "insert into student values( %1, \"%2\", \"%3\" )" ).arg( id ).arg( stuName ).arg( className );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "error string = " << sql.lastError();
    }else{
        qDebug() << "insert into student success...";
    }
    return true;
}

void CSqlLite::insertGECGUserTable(QStringList list )
{
    QSqlQuery sql;
    QString sqlString = QString( "insert into PersonnelInfoTable_ values( %1, \"%2\", \"%3\", \"%4\", \"%5\", \"%6\", \"%7\", \"%8\", \"%9\", \"%10\")" ).arg( list[ 0 ] ).arg( list[ 1 ] )
            .arg( list[ 2 ] ).arg( list[ 3 ] ).arg( list[ 4 ] ).arg( list[ 5 ] )
            .arg( list[ 6 ] ).arg( list[ 7 ] ).arg( list[ 8 ] ).arg( list[ 9 ] );

    qDebug() << "sql = " << sqlString;

    bool ok = sql.exec( sqlString );
}

void CSqlLite::insertIntoCppDepartment()
{
    QVariantList infoList;
    QStringList list;

    QString dpName = "产品部";

    int startRowIndex = getRowsCount( "PersonnelInfoTable_" ) + 1;

    for( int i = 0; i < 20000; i++ ){

        list.clear();
        list << QString::number( startRowIndex + i ) << "PersonnelInfoTable" << dpName + "_" + QString::number( i ) << "2022-02-02" << "1" << QString::number( 150 + i )
             << QString::number( 50 + i ) << dpName << QString::number( startRowIndex + i ) << "1";

        insertGECGUserTable( list );

        qDebug() << "index = " << i;

    }

    qDebug() << "finished...";
}

int CSqlLite::getRowsCount(QString tableName)
{
    QSqlQuery sql;
    QString sqlString = QString( "select count(*) from %1" ).arg( tableName );
    bool ok = sql.exec( sqlString );

    if( !ok ){
        qDebug() << "error string = " << sql.lastError();
        return 0;
    }

    int count = 0;
    while( sql.next() ){
        count = sql.value( 0 ).toInt();
    }

    return count;
}

bool CSqlLite::deleteFromStudent(int id)
{
    QSqlQuery sql;
    QString sqlString = QString( "delete from student where id = %1" ).arg( id );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "error string = " << sql.lastError();
        return false;
    }
    qDebug() << "delete success...";
    return true;
}

bool CSqlLite::updateStudent(int id, QString key, QString val)
{
    QSqlQuery sql;
    QString sqlString = QString( "update student set %1 = \"%2\" where id = %3" ).arg( key ).arg( val ).arg( id );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "update error:: " << sql.lastError();
        return false;
    }
    qDebug() << "update student success...";
    return true;
}

QVariant CSqlLite::querySpecificVal(int id, QString key)
{
    QSqlQuery sql;
    QString sqlString = QString( "select %1 from student where id = %2" ).arg( key ).arg( id );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "query error:: " << sql.lastError();
        return QVariant();
    }
    while( sql.next() ){
        //查询出来的数据可能有多条!!!!
        int retIndex = 0;
        qDebug() << "ret = " << sql.value( retIndex );
        retIndex++;
    }
    return QVariant();
}

student CSqlLite::queryStudentInfo(int id)
{
    QSqlQuery sql;
    QString sqlString = QString( "select * from student where id = %1" ).arg( id );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "query error:: " << sql.lastError();
        return student();
    }
    while( sql.next() ){
        //查询出来的数据可能有多条!!!!
        int id = sql.value( "id" ).toInt();
        QString name = sql.value( "name" ).toString();
        QString className = sql.value( "className" ).toString();
    }
    return student();
}

void CSqlLite::initDataBase()
{
    m_dataBase = QSqlDatabase::addDatabase( "QSQLITE" );
    qDebug() << "ret = " << m_dataBase.isValid();
    m_dataBase.setDatabaseName( "GECGDatabase.db" );
    if( !m_dataBase.open() ){
        qDebug() << "Error::failed to open database, errorstring is::" << m_dataBase.lastError();
    }

    qDebug() << "Successd to open dataBase...";
    qDebug() << "connection name = " << m_dataBase.connectionName();
}

student::student(int id, QString name, QString className) : m_id( id ), m_name( name ), m_className( className )
{

}
