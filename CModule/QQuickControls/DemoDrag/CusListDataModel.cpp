#include "CusListDataModel.h"

CusListDataModel::CusListDataModel(QObject *parent)
    : QAbstractListModel(parent)
{
    generateTestData();
}

int CusListDataModel::rowCount(const QModelIndex &parent) const
{
    return m_vecListData.size();
}

QVariant CusListDataModel::data(const QModelIndex &index, int role) const
{
    if( index.row() >= m_vecListData.size() ){
        return QVariant();
    }

    int rowIndex = index.row();

    switch ( role ) {
    case ListItem::Name:
        return m_vecListData.at( rowIndex ).m_name;

    case ListItem::Number:
        return m_vecListData.at( rowIndex ).m_number;

    case ListItem::Checked:
        return m_vecListData.at( rowIndex ).m_checked;

    default:
        return QVariant();
    }

    return QVariant();
}

bool CusListDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if( index.row() >= m_vecListData.size() ){
        return false;
    }

    switch ( role ) {
    case ListItem::Name:
        m_vecListData[ index.row() ].m_name = value.toString();
        break;

    case ListItem::Number:
        m_vecListData[ index.row() ].m_number = value.toString();
        break;

    case ListItem::Checked:
        m_vecListData[ index.row() ].m_checked = value.toBool();
        break;

    default:
        return false;
    }

    emit dataChanged( index, index, QVector< int >() << role );
    return true;
}

QHash<int, QByteArray> CusListDataModel::roleNames() const
{
    QHash< int, QByteArray > roleNames;

    roleNames[ ListItem::Name ]    = "userName";
    roleNames[ ListItem::Number ]  = "userNumber";
    roleNames[ ListItem::Checked ] = "userBind";

    return roleNames;
}

void CusListDataModel::generateTestData()
{
    ListElement tmpEle;
    QString index = "";
    for( int i = 0; i < 10; i++ ){
        tmpEle.clear();
        index = QString::number( i );
        tmpEle.m_name += index;
        tmpEle.m_number += index;

        m_vecListData << tmpEle;
    }
}

void ListElement::clear()
{
    m_name = "name_";
    m_number = "number_";
    m_checked = false;
}
