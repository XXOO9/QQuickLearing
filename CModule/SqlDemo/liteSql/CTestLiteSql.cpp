#include "CTestLiteSql.h"

CTestLiteSql::CTestLiteSql()
{
    if( !QFile::exists( "./WDNMD.db" ) ){
        m_pDataBase = new WDNMD( "sqlite3", "database=WDNMD.db" );
        m_pDataBase->create();
    }else{
        m_pDataBase = new WDNMD( "sqlite3", "database=WDNMD.db" );
    }


//    insert_50_records_into_WDNMD( m_pDataBase );

//    userInfo u( *m_pDataBase );
//    u.userName = "WDNMD";
//    u.age = 99;
//    u.update();

    queryTargetRecords();
    test();
}


void CTestLiteSql::insert_50_records_into_WDNMD( const WDNMD *pDB )
{

    for( int i = 0; i < 50; i++ ){
        userInfo tmpUser( *pDB );
        tmpUser.userName = QString( "userName_" + QString::number( i ) ).toStdString();
        tmpUser.age = i;
        tmpUser.update();
    }

    qDebug() << "done...";
}

void CTestLiteSql::removeRecords()
{

}

void CTestLiteSql::queryTargetRecords()
{
    And sql( userInfo::UserName == "userName_1", userInfo::Age == 11 );

    qDebug() << QString::fromStdString( sql.asString() );
    vector<userInfo> target = select<userInfo>( *m_pDataBase, sql ).all();

    //    Records records = m_pDataBase->query( SelectQuery().result( "id_" ).source( "userName_" ).where( userInfo::UserName == "userName_1" ) );
}

void CTestLiteSql::test()
{
    Records recs = m_pDataBase->query( "select count ( * ) from userInfo_" );

    for( auto &ele : recs ){
        qDebug() << QString::fromStdString( ele );
    }
}
