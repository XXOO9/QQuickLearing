#include "CusDateModel.h"

CusDateModel::CusDateModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void CusDateModel::refreshDateModel(const int &weekDay, const int &days)
{
    ElementDateInfo tmpEleDay;
    m_vecTotalInfos.clear();
    for( int weekDayOffset = 1; weekDayOffset < weekDay; weekDayOffset++ ){
        m_vecTotalInfos << tmpEleDay;
    }

    for( int dayIndex = 1; dayIndex < days; dayIndex++ ){
        tmpEleDay.m_dayIndex = dayIndex;
        m_vecTotalInfos << tmpEleDay;
    }

    tmpEleDay.m_dayIndex = 0;
    while (m_vecTotalInfos.size() < 42 ) {
        m_vecTotalInfos << tmpEleDay;
    }
}

int CusDateModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    m_vecTotalInfos.size();

    // FIXME: Implement me!
}

QVariant CusDateModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QVariant ret;

    switch (role) {
    case ElementDateInfo::Hour:
        ret = m_vecTotalInfos[ index.row() ].m_hour;

    case ElementDateInfo::TimeCnt:
        ret = m_vecTotalInfos[ index.row() ].m_timeCnt;

    case ElementDateInfo::Today:
        ret = m_vecTotalInfos[ index.row() ].m_isToday;

    case ElementDateInfo::DayIndex:
        ret = m_vecTotalInfos[ index.row() ].m_dayIndex;
        break;
    default:
        break;
    }

    // FIXME: Implement me!
    return ret;
}

bool CusDateModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!

        switch (role) {
        case ElementDateInfo::Hour:
            m_vecTotalInfos[ index.row() ].m_hour = value.toInt();

        case ElementDateInfo::TimeCnt:
            m_vecTotalInfos[ index.row() ].m_timeCnt = value.toInt();

        case ElementDateInfo::Today:
            m_vecTotalInfos[ index.row() ].m_isToday = value.toBool();
            break;

        case ElementDateInfo::DayIndex:
            m_vecTotalInfos[ index.row() ].m_dayIndex = value.toInt();

        default:
            break;
        }

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags CusDateModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> CusDateModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[ ElementDateInfo::Hour ]        = "hour";
    roleNames[ ElementDateInfo::TimeCnt ]     = "timeCnt";
    roleNames[ ElementDateInfo::Today ]       = "isToday";
    roleNames[ ElementDateInfo::DayIndex ]    = "dayIndex";

    return roleNames;
}
