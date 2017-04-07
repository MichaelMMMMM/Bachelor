/****************************************************************************
** Meta object code from reading C++ file 'CRxThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_Client/CRxThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CRxThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CRxThread_t {
    QByteArrayData data[16];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRxThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRxThread_t qt_meta_stringdata_CRxThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CRxThread"
QT_MOC_LITERAL(1, 10, 19), // "sensor1DataReceived"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "time"
QT_MOC_LITERAL(4, 36, 8), // "CMPUData"
QT_MOC_LITERAL(5, 45, 4), // "data"
QT_MOC_LITERAL(6, 50, 19), // "sensor2DataReceived"
QT_MOC_LITERAL(7, 70, 19), // "sensor3DataReceived"
QT_MOC_LITERAL(8, 90, 19), // "sensor4DataReceived"
QT_MOC_LITERAL(9, 110, 19), // "sensor5DataReceived"
QT_MOC_LITERAL(10, 130, 19), // "sensor6DataReceived"
QT_MOC_LITERAL(11, 150, 18), // "adcDataReceivedSIG"
QT_MOC_LITERAL(12, 169, 8), // "CADCData"
QT_MOC_LITERAL(13, 178, 14), // "endMeasurement"
QT_MOC_LITERAL(14, 193, 20), // "runSensorCalibration"
QT_MOC_LITERAL(15, 214, 21) // "runADCCalibrationSLOT"

    },
    "CRxThread\0sensor1DataReceived\0\0time\0"
    "CMPUData\0data\0sensor2DataReceived\0"
    "sensor3DataReceived\0sensor4DataReceived\0"
    "sensor5DataReceived\0sensor6DataReceived\0"
    "adcDataReceivedSIG\0CADCData\0endMeasurement\0"
    "runSensorCalibration\0runADCCalibrationSLOT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRxThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       6,    2,   69,    2, 0x06 /* Public */,
       7,    2,   74,    2, 0x06 /* Public */,
       8,    2,   79,    2, 0x06 /* Public */,
       9,    2,   84,    2, 0x06 /* Public */,
      10,    2,   89,    2, 0x06 /* Public */,
      11,    2,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 12,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRxThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRxThread *_t = static_cast<CRxThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sensor1DataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 1: _t->sensor2DataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 2: _t->sensor3DataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 3: _t->sensor4DataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 4: _t->sensor5DataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 5: _t->sensor6DataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 6: _t->adcDataReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CADCData(*)>(_a[2]))); break;
        case 7: _t->endMeasurement(); break;
        case 8: _t->runSensorCalibration(); break;
        case 9: _t->runADCCalibrationSLOT(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CRxThread::*_t)(double , const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor1DataReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor2DataReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor3DataReceived)) {
                *result = 2;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor4DataReceived)) {
                *result = 3;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor5DataReceived)) {
                *result = 4;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , const CMPUData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensor6DataReceived)) {
                *result = 5;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , const CADCData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::adcDataReceivedSIG)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject CRxThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CRxThread.data,
      qt_meta_data_CRxThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CRxThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRxThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CRxThread.stringdata0))
        return static_cast<void*>(const_cast< CRxThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CRxThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CRxThread::sensor1DataReceived(double _t1, const CMPUData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CRxThread::sensor2DataReceived(double _t1, const CMPUData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CRxThread::sensor3DataReceived(double _t1, const CMPUData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CRxThread::sensor4DataReceived(double _t1, const CMPUData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CRxThread::sensor5DataReceived(double _t1, const CMPUData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CRxThread::sensor6DataReceived(double _t1, const CMPUData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CRxThread::adcDataReceivedSIG(double _t1, const CADCData & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
