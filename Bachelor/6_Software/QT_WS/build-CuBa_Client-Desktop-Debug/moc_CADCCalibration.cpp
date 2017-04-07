/****************************************************************************
** Meta object code from reading C++ file 'CADCCalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_Client/CADCCalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CADCCalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CADCCalibration_t {
    QByteArrayData data[10];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CADCCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CADCCalibration_t qt_meta_stringdata_CADCCalibration = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CADCCalibration"
QT_MOC_LITERAL(1, 16, 22), // "startADCCalibrationSIG"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 17), // "endMeasurementSIG"
QT_MOC_LITERAL(4, 58, 25), // "numberOfValuesChangedSLOT"
QT_MOC_LITERAL(5, 84, 8), // "newValue"
QT_MOC_LITERAL(6, 93, 23), // "startButtonClickedLSLOT"
QT_MOC_LITERAL(7, 117, 19), // "adcDataReceivedSLOT"
QT_MOC_LITERAL(8, 137, 4), // "time"
QT_MOC_LITERAL(9, 142, 8) // "CADCData"

    },
    "CADCCalibration\0startADCCalibrationSIG\0"
    "\0endMeasurementSIG\0numberOfValuesChangedSLOT\0"
    "newValue\0startButtonClickedLSLOT\0"
    "adcDataReceivedSLOT\0time\0CADCData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CADCCalibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    2,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 9,    8,    2,

       0        // eod
};

void CADCCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CADCCalibration *_t = static_cast<CADCCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startADCCalibrationSIG(); break;
        case 1: _t->endMeasurementSIG(); break;
        case 2: _t->numberOfValuesChangedSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->startButtonClickedLSLOT(); break;
        case 4: _t->adcDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const CADCData(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CADCCalibration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibration::startADCCalibrationSIG)) {
                *result = 0;
            }
        }
        {
            typedef void (CADCCalibration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibration::endMeasurementSIG)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CADCCalibration::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CADCCalibration.data,
      qt_meta_data_CADCCalibration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CADCCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CADCCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CADCCalibration.stringdata0))
        return static_cast<void*>(const_cast< CADCCalibration*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CADCCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
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
void CADCCalibration::startADCCalibrationSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CADCCalibration::endMeasurementSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
