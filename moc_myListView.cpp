/****************************************************************************
** Meta object code from reading C++ file 'myListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyListView_t {
    QByteArrayData data[20];
    char stringdata[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyListView_t qt_meta_stringdata_MyListView = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 6),
QT_MOC_LITERAL(4, 30, 4),
QT_MOC_LITERAL(5, 35, 11),
QT_MOC_LITERAL(6, 47, 14),
QT_MOC_LITERAL(7, 62, 14),
QT_MOC_LITERAL(8, 77, 9),
QT_MOC_LITERAL(9, 87, 14),
QT_MOC_LITERAL(10, 102, 11),
QT_MOC_LITERAL(11, 114, 14),
QT_MOC_LITERAL(12, 129, 12),
QT_MOC_LITERAL(13, 142, 4),
QT_MOC_LITERAL(14, 147, 8),
QT_MOC_LITERAL(15, 156, 6),
QT_MOC_LITERAL(16, 163, 8),
QT_MOC_LITERAL(17, 172, 18),
QT_MOC_LITERAL(18, 191, 4),
QT_MOC_LITERAL(19, 196, 18)
    },
    "MyListView\0updateFile\0\0string\0draw\0"
    "drowSurface\0selectItemSlot\0QItemSelection\0"
    "selection\0insertItemSlot\0addItemSlot\0"
    "deleteItemSlot\0rafraichDraw\0save\0"
    "openFile\0upSlot\0downSlot\0textLineEdit1Valid\0"
    "text\0textLineEdit2Valid\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06,
       4,    1,   87,    2, 0x06,
       5,    2,   90,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   95,    2, 0x08,
       9,    0,   98,    2, 0x08,
      10,    0,   99,    2, 0x08,
      11,    0,  100,    2, 0x08,
      12,    0,  101,    2, 0x08,
      13,    0,  102,    2, 0x08,
      14,    0,  103,    2, 0x08,
      15,    0,  104,    2, 0x08,
      16,    0,  105,    2, 0x08,
      17,    1,  106,    2, 0x08,
      19,    1,  109,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void MyListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyListView *_t = static_cast<MyListView *>(_o);
        switch (_id) {
        case 0: _t->updateFile((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->draw((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->drowSurface((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 3: _t->selectItemSlot((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 4: _t->insertItemSlot(); break;
        case 5: _t->addItemSlot(); break;
        case 6: _t->deleteItemSlot(); break;
        case 7: _t->rafraichDraw(); break;
        case 8: _t->save(); break;
        case 9: _t->openFile(); break;
        case 10: _t->upSlot(); break;
        case 11: _t->downSlot(); break;
        case 12: _t->textLineEdit1Valid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->textLineEdit2Valid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyListView::*_t)(string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyListView::updateFile)) {
                *result = 0;
            }
        }
        {
            typedef void (MyListView::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyListView::draw)) {
                *result = 1;
            }
        }
        {
            typedef void (MyListView::*_t)(QStringList , string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyListView::drowSurface)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MyListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyListView.data,
      qt_meta_data_MyListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyListView.stringdata))
        return static_cast<void*>(const_cast< MyListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyListView::updateFile(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyListView::draw(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyListView::drowSurface(QStringList _t1, string _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
