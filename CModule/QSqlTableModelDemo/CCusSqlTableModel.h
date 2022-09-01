#ifndef CCUSSQLTABLEMODEL_H
#define CCUSSQLTABLEMODEL_H

#include <QObject>
#include <QDebug>
#include <QSqlTableModel>

class CCusSqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    CCusSqlTableModel();
    virtual ~CCusSqlTableModel() override;

private:

};

#endif // CCUSSQLTABLEMODEL_H
