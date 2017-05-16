/****************************************************************************
** Meta object code from reading C++ file 'CADCCalibrationWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_1D_Client/CADCCalibrationWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CADCCalibrationWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CADCCalibrationWidget_t {
    QByteArrayData data[12];
    char stringdata[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CADCCalibrationWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CADCCalibrationWidget_t qt_meta_stringdata_CADCCalibrationWidget = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 6),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 3),
QT_MOC_LITERAL(4, 34, 17),
QT_MOC_LITERAL(5, 52, 14),
QT_MOC_LITERAL(6, 67, 12),
QT_MOC_LITERAL(7, 80, 15),
QT_MOC_LITERAL(8, 96, 11),
QT_MOC_LITERAL(9, 108, 4),
QT_MOC_LITERAL(10, 113, 13),
QT_MOC_LITERAL(11, 127, 8)
    },
    "CADCCalibrationWidget\0setRPM\0\0rpm\0"
    "runADCMeasurement\0endMeasurement\0"
    "startClicked\0adcDataReceived\0CSensorData\0"
    "data\0setDatapoints\0newValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CADCCalibrationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       4,    0,   52,    2, 0x06,
       5,    0,   53,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x0a,
       7,    1,   55,    2, 0x0a,
      10,    1,   58,    2, 0x0a,
       1,    1,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void CADCCalibrationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CADCCalibrationWidget *_t = static_cast<CADCCalibrationWidget *>(_o);
        switch (_id) {
        case 0: _t->setRPM((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->runADCMeasurement(); break;
        case 2: _t->endMeasurement(); break;
        case 3: _t->startClicked(); break;
        case 4: _t->adcDataReceived((*reinterpret_cast< const CSensorData(*)>(_a[1]))); break;
        case 5: _t->setDatapoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setRPM((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CADCCalibrationWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibrationWidget::setRPM)) {
                *result = 0;
            }
        }
        {
            typedef void (CADCCalibrationWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibrationWidget::runADCMeasurement)) {
                *result = 1;
            }
        }
        {
            typedef void (CADCCalibrationWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CADCCalibrationWidget::endMeasurement)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CADCCalibrationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CADCCalibrationWidget.data,
      qt_meta_data_CADCCalibrationWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CADCCalibrationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CADCCalibrationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CADCCalibrationWidget.stringdata))
        return static_cast<void*>(const_cast< CADCCalibrationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CADCCalibrationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CADCCalibrationWidget::setRPM(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CADCCalibrationWidget::runADCMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CADCCalibrationWidget::endMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
