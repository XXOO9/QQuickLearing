#include "CusFiltListModel.h"

CusFiltListModel::CusFiltListModel()
{

}

CusFiltListModel::~CusFiltListModel()
{

}

bool CusFiltListModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QString data_role1 = sourceModel()->index( source_row, 0, source_parent ).data( CModelUserSelect::UserItem::UserDepartment ).toString();
    QString data_role2 = sourceModel()->index( source_row, 0, source_parent ).data( CModelUserSelect::UserItem::UserName ).toString();

//    qDebug() << "val = " << data_role1;
//    qDebug() << "RegExp = " << this->filterRegExp();

    if( data_role1 != m_targetDepartmentName ){
        return false;
    }

    if( data_role2.contains( this->filterRegExp() ) ){

        qDebug() << "val = " << data_role1;
        qDebug() << "RegExp = " << this->filterRegExp();
        qDebug() << "true row = " << source_row;
        return true;
    }

    return false;
}
