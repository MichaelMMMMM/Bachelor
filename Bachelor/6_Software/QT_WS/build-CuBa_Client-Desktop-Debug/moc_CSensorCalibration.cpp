/****************************************************************************
** Meta object code from reading C++ file 'CSensorCalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_Client/CSensorCalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSensorCalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSensorCalibration_t {
    QByteArrayData data[15];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSensorCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSensorCalibration_t qt_meta_stringdata_CSensorCalibration = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CSensorCalibration"
QT_MOC_LITERAL(1, 19, 25), // "startSensorCalibrationSIG"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 17), // "endMeasurementSIG"
QT_MOC_LITERAL(4, 64, 23), // "sensor1DataReceivedSLOT"
QT_MOC_LITERAL(5, 88, 4), // "time"
QT_MOC_LITERAL(6, 93, 8), // "CMPUData"
QT_MOC_LITERAL(7, 102, 23), // "sensor2DataReceivedSLOT"
QT_MOC_LITERAL(8, 126, 23), // "sensor3DataReceivedSLOT"
QT_MOC_LITERAL(9, 150, 23), // "sensor4DataReceivedSLOT"
QT_MOC_LITERAL(10, 174, 23), // "sensor5DataReceivedSLOT"
QT_MOC_LITERAL(11, 198, 23), // "sensor6DataReceivedSLOT"
QT_MOC_LITERAL(12, 222, 22), // "startButtonClickedSLOT"
QT_MOC_LITERAL(13, 245, 25), // "numberOfValuesChangedSLOT"
QT_MOC_LITERAL(14, 271, 8) // "newValue"

    },
    "CSensorCalibration\0startSensorCalibrationSIG\0"
    "\0endMeasurementSIG\0sensor1DataReceivedSLOT\0"
    "time\0CMPUData\0sensor2DataReceivedSLOT\0"
    "sensor3DataReceivedSLOT\0sensor4DataReceivedSLOT\0"
    "sensor5DataReceivedSLOT\0sensor6DataReceivedSLOT\0"
    "startButtonClickedSLOT\0numberOfValuesChangedSLOT\0"
    "newValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSensorCalibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   66,    2, 0x0a /* Public */,
       7,    2,   71,    2, 0x0a /* Public */,
       8,    2,   76,    2, 0x0a /* Public */,
       9,    2,   81,    2, 0x0a /* Public */,
      10,    2,   86,    2, 0x0a /* Public */,
      11,    2,   91,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, 0x80000000 | 6,    5,    2,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 6,    5,    2,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 6,    5,    2,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 6,    5,    2,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 6,    5,    2,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 6,    5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void CSensorCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSensorCalibration *_t = static_cast<CSensorCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSensorCalibrationSIG(); break;
        case 1: _t->endMeasurementSIG(); break;
        case 2: _t->sensor1DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 3: _t->sensor2DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 4: _t->sensor3DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 5: _t->sensor4DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 6: _t->sensor5DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 7: _t->sensor6DataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CMPUData(*)>(_a[2]))); break;
        case 8: _t->startButtonClickedSLOT(); break;
        case 9: _t->numberOfValuesChangedSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSensorCalibration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorCalibration::startSensorCalibrationSIG)) {
                *result = 0;
            }
        }
        {
            typedef void (CSensorCalibration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorCalibration::endMeasurementSIG)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CSensorCalibration::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CSensorCalibration.data,
      qt_meta_data_CSensorCalibration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSensorCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSensorCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSensorCalibration.stringdata0))
        return static_cast<void*>(const_cast< CSensorCalibration*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CSensorCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
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
void CSensorCalibration::startSensorCalibrationSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CSensorCalibration::endMeasurementSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
