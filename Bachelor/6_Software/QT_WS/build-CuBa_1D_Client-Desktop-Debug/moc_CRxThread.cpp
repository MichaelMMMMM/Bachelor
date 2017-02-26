/****************************************************************************
** Meta object code from reading C++ file 'CRxThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_1D_Client/CRxThread.h"
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
    char stringdata[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CRxThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CRxThread_t qt_meta_stringdata_CRxThread = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 18),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 11),
QT_MOC_LITERAL(4, 42, 4),
QT_MOC_LITERAL(5, 47, 15),
QT_MOC_LITERAL(6, 63, 15),
QT_MOC_LITERAL(7, 79, 4),
QT_MOC_LITERAL(8, 84, 18),
QT_MOC_LITERAL(9, 103, 7),
QT_MOC_LITERAL(10, 111, 18),
QT_MOC_LITERAL(11, 130, 7),
QT_MOC_LITERAL(12, 138, 14),
QT_MOC_LITERAL(13, 153, 20),
QT_MOC_LITERAL(14, 174, 17),
QT_MOC_LITERAL(15, 192, 6),
QT_MOC_LITERAL(16, 199, 3),
QT_MOC_LITERAL(17, 203, 14),
QT_MOC_LITERAL(18, 218, 16),
QT_MOC_LITERAL(19, 235, 6),
QT_MOC_LITERAL(20, 242, 19),
QT_MOC_LITERAL(21, 262, 19),
QT_MOC_LITERAL(22, 282, 13),
QT_MOC_LITERAL(23, 296, 7),
QT_MOC_LITERAL(24, 304, 6),
QT_MOC_LITERAL(25, 311, 19),
QT_MOC_LITERAL(26, 331, 4),
QT_MOC_LITERAL(27, 336, 14)
    },
    "CRxThread\0sensorDataReceived\0\0CSensorData\0"
    "data\0adcDataReceived\0phiDataReceived\0"
    "CPhi\0phi__dDataReceived\0CPhi__d\0"
    "psi__dDataReceived\0CPsi__d\0endMeasurement\0"
    "runSensorMeasurement\0runADCMeasurement\0"
    "setRPM\0rpm\0runControlTest\0phiOffsetChanged\0"
    "offset\0phi__dOffsetChanged\0"
    "psi__dOffsetChanged\0filterChanged\0"
    "EFilter\0filter\0highpassFlagChanged\0"
    "flag\0lqrFlagChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRxThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06,
       5,    1,   97,    2, 0x06,
       6,    1,  100,    2, 0x06,
       8,    1,  103,    2, 0x06,
      10,    1,  106,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    0,  109,    2, 0x0a,
      13,    0,  110,    2, 0x0a,
      14,    0,  111,    2, 0x0a,
      15,    1,  112,    2, 0x0a,
      17,    0,  115,    2, 0x0a,
      18,    1,  116,    2, 0x0a,
      20,    1,  119,    2, 0x0a,
      21,    1,  122,    2, 0x0a,
      22,    1,  125,    2, 0x0a,
      25,    1,  128,    2, 0x0a,
      27,    1,  131,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    4,
    QMetaType::Void, 0x80000000 | 9,    4,
    QMetaType::Void, 0x80000000 | 11,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   19,
    QMetaType::Void, QMetaType::Float,   19,
    QMetaType::Void, QMetaType::Float,   19,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,

       0        // eod
};

void CRxThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRxThread *_t = static_cast<CRxThread *>(_o);
        switch (_id) {
        case 0: _t->sensorDataReceived((*reinterpret_cast< const CSensorData(*)>(_a[1]))); break;
        case 1: _t->adcDataReceived((*reinterpret_cast< const CSensorData(*)>(_a[1]))); break;
        case 2: _t->phiDataReceived((*reinterpret_cast< const CPhi(*)>(_a[1]))); break;
        case 3: _t->phi__dDataReceived((*reinterpret_cast< const CPhi__d(*)>(_a[1]))); break;
        case 4: _t->psi__dDataReceived((*reinterpret_cast< const CPsi__d(*)>(_a[1]))); break;
        case 5: _t->endMeasurement(); break;
        case 6: _t->runSensorMeasurement(); break;
        case 7: _t->runADCMeasurement(); break;
        case 8: _t->setRPM((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->runControlTest(); break;
        case 10: _t->phiOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->phi__dOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->psi__dOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->filterChanged((*reinterpret_cast< EFilter(*)>(_a[1]))); break;
        case 14: _t->highpassFlagChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->lqrFlagChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CRxThread::*_t)(const CSensorData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::sensorDataReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CSensorData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::adcDataReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CPhi & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::phiDataReceived)) {
                *result = 2;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CPhi__d & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::phi__dDataReceived)) {
                *result = 3;
            }
        }
        {
            typedef void (CRxThread::*_t)(const CPsi__d & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRxThread::psi__dDataReceived)) {
                *result = 4;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void CRxThread::sensorDataReceived(const CSensorData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CRxThread::adcDataReceived(const CSensorData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CRxThread::phiDataReceived(const CPhi & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CRxThread::phi__dDataReceived(const CPhi__d & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CRxThread::psi__dDataReceived(const CPsi__d & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
