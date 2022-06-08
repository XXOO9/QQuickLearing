/****************************************************************************
** Meta object code from reading C++ file 'CDataModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CDataModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CDataModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CDataModel_t {
    QByteArrayData data[23];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDataModel_t qt_meta_stringdata_CDataModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CDataModel"
QT_MOC_LITERAL(1, 11, 11), // "columnCount"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 36, 6), // "parent"
QT_MOC_LITERAL(5, 43, 13), // "setSingleData"
QT_MOC_LITERAL(6, 57, 12), // "uniqeuString"
QT_MOC_LITERAL(7, 70, 11), // "ColumnIndex"
QT_MOC_LITERAL(8, 82, 6), // "column"
QT_MOC_LITERAL(9, 89, 3), // "val"
QT_MOC_LITERAL(10, 93, 9), // "RoleNames"
QT_MOC_LITERAL(11, 103, 8), // "roleName"
QT_MOC_LITERAL(12, 112, 11), // "DisplayRole"
QT_MOC_LITERAL(13, 124, 10), // "UniqueRole"
QT_MOC_LITERAL(14, 135, 8), // "DataRole"
QT_MOC_LITERAL(15, 144, 11), // "FirstColumn"
QT_MOC_LITERAL(16, 156, 12), // "SecondColumn"
QT_MOC_LITERAL(17, 169, 11), // "ThirdColumn"
QT_MOC_LITERAL(18, 181, 11), // "ForthColumn"
QT_MOC_LITERAL(19, 193, 11), // "FifthColumn"
QT_MOC_LITERAL(20, 205, 11), // "SixthColumn"
QT_MOC_LITERAL(21, 217, 14), // "SevengthColumn"
QT_MOC_LITERAL(22, 232, 11) // "EightColumn"

    },
    "CDataModel\0columnCount\0\0QModelIndex\0"
    "parent\0setSingleData\0uniqeuString\0"
    "ColumnIndex\0column\0val\0RoleNames\0"
    "roleName\0DisplayRole\0UniqueRole\0"
    "DataRole\0FirstColumn\0SecondColumn\0"
    "ThirdColumn\0ForthColumn\0FifthColumn\0"
    "SixthColumn\0SevengthColumn\0EightColumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       2,   54, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x01 /* Protected */,
       1,    0,   37,    2, 0x21 /* Protected | MethodCloned */,
       5,    4,   38,    2, 0x01 /* Protected */,
       5,    3,   47,    2, 0x21 /* Protected | MethodCloned */,

 // methods: parameters
    QMetaType::Int, 0x80000000 | 3,    4,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 7, QMetaType::QString, 0x80000000 | 10,    6,    8,    9,   11,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 7, QMetaType::QString,    6,    8,    9,

 // enums: name, alias, flags, count, data
      10,   10, 0x0,    3,   64,
       7,    7, 0x0,    8,   70,

 // enum data: key, value
      12, uint(CDataModel::DisplayRole),
      13, uint(CDataModel::UniqueRole),
      14, uint(CDataModel::DataRole),
      15, uint(CDataModel::FirstColumn),
      16, uint(CDataModel::SecondColumn),
      17, uint(CDataModel::ThirdColumn),
      18, uint(CDataModel::ForthColumn),
      19, uint(CDataModel::FifthColumn),
      20, uint(CDataModel::SixthColumn),
      21, uint(CDataModel::SevengthColumn),
      22, uint(CDataModel::EightColumn),

       0        // eod
};

void CDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->columnCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->columnCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->setSingleData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const ColumnIndex(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const RoleNames(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->setSingleData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const ColumnIndex(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CDataModel::staticMetaObject = { {
    &QAbstractTableModel::staticMetaObject,
    qt_meta_stringdata_CDataModel.data,
    qt_meta_data_CDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CDataModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int CDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
