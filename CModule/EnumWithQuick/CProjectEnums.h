#ifndef CPROJECTENUMS_H
#define CPROJECTENUMS_H

#include <QObject>

class CProjectEnums : public QObject
{
    Q_OBJECT
    Q_ENUMS( TestEnum )
public:
    enum ColorEnum{
        RED = 0,
        GREEN,
        YELLOW,
        BLUE
    };
    Q_ENUM( ColorEnum )

    enum TestEnum{
        WDNMD = 0,
        WSND
    };
    CProjectEnums();
};

#endif // CPROJECTENUMS_H
