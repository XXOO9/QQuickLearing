#ifndef CUSLISTDATAMODEL_H
#define CUSLISTDATAMODEL_H

#include <QAbstractListModel>

class ListElement{
public:
    void clear();
public:
    QString m_name = "null";
    QString m_number = "-1";
    bool    m_checked = false;
};

class CusListDataModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ListItem{
        Name = 0,
        Number,
        Checked
    };
    Q_ENUM( ListItem )

    explicit CusListDataModel(QObject *parent = nullptr);


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    virtual QHash< int, QByteArray > roleNames() const override;

private:
    void generateTestData();

private:

    QVector< ListElement >  m_vecListData;
};

#endif // CUSLISTDATAMODEL_H
