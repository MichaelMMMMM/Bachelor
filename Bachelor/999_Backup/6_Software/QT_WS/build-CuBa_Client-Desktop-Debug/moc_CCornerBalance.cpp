/****************************************************************************
** Meta object code from reading C++ file 'CCornerBalance.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_Client/CCornerBalance.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CCornerBalance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CCornerBalance_t {
    QByteArrayData data[15];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CCornerBalance_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CCornerBalance_t qt_meta_stringdata_CCornerBalance = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CCornerBalance"
QT_MOC_LITERAL(1, 15, 19), // "runCornerBalanceSIG"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 20), // "stopCornerBalanceSIG"
QT_MOC_LITERAL(4, 57, 15), // "reloadConfigSIG"
QT_MOC_LITERAL(5, 73, 24), // "CompLQR3DPhiReceivedSLOT"
QT_MOC_LITERAL(6, 98, 4), // "time"
QT_MOC_LITERAL(7, 103, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 119, 4), // "data"
QT_MOC_LITERAL(9, 124, 23), // "CompLQR3DUKReceivedSLOT"
QT_MOC_LITERAL(10, 148, 23), // "CompLQR3DURRecievedSLOT"
QT_MOC_LITERAL(11, 172, 23), // "CompLQR3DTMReceivedSLOT"
QT_MOC_LITERAL(12, 196, 15), // "startButtonSLOT"
QT_MOC_LITERAL(13, 212, 14), // "saveButtonSLOT"
QT_MOC_LITERAL(14, 227, 16) // "reloadButtonSLOT"

    },
    "CCornerBalance\0runCornerBalanceSIG\0\0"
    "stopCornerBalanceSIG\0reloadConfigSIG\0"
    "CompLQR3DPhiReceivedSLOT\0time\0"
    "QVector<double>\0data\0CompLQR3DUKReceivedSLOT\0"
    "CompLQR3DURRecievedSLOT\0CompLQR3DTMReceivedSLOT\0"
    "startButtonSLOT\0saveButtonSLOT\0"
    "reloadButtonSLOT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CCornerBalance[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   67,    2, 0x0a /* Public */,
       9,    2,   72,    2, 0x0a /* Public */,
      10,    2,   77,    2, 0x0a /* Public */,
      11,    2,   82,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CCornerBalance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CCornerBalance *_t = static_cast<CCornerBalance *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runCornerBalanceSIG(); break;
        case 1: _t->stopCornerBalanceSIG(); break;
        case 2: _t->reloadConfigSIG(); break;
        case 3: _t->CompLQR3DPhiReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 4: _t->CompLQR3DUKReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 5: _t->CompLQR3DURRecievedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 6: _t->CompLQR3DTMReceivedSLOT((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 7: _t->startButtonSLOT(); break;
        case 8: _t->saveButtonSLOT(); break;
        case 9: _t->reloadButtonSLOT(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 6:
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
            typedef void (CCornerBalance::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCornerBalance::runCornerBalanceSIG)) {
                *result = 0;
            }
        }
        {
            typedef void (CCornerBalance::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCornerBalance::stopCornerBalanceSIG)) {
                *result = 1;
            }
        }
        {
            typedef void (CCornerBalance::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCornerBalance::reloadConfigSIG)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CCornerBalance::staticMetaObject = {
    { &CExperimentWidget::staticMetaObject, qt_meta_stringdata_CCornerBalance.data,
      qt_meta_data_CCornerBalance,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CCornerBalance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CCornerBalance::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CCornerBalance.stringdata0))
        return static_cast<void*>(const_cast< CCornerBalance*>(this));
    return CExperimentWidget::qt_metacast(_clname);
}

int CCornerBalance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CCornerBalance::runCornerBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CCornerBalance::stopCornerBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CCornerBalance::reloadConfigSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
