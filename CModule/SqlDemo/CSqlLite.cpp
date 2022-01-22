#include "CSqlLite.h"

CSqlLite::CSqlLite(QObject *parent) : QObject(parent)
{
    initDataBase();
    //    insertIntoStudent( 20220101, "张三", "2020级99班" );
    //    deleteFromStudent( 20220101 );
    //    updateStudent( 20220101, "name", "张三" );
    //    query( 20220101, "name" );
//    testFunc();
    queryTables();
}

void CSqlLite::testFunc()
{
    QSqlQuery sql;
    QString sqlString = QString( "select * from student" );
    bool ok = sql.exec( sqlString );
    if( !ok ){
        qDebug() << "error string = " << sql.lastError();
        return;
    }
    qDebug() << "count = " << sql.size();
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
        qDebug() << "ret 1 = " << sql.value( "name" );
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
    m_dataBase.setDatabaseName( "demo.db" );
    if( !m_dataBase.open() ){
        qDebug() << "Error::failed to open database, errorstring is::" << m_dataBase.lastError();
    }

    qDebug() << "Successd to open dataBase...";
    qDebug() << "connection name = " << m_dataBase.connectionName();
}

student::student(int id, QString name, QString className) : m_id( id ), m_name( name ), m_className( className )
{

}
