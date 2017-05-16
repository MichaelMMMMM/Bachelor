/****************************************************************************
** Meta object code from reading C++ file 'CSensorCalibWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_3D_Client/CSensorCalibWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSensorCalibWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSensorCalibWidget_t {
    QByteArrayData data[13];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSensorCalibWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSensorCalibWidget_t qt_meta_stringdata_CSensorCalibWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CSensorCalibWidget"
QT_MOC_LITERAL(1, 19, 20), // "runSensorMeasurement"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 14), // "endMeasurement"
QT_MOC_LITERAL(4, 56, 12), // "startClicked"
QT_MOC_LITERAL(5, 69, 19), // "sensor1DataReceived"
QT_MOC_LITERAL(6, 89, 8), // "CMPUData"
QT_MOC_LITERAL(7, 98, 4), // "data"
QT_MOC_LITERAL(8, 103, 19), // "sensor2DataReceived"
QT_MOC_LITERAL(9, 123, 19), // "sensor3DataReceived"
QT_MOC_LITERAL(10, 143, 19), // "sensor4DataReceived"
QT_MOC_LITERAL(11, 163, 19), // "sensor5DataReceived"
QT_MOC_LITERAL(12, 183, 19) // "sensor6DataReceived"

    },
    "CSensorCalibWidget\0runSensorMeasurement\0"
    "\0endMeasurement\0startClicked\0"
    "sensor1DataReceived\0CMPUData\0data\0"
    "sensor2DataReceived\0sensor3DataReceived\0"
    "sensor4DataReceived\0sensor5DataReceived\0"
    "sensor6DataReceived"
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
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,

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
        Q_UNUSED(_t)
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
      qt_meta_data_CSensorCalibWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSensorCalibWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSensorCalibWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSensorCalibWidget.stringdata0))
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
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CSensorCalibWidget::endMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
