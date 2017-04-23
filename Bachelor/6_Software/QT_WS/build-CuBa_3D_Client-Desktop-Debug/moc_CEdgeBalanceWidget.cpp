/****************************************************************************
** Meta object code from reading C++ file 'CEdgeBalanceWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_3D_Client/CEdgeBalanceWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CEdgeBalanceWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CEdgeBalanceWidget_t {
    QByteArrayData data[15];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CEdgeBalanceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CEdgeBalanceWidget_t qt_meta_stringdata_CEdgeBalanceWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CEdgeBalanceWidget"
QT_MOC_LITERAL(1, 19, 17), // "runEdgeBalanceSIG"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 18), // "stopEdgeBalanceSIG"
QT_MOC_LITERAL(4, 57, 26), // "setOffsetCorrectionFlagSIG"
QT_MOC_LITERAL(5, 84, 4), // "flag"
QT_MOC_LITERAL(6, 89, 13), // "setLQRFlagSIG"
QT_MOC_LITERAL(7, 103, 22), // "startButtonClickedSLOT"
QT_MOC_LITERAL(8, 126, 19), // "lqrDataReceivedSLOT"
QT_MOC_LITERAL(9, 146, 6), // "Data1D"
QT_MOC_LITERAL(10, 153, 4), // "data"
QT_MOC_LITERAL(11, 158, 19), // "lqgDataReceivedSLOT"
QT_MOC_LITERAL(12, 178, 21), // "offsetCheckboxClicked"
QT_MOC_LITERAL(13, 200, 22), // "lqrCheckboxClickedSLOT"
QT_MOC_LITERAL(14, 223, 7) // "saveCSV"

    },
    "CEdgeBalanceWidget\0runEdgeBalanceSIG\0"
    "\0stopEdgeBalanceSIG\0setOffsetCorrectionFlagSIG\0"
    "flag\0setLQRFlagSIG\0startButtonClickedSLOT\0"
    "lqrDataReceivedSLOT\0Data1D\0data\0"
    "lqgDataReceivedSLOT\0offsetCheckboxClicked\0"
    "lqrCheckboxClickedSLOT\0saveCSV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CEdgeBalanceWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       6,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   72,    2, 0x0a /* Public */,
       8,    1,   73,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,
      13,    1,   82,    2, 0x0a /* Public */,
      14,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

       0        // eod
};

void CEdgeBalanceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CEdgeBalanceWidget *_t = static_cast<CEdgeBalanceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runEdgeBalanceSIG(); break;
        case 1: _t->stopEdgeBalanceSIG(); break;
        case 2: _t->setOffsetCorrectionFlagSIG((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setLQRFlagSIG((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->startButtonClickedSLOT(); break;
        case 5: _t->lqrDataReceivedSLOT((*reinterpret_cast< const Data1D(*)>(_a[1]))); break;
        case 6: _t->lqgDataReceivedSLOT((*reinterpret_cast< const Data1D(*)>(_a[1]))); break;
        case 7: _t->offsetCheckboxClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->lqrCheckboxClickedSLOT((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->saveCSV(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CEdgeBalanceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalanceWidget::runEdgeBalanceSIG)) {
                *result = 0;
            }
        }
        {
            typedef void (CEdgeBalanceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalanceWidget::stopEdgeBalanceSIG)) {
                *result = 1;
            }
        }
        {
            typedef void (CEdgeBalanceWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalanceWidget::setOffsetCorrectionFlagSIG)) {
                *result = 2;
            }
        }
        {
            typedef void (CEdgeBalanceWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEdgeBalanceWidget::setLQRFlagSIG)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CEdgeBalanceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CEdgeBalanceWidget.data,
      qt_meta_data_CEdgeBalanceWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CEdgeBalanceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CEdgeBalanceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CEdgeBalanceWidget.stringdata0))
        return static_cast<void*>(const_cast< CEdgeBalanceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CEdgeBalanceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CEdgeBalanceWidget::runEdgeBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CEdgeBalanceWidget::stopEdgeBalanceSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CEdgeBalanceWidget::setOffsetCorrectionFlagSIG(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CEdgeBalanceWidget::setLQRFlagSIG(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
