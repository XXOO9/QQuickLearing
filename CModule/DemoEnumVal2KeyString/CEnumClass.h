#ifndef CENUMCLASS_H
#define CENUMCLASS_H

#include <QObject>
#include <QMetaEnum>
#include <QDebug>

class CEnumClass : public QObject
{
    Q_OBJECT
public:

    enum Day{
        SunDay = 0,
        MonDay,
        TuesDay,
        WednesDay,
        ThursDay,
        FriDay,
        SaturyDay

    };
    Q_ENUM( Day )

    explicit CEnumClass(QObject *parent = nullptr);

    void Int2Enum( int val );

private:
    QMetaEnum m_dayEnum;
};

#endif // CENUMCLASS_H
