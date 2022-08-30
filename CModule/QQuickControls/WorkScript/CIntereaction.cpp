#include "CIntereaction.h"

CIntereaction::CIntereaction(QObject *parent)
    : QObject{parent}
{
    generateData();
}

QVariantList CIntereaction::getData()
{
    return m_dataList;
}

void CIntereaction::generateData()
{
    QElapsedTimer timer;
    timer.start();
    QVariantMap tmpMap;
    m_dataList.clear();

    for( int i = 0; i < 50000; i++ ){
        tmpMap[ "A" ] = "A_" + QString::number( i );
        tmpMap[ "B" ] = "B_" + QString::number( i );
        tmpMap[ "C" ] = "C_" + QString::number( i );
        tmpMap[ "D" ] = "D_" + QString::number( i );

        m_dataList << convert( tmpMap );
    }

    qDebug() << "config data cost = " << timer.elapsed();
}

QString CIntereaction::convert(const QVariantMap &srcMap)
{
    static QJsonDocument jsDoc;

    jsDoc = QJsonDocument::fromVariant( srcMap );

    return QString::fromUtf8( jsDoc.toJson() );
}
