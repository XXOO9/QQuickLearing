#include "CDataModel.h"

CDataModel::CDataModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int CDataModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_vecRets.size();
}

int CDataModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    int columnCount = m_vecRets[0].size() - 2;
    return columnCount;
}

QVariant CDataModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "column = " << ColumnIndex( index.column() );
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    ColumnIndex column = ColumnIndex( index.column() );
    int row = index.row();
    QString ret = m_vecRets[ row ].value( column );
//    qDebug() << "row = " << row << " column = " << column << " ret = " << ret;
    return ret;
}

QHash<int, QByteArray> CDataModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[FirstColumn]   = "firstColumn";
    roles[SecondColumn]  = "secondColumn";
    roles[ThirdColumn]   = "thirdColumn";
    roles[ForthColumn]   = "forthColumn";
    roles[FifthColumn]   = "fifthColumn";
    roles[RowUnique]     = "unique";
    roles[Check]         = "isCheck";

    return roles;
}

bool CDataModel::isSingleton(QString unique)
{
    for( auto &each : m_vecRets ){
        if( unique == each[RowUnique] ){
            return false;
        }
    }
    return true;
}

bool CDataModel::appendRow(QHash<ColumnIndex, QString> rowData)
{
    if( !isSingleton( rowData[RowUnique] ) || rowData[RowUnique].isEmpty() ){
        qDebug() << "RowUnique is abNormal...";
        return false;
    }

    beginInsertRows(QModelIndex(), m_vecRets.size(), m_vecRets.size() );
    m_vecRets << rowData;
    endInsertRows();

    return true;
}

QString CDataModel::getValue(int row, int column)
{
    qDebug() << "come in " << column;
    ColumnIndex columnIndex = static_cast<ColumnIndex>(column);
    qDebug() << "after = " << columnIndex;
    QHash<ColumnIndex, QString> retHash = m_vecRets[ row ];
    QString ret = retHash[ columnIndex ];
    qDebug() << "ret = " << ret;
    return ret;
}

void CDataModel::check(int rowIndex)
{
    qDebug() << "row = " << rowIndex;
    if( rowIndex < 0 || rowIndex > rowCount() ){
        return;
    }

    QHash<ColumnIndex, QString> targetRow = m_vecRets[ rowIndex ];
    targetRow[Check] = "true";
    emit layoutChanged();
}

void CDataModel::test_append()
{
    QHash<ColumnIndex, QString> ret;
    ret[RowUnique]    =   "1";
    ret[Check]        =    "";
    ret[FirstColumn]  =   "test1";
    ret[SecondColumn] =   "test2";
    ret[ThirdColumn]  =   "test3";

    appendRow( ret );
}

void CDataModel::test_check()
{

}
