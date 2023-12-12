#include "CusTableModel.h"

CusTableModel::CusTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

    for( int i = 0; i < 5; i++ ){
        TableColumnItems tmp;
        tmp.name += QString::number( i );
        if( i % 2 == 0 ){
            tmp.checked = true;
        }
        m_vecDatas.append( tmp );
    }

}

QVariant CusTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!

    if( orientation != Qt::Horizontal ){
        return QVariant();
    }

    if( role != Qt::DisplayRole ){
        return QVariant();
    }

    return QVariant( "W" );
}

int CusTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    int size = m_vecDatas.size();
    return size;
}

int CusTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 3;
}

QVariant CusTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!

    int rowIndex = index.row();
    auto targetRow = m_vecDatas.at( rowIndex );

    int colIndex = index.column();

    switch( role ){
    case -1:
        return targetRow.checked;
    case -2:
        return targetRow.name;

    case Qt::DisplayRole:
    case Qt::EditRole:
        return targetRow.getIndexVal( colIndex );

    case Qt::UserRole:
    {
        if( colIndex == 0 ){
            return true;
        }
        break;
    }
    default:
        return QVariant();
    }

    return QVariant();
}

bool CusTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    /*
     *1: 针对全景软件的英伟达独显和因特尔核显图像编码器进行兼容适配
     *2. 修改总控软件解码器端
     *3. 熟悉全景软件TCP传图和解图，拼接，控制俯仰角协议
     *4. 定位全景软件在总控软件关闭时，会崩溃的bug
*/
    if( !index.isValid() ){
        return false;
    }

    int colIndex = index.column();
    auto &targetElement = m_vecDatas[ index.row() ];
    switch( role ){
    case -1:
        targetElement.setIndexVal( value, 2 );
        break;
    case -2:
        targetElement.setIndexVal( value, 0 );
        break;
    case Qt::EditRole:
        targetElement.setIndexVal( value, colIndex );
        break;

    case Qt::CheckStateRole:
        return true;
        break;

    default:
        return false;
    }


    emit dataChanged( index, index );
    return true;


}

bool CusTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!


    endInsertRows();
    return true;
}

bool CusTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool CusTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool CusTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}

Qt::ItemFlags CusTableModel::flags(const QModelIndex &index) const
{
    auto flag = Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable;
    return flag;
}

QVariant TableColumnItems::getIndexVal(const int index)
{
    switch( index ){
    case 0:
        return this->name;
    case 1:
        return this->sex;
    case 2:
        return this->checked;

    default:
        return QVariant();
    }
}

void TableColumnItems::setIndexVal(const QVariant &val, const int index)
{
    switch( index ){
    case 0:
        this->name = val.toString();
        return;
    case 1:
        this->sex = val.toString();
        return;
    case 2:
        this->checked = val.toBool();
        return;

    default:
        return;
    }
}
