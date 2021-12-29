#ifndef CDATAMODEL_H
#define CDATAMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include <QVector>
#include <QDebug>

namespace DataModel {
            enum ColumnIndex{
                FirstColumn = 0,
                SecondColumn,
                ThirdColumn,
                ForthColumn,
                FifthColumn,
                SixthColumn,
                seventhColumn,
                eigthColumn,
                RowUnique,
                Check,
            };
}
using namespace DataModel;
class CDataModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    explicit CDataModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //每一列的角色名,在qml中，通过角色名访问值
    QHash<int, QByteArray> roleNames() const override;

    //check unique by RowUnique
    bool isSingleton( QString unique );

    //add row
    bool appendRow( QHash<ColumnIndex, QString> rowData );

    //
    Q_INVOKABLE QString getValue(int row, int column );
    //control the visible of check point
    Q_INVOKABLE void check( int rowIndex );

    Q_INVOKABLE void test_append();
    Q_INVOKABLE void test_check();

private:
    QVector< QHash<ColumnIndex, QString> >   m_vecRets;

};

#endif // CDATAMODEL_H
