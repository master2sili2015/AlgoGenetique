/****************************************************************************
** Meta object code from reading C++ file 'coordSol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "coordSol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coordSol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CoordSol_t {
    QByteArrayData data[9];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CoordSol_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CoordSol_t qt_meta_stringdata_CoordSol = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 11),
QT_MOC_LITERAL(4, 33, 6),
QT_MOC_LITERAL(5, 40, 12),
QT_MOC_LITERAL(6, 53, 4),
QT_MOC_LITERAL(7, 58, 13),
QT_MOC_LITERAL(8, 72, 3)
    },
    "CoordSol\0updateDraw\0\0drawSurface\0"
    "string\0rafraichDraw\0list\0updateSurface\0"
    "str\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoordSol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    2,   35,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   40,    2, 0x08,
       7,    2,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 4,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    6,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 4,    6,    8,

       0        // eod
};

void CoordSol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CoordSol *_t = static_cast<CoordSol *>(_o);
        switch (_id) {
        case 0: _t->updateDraw(); break;
        case 1: _t->drawSurface((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 2: _t->rafraichDraw((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->updateSurface((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CoordSol::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CoordSol::updateDraw)) {
                *result = 0;
            }
        }
        {
            typedef void (CoordSol::*_t)(QStringList , string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CoordSol::drawSurface)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CoordSol::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CoordSol.data,
      qt_meta_data_CoordSol,  qt_static_metacall, 0, 0}
};


const QMetaObject *CoordSol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoordSol::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoordSol.stringdata))
        return static_cast<void*>(const_cast< CoordSol*>(this));
    return QWidget::qt_metacast(_clname);
}

int CoordSol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CoordSol::updateDraw()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CoordSol::drawSurface(QStringList _t1, string _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
