#ifndef CTESTLITESQL_H
#define CTESTLITESQL_H

#include <QObject>
#include "./thirdParty/liteSql/litesql.hpp"
#include "wdnmd.hpp"
#include <QDebug>
#include <QFile>


using namespace litesql;
using namespace example;
using namespace std;

class CTestLiteSql
{
public:
    CTestLiteSql();

    void insert_50_records_into_WDNMD( const WDNMD *pDB );

    void removeRecords();

    void queryTargetRecords();
    void test();
    WDNMD *m_pDataBase = nullptr;
};

#endif // CTESTLITESQL_H
