/****************************************************************************
** Meta object code from reading C++ file 'CSensorCalibrationWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_1D_Client/CSensorCalibrationWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSensorCalibrationWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSensorCalibrationWidget_t {
    QByteArrayData data[9];
    char stringdata[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CSensorCalibrationWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CSensorCalibrationWidget_t qt_meta_stringdata_CSensorCalibrationWidget = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 16),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 14),
QT_MOC_LITERAL(4, 58, 23),
QT_MOC_LITERAL(5, 82, 19),
QT_MOC_LITERAL(6, 102, 18),
QT_MOC_LITERAL(7, 121, 11),
QT_MOC_LITERAL(8, 133, 4)
    },
    "CSensorCalibrationWidget\0startMeasurement\0"
    "\0endMeasurement\0startMeasurementClicked\0"
    "measurementFinished\0sensorDataReceived\0"
    "CSensorData\0data\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSensorCalibrationWidget[] = {

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
       1,    0,   39,    2, 0x06,
       3,    0,   40,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a,
       5,    0,   42,    2, 0x0a,
       6,    1,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void CSensorCalibrationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSensorCalibrationWidget *_t = static_cast<CSensorCalibrationWidget *>(_o);
        switch (_id) {
        case 0: _t->startMeasurement(); break;
        case 1: _t->endMeasurement(); break;
        case 2: _t->startMeasurementClicked(); break;
        case 3: _t->measurementFinished(); break;
        case 4: _t->sensorDataReceived((*reinterpret_cast< const CSensorData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSensorCalibrationWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorCalibrationWidget::startMeasurement)) {
                *result = 0;
            }
        }
        {
            typedef void (CSensorCalibrationWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensorCalibrationWidget::endMeasurement)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CSensorCalibrationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CSensorCalibrationWidget.data,
      qt_meta_data_CSensorCalibrationWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CSensorCalibrationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSensorCalibrationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CSensorCalibrationWidget.stringdata))
        return static_cast<void*>(const_cast< CSensorCalibrationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CSensorCalibrationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CSensorCalibrationWidget::startMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CSensorCalibrationWidget::endMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
