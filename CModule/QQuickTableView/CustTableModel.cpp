#include "CustTableModel.h"

CustTableModel::CustTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant CustTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
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

    QMap<ColumnIndex, QString> retMap = m_vecDatas[ row ];
    QString ret = retMap.value( column );
    return ret;
}

bool CustTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    m_vecDatas.insert( row, count, QMap<ColumnIndex, QString>() );
    endInsertRows();
    return true;
}

bool CustTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
}

bool CustTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

bool CustTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
}

QHash<int, QByteArray> CustTableModel::roleNames() const
{
    QHash< int, QByteArray > roles;
    roles[ColumnIndex::Index]        = "indexColumn";
    roles[ColumnIndex::Check]        = "bCheck";
    roles[ColumnIndex::FirstColumn]  = "firstColumn";
    roles[ColumnIndex::SecondColumn] = "secondColumn";
    roles[ColumnIndex::ThirdColumn]  = "thirdColumn";
    roles[ColumnIndex::ForthColumn]  = "forthColumn";
    roles[ColumnIndex::FifthColumn]  = "fifthColumn";
    roles[ColumnIndex::SixthColumn]  = "sixthColumn";

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

QString CustTableModel::getValue(int column, int row)
{
//    if( row < 0 || row > m_vecDatas.size() || column < 0 || column >Columns() ){
//        return QString();
//    }

//    QMap<QString,QString> retMap = m_vecDatas[ row ];
//    QString ret = retMap.value()
}
