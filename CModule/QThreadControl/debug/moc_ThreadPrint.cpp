/****************************************************************************
** Meta object code from reading C++ file 'ThreadPrint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ThreadPrint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadPrint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadPrint_t {
    QByteArrayData data[14];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadPrint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadPrint_t qt_meta_stringdata_ThreadPrint = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ThreadPrint"
QT_MOC_LITERAL(1, 12, 19), // "insideSigStartPrint"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "insideSigStartCount"
QT_MOC_LITERAL(4, 53, 16), // "insideStartTimer"
QT_MOC_LITERAL(5, 70, 23), // "insideSigInitConnection"
QT_MOC_LITERAL(6, 94, 19), // "insideSigKillThread"
QT_MOC_LITERAL(7, 114, 12), // "onStartPrint"
QT_MOC_LITERAL(8, 127, 12), // "onStartCount"
QT_MOC_LITERAL(9, 140, 12), // "onConnection"
QT_MOC_LITERAL(10, 153, 16), // "onThreadFinished"
QT_MOC_LITERAL(11, 170, 12), // "onStartTimer"
QT_MOC_LITERAL(12, 183, 12), // "onKillThread"
QT_MOC_LITERAL(13, 196, 14) // "onTimerTimeout"

    },
    "ThreadPrint\0insideSigStartPrint\0\0"
    "insideSigStartCount\0insideStartTimer\0"
    "insideSigInitConnection\0insideSigKillThread\0"
    "onStartPrint\0onStartCount\0onConnection\0"
    "onThreadFinished\0onStartTimer\0"
    "onKillThread\0onTimerTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadPrint[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ThreadPrint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadPrint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insideSigStartPrint(); break;
        case 1: _t->insideSigStartCount(); break;
        case 2: _t->insideStartTimer(); break;
        case 3: _t->insideSigInitConnection(); break;
        case 4: _t->insideSigKillThread(); break;
        case 5: _t->onStartPrint(); break;
        case 6: _t->onStartCount(); break;
        case 7: _t->onConnection(); break;
        case 8: _t->onThreadFinished(); break;
        case 9: _t->onStartTimer(); break;
        case 10: _t->onKillThread(); break;
        case 11: _t->onTimerTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadPrint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadPrint::insideSigStartPrint)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadPrint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadPrint::insideSigStartCount)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThreadPrint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadPrint::insideStartTimer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThreadPrint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadPrint::insideSigInitConnection)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThreadPrint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadPrint::insideSigKillThread)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ThreadPrint::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ThreadPrint.data,
    qt_meta_data_ThreadPrint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadPrint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadPrint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadPrint.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadPrint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ThreadPrint::insideSigStartPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadPrint::insideSigStartCount()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ThreadPrint::insideStartTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ThreadPrint::insideSigInitConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ThreadPrint::insideSigKillThread()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
