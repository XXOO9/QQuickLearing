#ifndef CUSTTABLEMODEL_H
#define CUSTTABLEMODEL_H

#include <QAbstractTableModel>

class CustTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    enum ColumnIndex{
        Index       = 1,
        Check,
        FirstColumn,
        SecondColumn,
        ThirdColumn,
        ForthColumn,
        FifthColumn,
        SixthColumn
    };
    explicit CustTableModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    QHash<int, QByteArray> roleNames() const override;

    int Columns() const;
    void setColumns(int Columns);

    QString getValue( int column, int row );

private:
    QVector< QMap<ColumnIndex, QString> > m_vecDatas;
    QStringList                           m_roleNamesList;
    int                                   m_Columns;
};

#endif // CUSTTABLEMODEL_H
