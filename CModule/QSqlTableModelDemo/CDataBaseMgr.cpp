#include "CDataBaseMgr.h"

#include <QSqlField>
#include <QSqlRecord>

CDataBaseMgr::CDataBaseMgr(QObject *parent) : QObject(parent)
{
    createConnection();
    init();

    insertNewRecord();

//    for( int i = 0; i < 1000; i++ ){
//        insertNewRecord();
//    }

    //    query();
    //    queryFilter();
    //    change();

    ////    deleRecord();

    //    getSpecificRecord();
}

bool CDataBaseMgr::createConnection()
{
    m_db = QSqlDatabase::addDatabase( "QSQLITE" );
    m_db.setDatabaseName( "../src/GECGDatabase.db" );
    if( !m_db.open() ){
        qDebug() << "open db faild, " << m_db.lastError().text();
        return false;
    }

    qDebug() << "open db success";
    return true;
}

void CDataBaseMgr::insertNewRecord()
{
    int rowCount = m_pMentalTable->rowCount();
    int id = rowCount;

    bool ok = m_pMentalTable->insertRow( rowCount );

    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 0 ), id );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 1 ), "PersonnelInfoTable" );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 2 ), "C++_" + QString::number( id ) );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 3 ), "2022-08-30_" + QString::number( id ) );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 4 ), 1 );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 5 ), QString::number( 160 + id ) );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 6 ), QString::number( 30 + id ) );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 7 ), "c++" );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 8 ), "TME_C++_" + QString::number( id ) );
    ok      = m_pMentalTable->setData( m_pMentalTable->index( rowCount, 9 ), 1 );

    ok = m_pMentalTable->submit();

    if( !ok ){
        qDebug() << "error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revertAll();
    }
}

void CDataBaseMgr::deleRecord()
{
    int curRow = m_pMentalTable->rowCount() - 2;
    if( curRow <= 0 ){
        return;
    }

    bool ok = m_pMentalTable->removeRow( 1 );
    if( !ok ){
        qDebug() << "error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revertAll();
        return;
    }

    ok = m_pMentalTable->submit();

    if( !ok ){
        qDebug() << "error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revertAll();
    }
}

void CDataBaseMgr::query()
{
    bool ok = m_pMentalTable->select();

    int rowCount = m_pMentalTable->rowCount();
    int columnCount = m_pMentalTable->columnCount();

    QVariantList eleRecordList;

    for( int indexRow = 0; indexRow < rowCount; indexRow++ ){
        eleRecordList.clear();
        for( int indexColumn = 0; indexColumn < columnCount; indexColumn++ ){
            eleRecordList << m_pMentalTable->data( m_pMentalTable->index( indexRow, indexColumn ) );
        }
        qDebug() << eleRecordList;
    }
}

void CDataBaseMgr::queryFilter()
{
    m_pMentalTable->setFilter( QString( "id_ = 1 AND strUsername_ = 123456 AND strPassword_ = 1123456" ) );
    bool ok = m_pMentalTable->select();
    if( !ok ){
        qDebug() << "error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revertAll();
        return;
    }

    int rowCount = m_pMentalTable->rowCount();
    int columnCount = m_pMentalTable->columnCount();

    QVariantList eleRecordList;

    for( int indexRow = 0; indexRow < rowCount; indexRow++ ){
        eleRecordList.clear();
        for( int indexColumn = 0; indexColumn < columnCount; indexColumn++ ){
            eleRecordList << m_pMentalTable->data( m_pMentalTable->index( indexRow, indexColumn ) );
        }

        qDebug() << eleRecordList;
    }
}

void CDataBaseMgr::change()
{
    m_pMentalTable->setFilter( QString( "id_ = 12" ) );
    bool ok = m_pMentalTable->select();
    if( !ok ){
        qDebug() << "error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revertAll();
        return;
    }

    ok = m_pMentalTable->setData( m_pMentalTable->index( 0, 2 ), "newName" );
    if( !ok ){
        qDebug() << "change error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revert();
    }

    m_pMentalTable->submit();
}

void CDataBaseMgr::getSpecificRecord()
{
    m_pMentalTable->revertAll();
    QSqlRecord tmpRecord = m_pMentalTable->record( 0 );
    int count = tmpRecord.count();

    QSqlField tmpField;

    for( int i = 0; i < count; i++ ){
        qDebug() << "field name = "<< tmpRecord.fieldName( i );
    }
}

void CDataBaseMgr::init()
{
    if( nullptr == m_pMentalTable ){
        m_pMentalTable = new QSqlTableModel( this, m_db );
    }

    m_pMentalTable->setTable( "PersonnelInfoTable_" );
    bool ok = m_pMentalTable->select();
    qDebug() << "data( 0, 2 ) = " << m_pMentalTable->data( m_pMentalTable->index( 0, 2 ) );
    if( !ok ){
        qDebug()<< "error: " << m_pMentalTable->lastError().text();
        m_pMentalTable->revert();
    }
    qDebug() << "set table success";

    m_pMentalTable->revert();
}
