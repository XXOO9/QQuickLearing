#include "CAbstractTableModel.h"

CAbstractTableModel::CAbstractTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int CAbstractTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_vecDatas.size();
}

int CAbstractTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_vecDatas.first().size();
}

QVariant CAbstractTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if( m_vecDatas.isEmpty() ){
        return QVariant();
    }
    if( index.row() > m_vecDatas.size() || index.column() > m_vecDatas.first().size() ){
        return QVariant();
    }
    CTableCell tmpCell = m_vecDatas[ index.row() ][ index.column() ];
    QString tmpRet = tmpCell.value( static_cast<CellRoles>( role ) );
    return tmpRet;
}

bool CAbstractTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags CAbstractTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool CAbstractTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool CAbstractTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool CAbstractTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool CAbstractTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}

CTableCell::CTableCell()
{

}

QString CTableCell::value(CAbstractTableModel::CellRoles roleName)
{
    switch (roleName) {
    case CAbstractTableModel::Cell_DisplayRole:
        return m_displayValue;
    default:
        return QString("");
    }
}
