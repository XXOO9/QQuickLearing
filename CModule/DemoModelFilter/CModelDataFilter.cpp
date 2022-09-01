#include "CModelDataFilter.h"

CModelDataFilter::CModelDataFilter(QObject *parent) : QObject(parent)
{
    init();
}

void CModelDataFilter::init()
{
    m_proxyModel = new QSortFilterProxyModel();
    QStringList suggestions;

    suggestions << "mxq" << "cpc" << "sw" << "xtc" << "tcy" << "zhy" << "wyf" << "mxq1" << "cpc1" << "sw1" << "xtc1" << "tcy1" << "zhy1" << "wyf1";

    for( int i = 0; i < 10; i++ ){

        suggestions << "mxq" + QString::number( i )
                    << "cpc" + QString::number( i )
                    << "sw"  + QString::number( i )
                    << "xtc" + QString::number( i )
                    << "tcy" + QString::number( i )
                    << "zhy" + QString::number( i )
                    << "wyf" + QString::number( i );

        qDebug() << "cur i = " << QString::number( i );
    }

    static QStringListModel SuggestionModel;
    SuggestionModel.setStringList( suggestions );


    m_proxyModel->setSourceModel( &SuggestionModel );
    m_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    //按第一列排序
//    m_proxyModel->sort(0);
}
