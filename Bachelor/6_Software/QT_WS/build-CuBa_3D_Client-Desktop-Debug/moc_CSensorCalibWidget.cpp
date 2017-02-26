/****************************************************************************
** Meta object code from reading C++ file 'CSensorCalibWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_3D_Client/CSensorCalibWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSensorCalibWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSensorCalibWidget_t {
    QByteArrayData data[13];
    char stringdata[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CSensorCalibWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CSensorCalibWidget_t qt_meta_stringdata_CSensorCalibWidget = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 20),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 14),
QT_MOC_LITERAL(4, 56, 12),
QT_MOC_LITERAL(5, 69, 19),
QT_MOC_LITERAL(6, 89, 8),
QT_MOC_LITERAL(7, 98, 4),
QT_MOC_LITERAL(8, 103, 19),
QT_MOC_LITERAL(9, 123, 19),
QT_MOC_LITERAL(10, 143, 19),
QT_MOC_LITERAL(11, 163, 19),
QT_MOC_LITERAL(12, 183, 19)
    },
    "CSensorCalibWidget\0runSensorMeasurement\0"
    "\0endMeasurement\0startClicked\0"
    "sensor1DataReceived\0CMPUData\0data\0"
    "sensor2DataReceived\0sensor3DataReceived\0"
    "sensor4DataReceived\0sensor5DataReceived\0"
    "sensor6DataReceived\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSensorCalibWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,
       3,    0,   60,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a,
       5,    1,   62,    2, 0x0a,
       8,    1,   65,    2, 0x0a,
       9,    1,   68,    2, 0x0a,
      10,    1,   71,    2, 0x0a,
      11,    1,   74,    2, 0x0a,
      12,    1,   77,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void CSensorCalibWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSensorCalibWidget *_t = static_cast<CSensorCalibWidget *>(_o);
        switch (_id) {
        case 0: _t->runSensorMeasurement(); break;
        case 1: _t->endMeasurement(); break;
        case 2: _t->startClicked(); break;
        case 3: _t->sensor1DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 4: _t->sensor2DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 5: _t->sensor3DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 6: _t->sensor4DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 7: _t->sensor5DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 8: _t->sensor6DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSensorCalibWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorCalibWidget::runSensorMeasurement)) {
                *result = 0;
            }
        }
        {
            typedef void (CSensorCalibWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorCalibWidget::endMeasurement)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CSensorCalibWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CSensorCalibWidget.data,
      qt_meta_data_CSensorCalibWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CSensorCalibWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSensorCalibWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CSensorCalibWidget.stringdata))
        return static_cast<void*>(const_cast< CSensorCalibWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CSensorCalibWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CSensorCalibWidget::runSensorMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CSensorCalibWidget::endMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
