#include "CTableModelImplementation.h"

typedef QList<CTableElement>  TableRowData;
CTableModelImplementation::CTableModelImplementation(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant CTableModelImplementation::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QVariant();
}

bool CTableModelImplementation::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int CTableModelImplementation::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!

    return m_vecTableContents.size();
}

int CTableModelImplementation::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    int colunmClount = m_vecTableContents.first().size();
    return colunmClount;
}

QVariant CTableModelImplementation::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    TableRowData rowData = m_vecTableContents[ index.row() ];
    CTableElement ele = rowData[ index.column() ];

    CTableElement::elementType type = static_cast<CTableElement::elementType>( role );

    QVariant data = ele.getData( type );
    return data;
}

bool CTableModelImplementation::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags CTableModelImplementation::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool CTableModelImplementation::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();

    return true;
}

bool CTableModelImplementation::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool CTableModelImplementation::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool CTableModelImplementation::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}

void CTableElement::setData(CTableElement::elementType type, QVariant data)
{
    switch (type) {
    case Text:
    case TextInput:
        m_displayText = data.toString();
        return;
    case CheckBox:
        m_isChecked = data.toBool();
        return;
    default:
        m_displayText = data.toString();
        return;
    }
}

QVariant CTableElement::getData(CTableElement::elementType type)
{
    switch (type) {
    case Text:
    case TextInput:
        return m_displayText;
    case CheckBox:
        return m_isChecked;
    default:
        return m_displayText;
    }
}
