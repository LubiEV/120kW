/****************************************************************************
** Meta object code from reading C++ file 'widgetKeyBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "keyboard/widgetKeyBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetKeyBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgetKeyBoard_t {
    QByteArrayData data[14];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetKeyBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetKeyBoard_t qt_meta_stringdata_widgetKeyBoard = {
    {
QT_MOC_LITERAL(0, 0, 14), // "widgetKeyBoard"
QT_MOC_LITERAL(1, 15, 17), // "keySignalReceived"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "show"
QT_MOC_LITERAL(4, 39, 8), // "QWidget*"
QT_MOC_LITERAL(5, 48, 10), // "activeForm"
QT_MOC_LITERAL(6, 59, 10), // "QLineEdit*"
QT_MOC_LITERAL(7, 70, 5), // "first"
QT_MOC_LITERAL(8, 76, 9), // "frameless"
QT_MOC_LITERAL(9, 86, 4), // "hide"
QT_MOC_LITERAL(10, 91, 13), // "noChangeColor"
QT_MOC_LITERAL(11, 105, 9), // "focusThis"
QT_MOC_LITERAL(12, 115, 7), // "control"
QT_MOC_LITERAL(13, 123, 23) // "returnKeySignalReceived"

    },
    "widgetKeyBoard\0keySignalReceived\0\0"
    "show\0QWidget*\0activeForm\0QLineEdit*\0"
    "first\0frameless\0hide\0noChangeColor\0"
    "focusThis\0control\0returnKeySignalReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetKeyBoard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   50,    2, 0x0a /* Public */,
       3,    2,   57,    2, 0x2a /* Public | MethodCloned */,
       3,    1,   62,    2, 0x2a /* Public | MethodCloned */,
       9,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, QMetaType::Bool,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 6,   12,
    QMetaType::Void,

       0        // eod
};

void widgetKeyBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<widgetKeyBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keySignalReceived(); break;
        case 1: _t->show((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->show((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2]))); break;
        case 3: _t->show((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->hide((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->focusThis((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 6: _t->returnKeySignalReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widgetKeyBoard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetKeyBoard::keySignalReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgetKeyBoard::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_widgetKeyBoard.data,
    qt_meta_data_widgetKeyBoard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *widgetKeyBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgetKeyBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgetKeyBoard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int widgetKeyBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void widgetKeyBoard::keySignalReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
