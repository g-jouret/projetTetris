/****************************************************************************
** Meta object code from reading C++ file 'mwtetris.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/mwtetris.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mwtetris.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MWTetris_t {
    QByteArrayData data[10];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MWTetris_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MWTetris_t qt_meta_stringdata_MWTetris = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MWTetris"
QT_MOC_LITERAL(1, 9, 10), // "createGame"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "quitGame"
QT_MOC_LITERAL(4, 30, 6), // "rotate"
QT_MOC_LITERAL(5, 37, 4), // "drop"
QT_MOC_LITERAL(6, 42, 4), // "left"
QT_MOC_LITERAL(7, 47, 5), // "right"
QT_MOC_LITERAL(8, 53, 4), // "time"
QT_MOC_LITERAL(9, 58, 4) // "next"

    },
    "MWTetris\0createGame\0\0quitGame\0rotate\0"
    "drop\0left\0right\0time\0next"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MWTetris[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MWTetris::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MWTetris *_t = static_cast<MWTetris *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createGame(); break;
        case 1: _t->quitGame(); break;
        case 2: _t->rotate(); break;
        case 3: _t->drop(); break;
        case 4: _t->left(); break;
        case 5: _t->right(); break;
        case 6: _t->time(); break;
        case 7: _t->next(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MWTetris::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MWTetris.data,
      qt_meta_data_MWTetris,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MWTetris::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MWTetris::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MWTetris.stringdata0))
        return static_cast<void*>(const_cast< MWTetris*>(this));
    if (!strcmp(_clname, "GJ_GW::Observer"))
        return static_cast< GJ_GW::Observer*>(const_cast< MWTetris*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MWTetris::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
