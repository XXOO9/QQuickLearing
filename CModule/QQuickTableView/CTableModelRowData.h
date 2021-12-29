#ifndef CTABLEMODELROWDATA_H
#define CTABLEMODELROWDATA_H

#include <QObject>
#include <QDebug>
#include <QHash>


namespace ColumnEnums {
        enum ColumnIndex{
            RowUnique       = 1,
            Check,
            FirstColumn,
            SecondColumn,
            ThirdColumn,
            ForthColumn,
            FifthColumn,
            SixthColumn,
            seventhColumn,
            eigthColumn,
        };

        enum ValueRoles{
            DisplayRole = 1,
            DataRole,
            TipsRole,
            unquieRole,
        };
}

using namespace ColumnEnums;


class CTableModelRowData
{

public:
    explicit CTableModelRowData();
    ~CTableModelRowData();

    void setDisplayRole( QString val );
    QString displayRole();

    void setDataRole(  QString val );
    QString dataRole();

    void setTipsRole(  QString val );
    QString tipsRole();

    void setUnqiueRole( QString val );
    QString unqiueRole();

    void clear();

private:
    QHash<ValueRoles, QString> m_unitData;
};

#endif // CTABLEMODELROWDATA_H
