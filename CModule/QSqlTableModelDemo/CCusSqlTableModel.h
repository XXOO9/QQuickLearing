#ifndef CCUSSQLTABLEMODEL_H
#define CCUSSQLTABLEMODEL_H

#include <QObject>
#include <QDebug>

class CCusSqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    CCusSqlTableModel();
    virtual ~CCusSqlTableModel() override;

    virtual QVariant data() override;

private:

};

#endif // CCUSSQLTABLEMODEL_H
