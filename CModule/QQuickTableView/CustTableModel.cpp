#include "CustTableModel.h"

CustTableModel::CustTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant CustTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QVariant();
}

int CustTableModel::rowCount(const QModelIndex &parent) const
{
    return m_vecDatas.size();
}

int CustTableModel::columnCount(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return m_Columns;
}

QVariant CustTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    ColumnIndex column = ColumnIndex( index.column() );

    QHash<ColumnIndex, CTableModelRowData> retHash = m_vecDatas[ row ];
    CTableModelRowData ret = retHash.value( column );
    return ret.dataRole();
}

bool CustTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool CustTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool CustTableModel::appendRow(rowDatas rowData)
{
    QString uniqueString = rowData[RowUnique].unqiueRole();
    if( !isUniqueble( uniqueString ) ){
        return false;
    }
    beginInsertRows( QModelIndex(), m_vecDatas.size(), m_vecDatas.size() );
    m_vecDatas << rowData;
    endInsertRows();
    return true;
}

bool CustTableModel::isUniqueble(QString uniqueString)
{
    for(auto &eachRow : m_vecDatas ){
        if( uniqueString == eachRow[RowUnique].unqiueRole() ){
            return false;
        }
    }
    return true;
}

bool CustTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool CustTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}

QHash<int, QByteArray> CustTableModel::roleNames() const
{
    QHash< int, QByteArray > roles;
    roles[ColumnIndex::RowUnique]       = "rowIndexColumn";
    roles[ColumnIndex::Check]           = "bCheck";
    roles[ColumnIndex::FirstColumn]     = "firstColumn";
    roles[ColumnIndex::SecondColumn]    = "secondColumn";
    roles[ColumnIndex::ThirdColumn]     = "thirdColumn";
    roles[ColumnIndex::ForthColumn]     = "forthColumn";
    roles[ColumnIndex::FifthColumn]     = "fifthColumn";
    roles[ColumnIndex::SixthColumn]     = "sixthColumn";
    return roles;
}

int CustTableModel::Columns() const
{
    return m_Columns;
}

void CustTableModel::setColumns(int Columns)
{
    m_Columns = Columns;
}

QString CustTableModel::getValue(ColumnIndex column, int row)
{
    if( row < 0 || row > m_vecDatas.size() || column < FirstColumn || column > Columns() ){
        return QString();
    }

    QHash<ColumnIndex, CTableModelRowData> retHash = m_vecDatas[ row ];
    CTableModelRowData retUnit = retHash.value( column );
    QString ret = retUnit.dataRole();
    return ret;
}
