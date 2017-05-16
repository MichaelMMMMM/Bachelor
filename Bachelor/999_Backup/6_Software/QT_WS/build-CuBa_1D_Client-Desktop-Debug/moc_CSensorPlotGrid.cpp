/****************************************************************************
** Meta object code from reading C++ file 'CSensorPlotGrid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_1D_Client/CSensorPlotGrid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSensorPlotGrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSensorPlotGrid_t {
    QByteArrayData data[6];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CSensorPlotGrid_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CSensorPlotGrid_t qt_meta_stringdata_CSensorPlotGrid = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 19),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 21),
QT_MOC_LITERAL(4, 59, 8),
QT_MOC_LITERAL(5, 68, 11)
    },
    "CSensorPlotGrid\0measurementFinished\0"
    "\0setNumberOfDatapoints\0newValue\0"
    "setPhiValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSensorPlotGrid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a,
       5,    1,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void CSensorPlotGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSensorPlotGrid *_t = static_cast<CSensorPlotGrid *>(_o);
        switch (_id) {
        case 0: _t->measurementFinished(); break;
        case 1: _t->setNumberOfDatapoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setPhiValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSensorPlotGrid::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorPlotGrid::measurementFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CSensorPlotGrid::staticMetaObject = {
    { &QGridLayout::staticMetaObject, qt_meta_stringdata_CSensorPlotGrid.data,
      qt_meta_data_CSensorPlotGrid,  qt_static_metacall, 0, 0}
};


const QMetaObject *CSensorPlotGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSensorPlotGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CSensorPlotGrid.stringdata))
        return static_cast<void*>(const_cast< CSensorPlotGrid*>(this));
    return QGridLayout::qt_metacast(_clname);
}

int CSensorPlotGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CSensorPlotGrid::measurementFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
