/****************************************************************************
** Meta object code from reading C++ file 'ocpp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ocpp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ocpp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OCPP_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OCPP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OCPP_t qt_meta_stringdata_OCPP = {
    {
QT_MOC_LITERAL(0, 0, 4), // "OCPP"
QT_MOC_LITERAL(1, 5, 16), // "RmtCharger_Start"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "RmtCharger_Stop"
QT_MOC_LITERAL(4, 39, 15), // "onOCPPConnected"
QT_MOC_LITERAL(5, 55, 18), // "onOCPPdisConnected"
QT_MOC_LITERAL(6, 74, 10), // "TimerEvent"
QT_MOC_LITERAL(7, 85, 25), // "onOcppTextMessageReceived"
QT_MOC_LITERAL(8, 111, 7) // "message"

    },
    "OCPP\0RmtCharger_Start\0\0RmtCharger_Stop\0"
    "onOCPPConnected\0onOCPPdisConnected\0"
    "TimerEvent\0onOcppTextMessageReceived\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OCPP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   50,    2, 0x0a /* Public */,
       5,    0,   51,    2, 0x0a /* Public */,
       6,    0,   52,    2, 0x0a /* Public */,
       7,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void OCPP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OCPP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RmtCharger_Start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->RmtCharger_Stop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onOCPPConnected(); break;
        case 3: _t->onOCPPdisConnected(); break;
        case 4: _t->TimerEvent(); break;
        case 5: _t->onOcppTextMessageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OCPP::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OCPP::RmtCharger_Start)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OCPP::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OCPP::RmtCharger_Stop)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OCPP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OCPP.data,
    qt_meta_data_OCPP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OCPP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OCPP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OCPP.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OCPP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void OCPP::RmtCharger_Start(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OCPP::RmtCharger_Stop(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
