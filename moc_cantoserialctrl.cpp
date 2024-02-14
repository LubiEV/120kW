/****************************************************************************
** Meta object code from reading C++ file 'cantoserialctrl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "cantoserialctrl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cantoserialctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CanToSerialCtrl_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanToSerialCtrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanToSerialCtrl_t qt_meta_stringdata_CanToSerialCtrl = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CanToSerialCtrl"
QT_MOC_LITERAL(1, 16, 13), // "errorOccurred"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "CanBusError"
QT_MOC_LITERAL(4, 43, 14), // "framesReceived"
QT_MOC_LITERAL(5, 58, 2), // "ch"
QT_MOC_LITERAL(6, 61, 13), // "framesWritten"
QT_MOC_LITERAL(7, 75, 11), // "framesCount"
QT_MOC_LITERAL(8, 87, 17), // "SerialOpenSuccess"
QT_MOC_LITERAL(9, 105, 11), // "SendCanData"
QT_MOC_LITERAL(10, 117, 15), // "ReconnectDevice"
QT_MOC_LITERAL(11, 133, 15) // "StartCanConnect"

    },
    "CanToSerialCtrl\0errorOccurred\0\0"
    "CanBusError\0framesReceived\0ch\0"
    "framesWritten\0framesCount\0SerialOpenSuccess\0"
    "SendCanData\0ReconnectDevice\0StartCanConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanToSerialCtrl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       4,    0,   60,    2, 0x26 /* Public | MethodCloned */,
       6,    1,   61,    2, 0x06 /* Public */,
       8,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   65,    2, 0x0a /* Public */,
      10,    0,   66,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CanToSerialCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CanToSerialCtrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorOccurred((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->framesReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->framesReceived(); break;
        case 3: _t->framesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->SerialOpenSuccess(); break;
        case 5: _t->SendCanData(); break;
        case 6: _t->ReconnectDevice(); break;
        case 7: _t->StartCanConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CanToSerialCtrl::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanToSerialCtrl::errorOccurred)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CanToSerialCtrl::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanToSerialCtrl::framesReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CanToSerialCtrl::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanToSerialCtrl::framesWritten)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CanToSerialCtrl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanToSerialCtrl::SerialOpenSuccess)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CanToSerialCtrl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CanToSerialCtrl.data,
    qt_meta_data_CanToSerialCtrl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CanToSerialCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanToSerialCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CanToSerialCtrl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CanToSerialCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CanToSerialCtrl::errorOccurred(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CanToSerialCtrl::framesReceived(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void CanToSerialCtrl::framesWritten(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CanToSerialCtrl::SerialOpenSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
