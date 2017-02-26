/****************************************************************************
** Meta object code from reading C++ file 'CRxThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_3D_Client/CRxThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CRxThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CRxThread_t {
    QByteArrayData data[28];
    char stringdata[395];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CRxThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CRxThread_t qt_meta_stringdata_CRxThread = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 19),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 8),
QT_MOC_LITERAL(4, 40, 4),
QT_MOC_LITERAL(5, 45, 19),
QT_MOC_LITERAL(6, 65, 19),
QT_MOC_LITERAL(7, 85, 19),
QT_MOC_LITERAL(8, 105, 19),
QT_MOC_LITERAL(9, 125, 19),
QT_MOC_LITERAL(10, 145, 15),
QT_MOC_LITERAL(11, 161, 8),
QT_MOC_LITERAL(12, 170, 13),
QT_MOC_LITERAL(13, 184, 6),
QT_MOC_LITERAL(14, 191, 14),
QT_MOC_LITERAL(15, 206, 7),
QT_MOC_LITERAL(16, 214, 14),
QT_MOC_LITERAL(17, 229, 7),
QT_MOC_LITERAL(18, 237, 18),
QT_MOC_LITERAL(19, 256, 11),
QT_MOC_LITERAL(20, 268, 14),
QT_MOC_LITERAL(21, 283, 20),
QT_MOC_LITERAL(22, 304, 17),
QT_MOC_LITERAL(23, 322, 14),
QT_MOC_LITERAL(24, 337, 9),
QT_MOC_LITERAL(25, 347, 17),
QT_MOC_LITERAL(26, 365, 4),
QT_MOC_LITERAL(27, 370, 23)
    },
    "CRxThread\0sensor1DataReceived\0\0CMPUData\0"
    "data\0sensor2DataReceived\0sensor3DataReceived\0"
    "sensor4DataReceived\0sensor5DataReceived\0"
    "sensor6DataReceived\0adcDataReceived\0"
    "CADCData\0gDataReceived\0CGData\0"
    "ukDataReceived\0CUKData\0urDataReceived\0"
    "CURData\0torqueDataReceived\0CTorqueData\0"
    "endMeasurement\0runSensorCalibration\0"
    "runADCCalibration\0runControlTest\0"
    "setTorque\0setCompFilterFlag\0flag\0"
    "setOffsetCorrectionFlag\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRxThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06,
       5,    1,  107,    2, 0x06,
       6,    1,  110,    2, 0x06,
       7,    1,  113,    2, 0x06,
       8,    1,  116,    2, 0x06,
       9,    1,  119,    2, 0x06,
      10,    1,  122,    2, 0x06,
      12,    1,  125,    2, 0x06,
      14,    1,  128,    2, 0x06,
      16,    1,  131,    2, 0x06,
      18,    1,  134,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      20,    0,  137,    2, 0x0a,
      21,    0,  138,    2, 0x0a,
      22,    0,  139,    2, 0x0a,
      23,    0,  140,    2, 0x0a,
      24,    1,  141,    2, 0x0a,
      25,    1,  144,    2, 0x0a,
      27,    1,  147,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 11,    4,
    QMetaType::Void, 0x80000000 | 13,    4,
    QMetaType::Void, 0x80000000 | 15,    4,
    QMetaType::Void, 0x80000000 | 17,    4,
    QMetaType::Void, 0x80000000 | 19,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    4,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,

       0        // eod
};

void CRxThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRxThread *_t = static_cast<CRxThread *>(_o);
        switch (_id) {
        case 0: _t->sensor1DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 1: _t->sensor2DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 2: _t->sensor3DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 3: _t->sensor4DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 4: _t->sensor5DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 5: _t->sensor6DataReceived((*reinterpret_cast< const CMPUData(*)>(_a[1]))); break;
        case 6: _t->adcDataReceived((*reinterpret_cast< const CADCData(*)>(_a[1]))); break;
        case 7: _t->gDataReceived((*reinterpret_cast< const CGData(*)>(_a[1]))); break;
        case 8: _t->ukDataReceived((*reinterpret_cast< const CUKData(*)>(_a[1]))); break;
        case 9: _t->urDataReceived((*reinterpret_cast< const CURData(*)>(_a[1]))); break;
        case 10: _t->torqueDataReceived((*reinterpret_cast< const CTorqueData(*)>(_a[1]))); break;
        case 11: _t->endMeasurement(); break;
        case 12: _t->runSensorCalibration(); break;
        case 13: _t->runADCCalibration(); break;
        case 14: _t->runControlTest(); break;
        case 15: _t->setTorque((*reinterpret_cast< const CTorqueData(*)>(_a[1]))); break;
        case 16: _t->setCompFilterFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setOffsetCorrectionFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CRxThread::*_t)(const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor1DataReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor2DataReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor3DataReceived)) {
                *result = 2;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor4DataReceived)) {
                *result = 3;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor5DataReceived)) {
                *result = 4;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor6DataReceived)) {
                *result = 5;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CADCData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::adcDataReceived)) {
                *result = 6;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CGData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::gDataReceived)) {
                *result = 7;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CUKData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::ukDataReceived)) {
                *result = 8;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CURData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::urDataReceived)) {
                *result = 9;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CTorqueData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::torqueDataReceived)) {
                *result = 10;
            }
        }
    }
}

const QMetaObject CRxThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CRxThread.data,
      qt_meta_data_CRxThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *CRxThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRxThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CRxThread.stringdata))
        return static_cast<void*>(const_cast< CRxThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CRxThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void CRxThread::sensor1DataReceived(const CMPUData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CRxThread::sensor2DataReceived(const CMPUData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CRxThread::sensor3DataReceived(const CMPUData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CRxThread::sensor4DataReceived(const CMPUData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CRxThread::sensor5DataReceived(const CMPUData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CRxThread::sensor6DataReceived(const CMPUData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CRxThread::adcDataReceived(const CADCData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CRxThread::gDataReceived(const CGData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CRxThread::ukDataReceived(const CUKData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CRxThread::urDataReceived(const CURData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CRxThread::torqueDataReceived(const CTorqueData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
