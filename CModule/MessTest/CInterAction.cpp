#include "CInterAction.h"

#include <QRegularExpression>

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{
    testQStringContains();

    testDateTimeToString();
}

void CInterAction::testQStringContains()
{
    QString src = "A-B-C-D-E-F-G";
    QString target = "A-B-C";

    QRegExp reg = QRegExp( target );

    if( reg.isValid() ){
        qDebug() << "WDNMD";
    }


    bool ok = src.contains( reg );
    qDebug() << "ret = " << ok << " , reg = " << reg.pattern();
}

void CInterAction::testDateTimeToString()
{
    long long time = 20221018165926;
    QString timeString = QString::number( time );

    QDateTime dateTime = QDateTime::fromString( timeString, "yyyyMMddhhmmss" );

    qDebug() << "time = " << dateTime;
}
