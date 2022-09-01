#include "CModelUserSelect.h"

CModelUserSelect::CModelUserSelect(QObject *parent)
    : QAbstractListModel(parent)
{
    CUserSelectItem tmp;
    for( int i = 0; i < 10; i++ ){
        tmp.setUserName( "name_" + QString::number( i ) );
        tmp.setUserNumber( QString::number( i ) );

        m_vecUsers << tmp;
    }
}

QVariant CModelUserSelect::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!

    return QVariant();
}

int CModelUserSelect::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_vecUsers.size();
}

QVariant CModelUserSelect::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if( row < 0 || row > m_vecUsers.size() ){
        return QVariant();
    }

    // FIXME: Implement me!
    CUserSelectItem tmp = m_vecUsers[ row ];
    switch ( static_cast< UserItem >( role ) ) {
    case CheckState:
        return tmp.checkFlag();

    case PhotoPath:
        return tmp.photoPath();

    case UserName:
        return tmp.userName();

    case UserNumber:
        return tmp.userNumber();

    case UserWeight_KG:
        return tmp.userWeight();

    case BindDevOrderNumber:
        return tmp.bindDevOrderNum();

    default: return QVariant();
    }
}

QHash<int, QByteArray> CModelUserSelect::roleNames() const
{
    QHash<int, QByteArray>  roleNames;
    roleNames[ UserItem::CheckState ]         = "checkState";
    roleNames[ UserItem::PhotoPath ]          = "photoPath";
    roleNames[ UserItem::UserName ]           = "userName";
    roleNames[ UserItem::UserNumber ]         = "userNumber";
    roleNames[ UserItem::UserWeight_KG ]      = "userWeight_KG";
    roleNames[ UserItem::BindDevOrderNumber ] = "bindDevOrderNumber";

    return roleNames;
}
