/****************************************************************************
** Meta object code from reading C++ file 'imd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "imd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Imd_t {
    QByteArrayData data[20];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Imd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Imd_t qt_meta_stringdata_Imd = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Imd"
QT_MOC_LITERAL(1, 4, 5), // "delay"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 17), // "number_of_seconds"
QT_MOC_LITERAL(4, 29, 15), // "can_setting_imd"
QT_MOC_LITERAL(5, 45, 11), // "const char*"
QT_MOC_LITERAL(6, 57, 3), // "can"
QT_MOC_LITERAL(7, 61, 7), // "bitrate"
QT_MOC_LITERAL(8, 69, 6), // "enable"
QT_MOC_LITERAL(9, 76, 9), // "VoltageVP"
QT_MOC_LITERAL(10, 86, 15), // "Resistance_func"
QT_MOC_LITERAL(11, 102, 10), // "Error_func"
QT_MOC_LITERAL(12, 113, 11), // "Capacitance"
QT_MOC_LITERAL(13, 125, 14), // "isolation_func"
QT_MOC_LITERAL(14, 140, 12), // "Battery_func"
QT_MOC_LITERAL(15, 153, 5), // "vbmax"
QT_MOC_LITERAL(16, 159, 7), // "Restart"
QT_MOC_LITERAL(17, 167, 8), // "imd_test"
QT_MOC_LITERAL(18, 176, 10), // "ImdCalling"
QT_MOC_LITERAL(19, 187, 19) // "Ethernet_connection"

    },
    "Imd\0delay\0\0number_of_seconds\0"
    "can_setting_imd\0const char*\0can\0bitrate\0"
    "enable\0VoltageVP\0Resistance_func\0"
    "Error_func\0Capacitance\0isolation_func\0"
    "Battery_func\0vbmax\0Restart\0imd_test\0"
    "ImdCalling\0Ethernet_connection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Imd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    3,   82,    2, 0x0a /* Public */,
       9,    0,   89,    2, 0x0a /* Public */,
      10,    0,   90,    2, 0x0a /* Public */,
      11,    0,   91,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,
      16,    0,   96,    2, 0x0a /* Public */,
      17,    0,   97,    2, 0x0a /* Public */,
      18,    0,   98,    2, 0x0a /* Public */,
      19,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int, 0x80000000 | 5, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void Imd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Imd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = _t->can_setting_imd((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->VoltageVP();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->Resistance_func();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->Error_func();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->Capacitance();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->isolation_func();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->Battery_func();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->vbmax();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->Restart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->imd_test();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->ImdCalling();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->Ethernet_connection();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Imd::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Imd.data,
    qt_meta_data_Imd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Imd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Imd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Imd.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Imd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
