/****************************************************************************
** Meta object code from reading C++ file 'CADCWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_3D_Client/CADCWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CADCWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CADCCalibWidget_t {
    QByteArrayData data[10];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CADCCalibWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CADCCalibWidget_t qt_meta_stringdata_CADCCalibWidget = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 13),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 11),
QT_MOC_LITERAL(4, 43, 9),
QT_MOC_LITERAL(5, 53, 11),
QT_MOC_LITERAL(6, 65, 4),
QT_MOC_LITERAL(7, 70, 12),
QT_MOC_LITERAL(8, 83, 17),
QT_MOC_LITERAL(9, 101, 8)
    },
    "CADCCalibWidget\0startADCCalib\0\0"
    "endADCCalib\0setTorque\0CTorqueData\0"
    "data\0startClicked\0onADCDataReceived\0"
    "CADCData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CADCCalibWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06,
       3,    0,   40,    2, 0x06,
       4,    1,   41,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    2, 0x0a,
       8,    1,   45,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void CADCCalibWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CADCCalibWidget *_t = static_cast<CADCCalibWidget *>(_o);
        switch (_id) {
        case 0: _t->startADCCalib(); break;
        case 1: _t->endADCCalib(); break;
        case 2: _t->setTorque((*reinterpret_cast< const CTorqueData(*)>(_a[1]))); break;
        case 3: _t->startClicked(); break;
        case 4: _t->onADCDataReceived((*reinterpret_cast< const CADCData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CADCCalibWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibWidget::startADCCalib)) {
                *result = 0;
            }
        }
        {
            typedef void (CADCCalibWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibWidget::endADCCalib)) {
                *result = 1;
            }
        }
        {
            typedef void (CADCCalibWidget::*_t)(const CTorqueData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibWidget::setTorque)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CADCCalibWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CADCCalibWidget.data,
      qt_meta_data_CADCCalibWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CADCCalibWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CADCCalibWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CADCCalibWidget.stringdata))
        return static_cast<void*>(const_cast< CADCCalibWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CADCCalibWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CADCCalibWidget::startADCCalib()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CADCCalibWidget::endADCCalib()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CADCCalibWidget::setTorque(const CTorqueData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
