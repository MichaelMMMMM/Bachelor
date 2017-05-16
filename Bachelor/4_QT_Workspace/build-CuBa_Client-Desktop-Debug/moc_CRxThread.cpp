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
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CRxThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CRxThread_t {
    QByteArrayData data[36];
    char stringdata0[584];
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
QT_MOC_LITERAL(13, 178, 24), // "CompLQR1DDataReceivedSIG"
QT_MOC_LITERAL(14, 203, 15), // "QVector<double>"
QT_MOC_LITERAL(15, 219, 25), // "PhiObsLQR1DDataReceiveSIG"
QT_MOC_LITERAL(16, 245, 27), // "FullObsLQR1DDataReceivedSIG"
QT_MOC_LITERAL(17, 273, 23), // "CompLQR3DPhiReceivedSIG"
QT_MOC_LITERAL(18, 297, 3), // "phi"
QT_MOC_LITERAL(19, 301, 22), // "CompLQR3DUKReceivedSIG"
QT_MOC_LITERAL(20, 324, 2), // "uk"
QT_MOC_LITERAL(21, 327, 22), // "CompLQR3DURReceivedSIG"
QT_MOC_LITERAL(22, 350, 2), // "ur"
QT_MOC_LITERAL(23, 353, 22), // "CompLQR3DTMReceivedSIG"
QT_MOC_LITERAL(24, 376, 2), // "tm"
QT_MOC_LITERAL(25, 379, 14), // "endMeasurement"
QT_MOC_LITERAL(26, 394, 20), // "runSensorCalibration"
QT_MOC_LITERAL(27, 415, 21), // "runADCCalibrationSLOT"
QT_MOC_LITERAL(28, 437, 18), // "runEdgeBalanceSLOT"
QT_MOC_LITERAL(29, 456, 20), // "runCornerBalanceSLOT"
QT_MOC_LITERAL(30, 477, 16), // "setPhiOffsetSLOT"
QT_MOC_LITERAL(31, 494, 15), // "setUKOffsetSLOT"
QT_MOC_LITERAL(32, 510, 15), // "setUROffsetSLOT"
QT_MOC_LITERAL(33, 526, 23), // "selectControlSystemSLOT"
QT_MOC_LITERAL(34, 550, 16), // "E1DControlSystem"
QT_MOC_LITERAL(35, 567, 16) // "reloadConfigSLOT"

    },
    "CRxThread\0sensor1DataReceived\0\0time\0"
    "CMPUData\0data\0sensor2DataReceived\0"
    "sensor3DataReceived\0sensor4DataReceived\0"
    "sensor5DataReceived\0sensor6DataReceived\0"
    "adcDataReceivedSIG\0CADCData\0"
    "CompLQR1DDataReceivedSIG\0QVector<double>\0"
    "PhiObsLQR1DDataReceiveSIG\0"
    "FullObsLQR1DDataReceivedSIG\0"
    "CompLQR3DPhiReceivedSIG\0phi\0"
    "CompLQR3DUKReceivedSIG\0uk\0"
    "CompLQR3DURReceivedSIG\0ur\0"
    "CompLQR3DTMReceivedSIG\0tm\0endMeasurement\0"
    "runSensorCalibration\0runADCCalibrationSLOT\0"
    "runEdgeBalanceSLOT\0runCornerBalanceSLOT\0"
    "setPhiOffsetSLOT\0setUKOffsetSLOT\0"
    "setUROffsetSLOT\0selectControlSystemSLOT\0"
    "E1DControlSystem\0reloadConfigSLOT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRxThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  134,    2, 0x06 /* Public */,
       6,    2,  139,    2, 0x06 /* Public */,
       7,    2,  144,    2, 0x06 /* Public */,
       8,    2,  149,    2, 0x06 /* Public */,
       9,    2,  154,    2, 0x06 /* Public */,
      10,    2,  159,    2, 0x06 /* Public */,
      11,    2,  164,    2, 0x06 /* Public */,
      13,    2,  169,    2, 0x06 /* Public */,
      15,    2,  174,    2, 0x06 /* Public */,
      16,    2,  179,    2, 0x06 /* Public */,
      17,    2,  184,    2, 0x06 /* Public */,
      19,    2,  189,    2, 0x06 /* Public */,
      21,    2,  194,    2, 0x06 /* Public */,
      23,    2,  199,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    0,  204,    2, 0x0a /* Public */,
      26,    0,  205,    2, 0x0a /* Public */,
      27,    0,  206,    2, 0x0a /* Public */,
      28,    0,  207,    2, 0x0a /* Public */,
      29,    0,  208,    2, 0x0a /* Public */,
      30,    1,  209,    2, 0x0a /* Public */,
      31,    1,  212,    2, 0x0a /* Public */,
      32,    1,  215,    2, 0x0a /* Public */,
      33,    1,  218,    2, 0x0a /* Public */,
      35,    0,  221,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 12,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,    5,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,   18,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,   20,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,   22,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 14,    3,   24,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
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
        case 7: _t->CompLQR1DDataReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 8: _t->PhiObsLQR1DDataReceiveSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 9: _t->FullObsLQR1DDataReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 10: _t->CompLQR3DPhiReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 11: _t->CompLQR3DUKReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 12: _t->CompLQR3DURReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 13: _t->CompLQR3DTMReceivedSIG((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 14: _t->endMeasurement(); break;
        case 15: _t->runSensorCalibration(); break;
        case 16: _t->runADCCalibrationSLOT(); break;
        case 17: _t->runEdgeBalanceSLOT(); break;
        case 18: _t->runCornerBalanceSLOT(); break;
        case 19: _t->setPhiOffsetSLOT((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->setUKOffsetSLOT((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->setUROffsetSLOT((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->selectControlSystemSLOT((*reinterpret_cast< E1DControlSystem(*)>(_a[1]))); break;
        case 23: _t->reloadConfigSLOT(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
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
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::CompLQR1DDataReceivedSIG)) {
                *result = 7;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::PhiObsLQR1DDataReceiveSIG)) {
                *result = 8;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::FullObsLQR1DDataReceivedSIG)) {
                *result = 9;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::CompLQR3DPhiReceivedSIG)) {
                *result = 10;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::CompLQR3DUKReceivedSIG)) {
                *result = 11;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::CompLQR3DURReceivedSIG)) {
                *result = 12;
            }
        }
        {
            typedef void (CRxThread::*_t)(double , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::CompLQR3DTMReceivedSIG)) {
                *result = 13;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
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

// SIGNAL 7
void CRxThread::CompLQR1DDataReceivedSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CRxThread::PhiObsLQR1DDataReceiveSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CRxThread::FullObsLQR1DDataReceivedSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CRxThread::CompLQR3DPhiReceivedSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CRxThread::CompLQR3DUKReceivedSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CRxThread::CompLQR3DURReceivedSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CRxThread::CompLQR3DTMReceivedSIG(double _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
