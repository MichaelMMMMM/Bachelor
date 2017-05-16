/****************************************************************************
** Meta object code from reading C++ file 'CEdgeBalance.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_Client/CEdgeBalance.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CEdgeBalance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CEdgeBalance_t {
    QByteArrayData data[22];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CEdgeBalance_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CEdgeBalance_t qt_meta_stringdata_CEdgeBalance = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CEdgeBalance"
QT_MOC_LITERAL(1, 13, 17), // "runEdgeBalanceSIG"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "stopEdgeBalanceSIG"
QT_MOC_LITERAL(4, 51, 15), // "setPhiOffsetSIG"
QT_MOC_LITERAL(5, 67, 14), // "setUKOffsetSIG"
QT_MOC_LITERAL(6, 82, 14), // "setUROffsetSIG"
QT_MOC_LITERAL(7, 97, 22), // "selectControlSystemSIG"
QT_MOC_LITERAL(8, 120, 16), // "E1DControlSystem"
QT_MOC_LITERAL(9, 137, 15), // "updateConfigSIG"
QT_MOC_LITERAL(10, 153, 25), // "compLQR1DDataReceivedSLOT"
QT_MOC_LITERAL(11, 179, 4), // "time"
QT_MOC_LITERAL(12, 184, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 200, 4), // "data"
QT_MOC_LITERAL(14, 205, 27), // "phiObsLQR1DDataReceivedSLOT"
QT_MOC_LITERAL(15, 233, 28), // "fullObsLQR1DDataReceivedSLOT"
QT_MOC_LITERAL(16, 262, 15), // "startButtonSLOT"
QT_MOC_LITERAL(17, 278, 14), // "saveButtonSLOT"
QT_MOC_LITERAL(18, 293, 16), // "offsetButtonSLOT"
QT_MOC_LITERAL(19, 310, 22), // "controlRadioButtonSLOT"
QT_MOC_LITERAL(20, 333, 22), // "updateConfigButtonSLOT"
QT_MOC_LITERAL(21, 356, 17) // "displayButtonSLOT"

    },
    "CEdgeBalance\0runEdgeBalanceSIG\0\0"
    "stopEdgeBalanceSIG\0setPhiOffsetSIG\0"
    "setUKOffsetSIG\0setUROffsetSIG\0"
    "selectControlSystemSIG\0E1DControlSystem\0"
    "updateConfigSIG\0compLQR1DDataReceivedSLOT\0"
    "time\0QVector<double>\0data\0"
    "phiObsLQR1DDataReceivedSLOT\0"
    "fullObsLQR1DDataReceivedSLOT\0"
    "startButtonSLOT\0saveButtonSLOT\0"
    "offsetButtonSLOT\0controlRadioButtonSLOT\0"
    "updateConfigButtonSLOT\0displayButtonSLOT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CEdgeBalance[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    1,   96,    2, 0x06 /* Public */,
       5,    1,   99,    2, 0x06 /* Public */,
       6,    1,  102,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
       9,    0,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,  109,    2, 0x0a /* Public */,
      14,    2,  114,    2, 0x0a /* Public */,
      15,    2,  119,    2, 0x0a /* Public */,
      16,    0,  124,    2, 0x0a /* Public */,
      17,    0,  125,    2, 0x0a /* Public */,
      18,    0,  126,    2, 0x0a /* Public */,
      19,    0,  127,    2, 0x0a /* Public */,
      20,    0,  128,    2, 0x0a /* Public */,
      21,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 12,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CEdgeBalance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CEdgeBalance *_t = static_cast<CEdgeBalance *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runEdgeBalanceSIG(); break;
        case 1: _t->stopEdgeBalanceSIG(); break;
        case 2: _t->setPhiOffsetSIG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setUKOffsetSIG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setUROffsetSIG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->selectControlSystemSIG((*reinterpret_cast< E1DControlSystem(*)>(_a[1]))); break;
        case 6: _t->updateConfigSIG(); break;
        case 7: _t->compLQR1DDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 8: _t->phiObsLQR1DDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 9: _t->fullObsLQR1DDataReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 10: _t->startButtonSLOT(); break;
        case 11: _t->saveButtonSLOT(); break;
        case 12: _t->offsetButtonSLOT(); break;
        case 13: _t->controlRadioButtonSLOT(); break;
        case 14: _t->updateConfigButtonSLOT(); break;
        case 15: _t->displayButtonSLOT(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CEdgeBalance::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::runEdgeBalanceSIG)) {
                *result = 0;
            }
        }
        {
            typedef void (CEdgeBalance::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::stopEdgeBalanceSIG)) {
                *result = 1;
            }
        }
        {
            typedef void (CEdgeBalance::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::setPhiOffsetSIG)) {
                *result = 2;
            }
        }
        {
            typedef void (CEdgeBalance::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::setUKOffsetSIG)) {
                *result = 3;
            }
        }
        {
            typedef void (CEdgeBalance::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::setUROffsetSIG)) {
                *result = 4;
            }
        }
        {
            typedef void (CEdgeBalance::*_t)(E1DControlSystem );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::selectControlSystemSIG)) {
                *result = 5;
            }
        }
        {
            typedef void (CEdgeBalance::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalance::updateConfigSIG)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject CEdgeBalance::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CEdgeBalance.data,
      qt_meta_data_CEdgeBalance,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CEdgeBalance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CEdgeBalance::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CEdgeBalance.stringdata0))
        return static_cast<void*>(const_cast< CEdgeBalance*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CEdgeBalance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CExperimentWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void CEdgeBalance::runEdgeBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CEdgeBalance::stopEdgeBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CEdgeBalance::setPhiOffsetSIG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CEdgeBalance::setUKOffsetSIG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CEdgeBalance::setUROffsetSIG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CEdgeBalance::selectControlSystemSIG(E1DControlSystem _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CEdgeBalance::updateConfigSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
