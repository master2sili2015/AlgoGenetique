/****************************************************************************
** Meta object code from reading C++ file 'ombrage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ombrage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ombrage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ombrage_t {
    QByteArrayData data[12];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Ombrage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Ombrage_t qt_meta_stringdata_Ombrage = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 11),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4),
QT_MOC_LITERAL(4, 26, 6),
QT_MOC_LITERAL(5, 33, 1),
QT_MOC_LITERAL(6, 35, 11),
QT_MOC_LITERAL(7, 47, 3),
QT_MOC_LITERAL(8, 51, 1),
QT_MOC_LITERAL(9, 53, 13),
QT_MOC_LITERAL(10, 67, 4),
QT_MOC_LITERAL(11, 72, 20)
    },
    "Ombrage\0surfaceDrow\0\0list\0string\0f\0"
    "updateColor\0col\0i\0setModeleFile\0file\0"
    "setZeniteAzimithFile\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ombrage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x08,
       6,    2,   39,    2, 0x08,
       9,    1,   44,    2, 0x08,
      11,    1,   47,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QColor, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 4,   10,
    QMetaType::Void, 0x80000000 | 4,   10,

       0        // eod
};

void Ombrage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ombrage *_t = static_cast<Ombrage *>(_o);
        switch (_id) {
        case 0: _t->surfaceDrow((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 1: _t->updateColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setModeleFile((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 3: _t->setZeniteAzimithFile((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Ombrage::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Ombrage.data,
      qt_meta_data_Ombrage,  qt_static_metacall, 0, 0}
};


const QMetaObject *Ombrage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ombrage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ombrage.stringdata))
        return static_cast<void*>(const_cast< Ombrage*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Ombrage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE