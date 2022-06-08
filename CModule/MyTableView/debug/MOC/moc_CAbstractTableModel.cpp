/****************************************************************************
** Meta object code from reading C++ file 'CAbstractTableModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CAbstractTableModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CAbstractTableModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAbstractTableModel_t {
    QByteArrayData data[19];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAbstractTableModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAbstractTableModel_t qt_meta_stringdata_CAbstractTableModel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CAbstractTableModel"
QT_MOC_LITERAL(1, 20, 16), // "horizontalHeader"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "columnIndex"
QT_MOC_LITERAL(4, 50, 19), // "setHorizontalHeader"
QT_MOC_LITERAL(5, 70, 7), // "headers"
QT_MOC_LITERAL(6, 78, 21), // "horizontalHeaderCount"
QT_MOC_LITERAL(7, 100, 15), // "setSpecificData"
QT_MOC_LITERAL(8, 116, 12), // "uniqueString"
QT_MOC_LITERAL(9, 129, 11), // "ColumnIndex"
QT_MOC_LITERAL(10, 141, 12), // "targetColumn"
QT_MOC_LITERAL(11, 154, 3), // "val"
QT_MOC_LITERAL(12, 158, 5), // "check"
QT_MOC_LITERAL(13, 164, 9), // "testfunc1"
QT_MOC_LITERAL(14, 174, 9), // "testfunc2"
QT_MOC_LITERAL(15, 184, 9), // "testfunc3"
QT_MOC_LITERAL(16, 194, 9), // "testfunc4"
QT_MOC_LITERAL(17, 204, 9), // "testfunc5"
QT_MOC_LITERAL(18, 214, 9) // "testfunc6"

    },
    "CAbstractTableModel\0horizontalHeader\0"
    "\0columnIndex\0setHorizontalHeader\0"
    "headers\0horizontalHeaderCount\0"
    "setSpecificData\0uniqueString\0ColumnIndex\0"
    "targetColumn\0val\0check\0testfunc1\0"
    "testfunc2\0testfunc3\0testfunc4\0testfunc5\0"
    "testfunc6"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAbstractTableModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x02 /* Public */,
       4,    1,   72,    2, 0x02 /* Public */,
       6,    0,   75,    2, 0x02 /* Public */,
       7,    3,   76,    2, 0x02 /* Public */,
      12,    1,   83,    2, 0x02 /* Public */,
      13,    0,   86,    2, 0x02 /* Public */,
      14,    0,   87,    2, 0x02 /* Public */,
      15,    0,   88,    2, 0x02 /* Public */,
      16,    0,   89,    2, 0x02 /* Public */,
      17,    0,   90,    2, 0x02 /* Public */,
      18,    0,   91,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QVariant, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 9, QMetaType::QString,    8,   10,   11,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CAbstractTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAbstractTableModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->horizontalHeader((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setHorizontalHeader((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: { int _r = _t->horizontalHeaderCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->setSpecificData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ColumnIndex(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->check((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->testfunc1(); break;
        case 6: _t->testfunc2(); break;
        case 7: _t->testfunc3(); break;
        case 8: _t->testfunc4(); break;
        case 9: _t->testfunc5(); break;
        case 10: _t->testfunc6(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAbstractTableModel::staticMetaObject = { {
    &CDataModel::staticMetaObject,
    qt_meta_stringdata_CAbstractTableModel.data,
    qt_meta_data_CAbstractTableModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAbstractTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAbstractTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAbstractTableModel.stringdata0))
        return static_cast<void*>(this);
    return CDataModel::qt_metacast(_clname);
}

int CAbstractTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
