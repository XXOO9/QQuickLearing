/****************************************************************************
** Meta object code from reading C++ file 'CProjectEnums.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CProjectEnums.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CProjectEnums.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CProjectEnums_t {
    QByteArrayData data[9];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CProjectEnums_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CProjectEnums_t qt_meta_stringdata_CProjectEnums = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CProjectEnums"
QT_MOC_LITERAL(1, 14, 9), // "ColorEnum"
QT_MOC_LITERAL(2, 24, 3), // "RED"
QT_MOC_LITERAL(3, 28, 5), // "GREEN"
QT_MOC_LITERAL(4, 34, 6), // "YELLOW"
QT_MOC_LITERAL(5, 41, 4), // "BLUE"
QT_MOC_LITERAL(6, 46, 8), // "TestEnum"
QT_MOC_LITERAL(7, 55, 5), // "WDNMD"
QT_MOC_LITERAL(8, 61, 4) // "WSND"

    },
    "CProjectEnums\0ColorEnum\0RED\0GREEN\0"
    "YELLOW\0BLUE\0TestEnum\0WDNMD\0WSND"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CProjectEnums[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    4,   24,
       6,    6, 0x0,    2,   32,

 // enum data: key, value
       2, uint(CProjectEnums::RED),
       3, uint(CProjectEnums::GREEN),
       4, uint(CProjectEnums::YELLOW),
       5, uint(CProjectEnums::BLUE),
       7, uint(CProjectEnums::WDNMD),
       8, uint(CProjectEnums::WSND),

       0        // eod
};

void CProjectEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CProjectEnums::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CProjectEnums.data,
    qt_meta_data_CProjectEnums,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CProjectEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CProjectEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CProjectEnums.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CProjectEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
