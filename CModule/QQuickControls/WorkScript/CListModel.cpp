#include "CListModel.h"

#include <QElapsedTimer>

CListModel::CListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    initDataModel();
}

int CListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_listDataModel.size();

    // FIXME: Implement me!
}

QVariant CListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if (!index.isValid() || row > m_listDataModel.size() )
        return QVariant();

    // FIXME: Implement me!
    switch (role) {
    case Role_A:
        return m_listDataModel.at( row ).value( Role_A );

    case Role_B:
        return m_listDataModel.at( row ).value( Role_B );

    case Role_C:
        return m_listDataModel.at( row ).value( Role_C );

    case Role_D:
        return m_listDataModel.at( row ).value( Role_D );

    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> CListModel::roleNames() const
{
    QHash< int, QByteArray > roleNames;

    roleNames[ Role_A ] = "roleA";
    roleNames[ Role_B ] = "roleB";
    roleNames[ Role_C ] = "roleC";
    roleNames[ Role_D ] = "roleD";

    return roleNames;
}

void CListModel::initDataModel()
{
    qDebug() << "start...";
    QElapsedTimer timer;
    timer.start();
    QMap< CusRoleName, QString > tmpMap;

    QString tmpIndex = "";

    for( int i = 0; i < 500000; i++ ){

        tmpIndex = QString::number( i );
        tmpMap[ Role_A ] = "roleA" + tmpIndex;
        tmpMap[ Role_B ] = "roleB" + tmpIndex;
        tmpMap[ Role_C ] = "roleC" + tmpIndex;
        tmpMap[ Role_D ] = "roleD" + tmpIndex;

        m_listDataModel << tmpMap;
    }

    qDebug() << "config list cost = " << timer.elapsed();

    qDebug() << "init finished...";
}
