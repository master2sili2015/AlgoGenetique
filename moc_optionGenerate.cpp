/****************************************************************************
** Meta object code from reading C++ file 'optionGenerate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionGenerate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionGenerate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OptionGenerate_t {
    QByteArrayData data[11];
    char stringdata[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_OptionGenerate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_OptionGenerate_t qt_meta_stringdata_OptionGenerate = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 20),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 5),
QT_MOC_LITERAL(4, 43, 22),
QT_MOC_LITERAL(5, 66, 24),
QT_MOC_LITERAL(6, 91, 4),
QT_MOC_LITERAL(7, 96, 12),
QT_MOC_LITERAL(8, 109, 20),
QT_MOC_LITERAL(9, 130, 18),
QT_MOC_LITERAL(10, 149, 22)
    },
    "OptionGenerate\0fitnessHeuristicSlot\0"
    "\0index\0selectionHeuristicSlot\0"
    "mutationProbabilityValid\0text\0"
    "popSizeValid\0fitnessTresholdValid\0"
    "selectionSizeValid\0childrenPerCoupleValid\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionGenerate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08,
       4,    1,   52,    2, 0x08,
       5,    1,   55,    2, 0x08,
       7,    1,   58,    2, 0x08,
       8,    1,   61,    2, 0x08,
       9,    1,   64,    2, 0x08,
      10,    1,   67,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void OptionGenerate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionGenerate *_t = static_cast<OptionGenerate *>(_o);
        switch (_id) {
        case 0: _t->fitnessHeuristicSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->selectionHeuristicSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mutationProbabilityValid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->popSizeValid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->fitnessTresholdValid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->selectionSizeValid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->childrenPerCoupleValid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject OptionGenerate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionGenerate.data,
      qt_meta_data_OptionGenerate,  qt_static_metacall, 0, 0}
};


const QMetaObject *OptionGenerate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionGenerate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionGenerate.stringdata))
        return static_cast<void*>(const_cast< OptionGenerate*>(this));
    return QWidget::qt_metacast(_clname);
}

int OptionGenerate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
