/****************************************************************************
** Meta object code from reading C++ file 'CControlWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_1D_Client/CControlWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CControlWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CControlWidget_t {
    QByteArrayData data[28];
    char stringdata[420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CControlWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CControlWidget_t qt_meta_stringdata_CControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 6),
QT_MOC_LITERAL(4, 40, 19),
QT_MOC_LITERAL(5, 60, 19),
QT_MOC_LITERAL(6, 80, 13),
QT_MOC_LITERAL(7, 94, 7),
QT_MOC_LITERAL(8, 102, 6),
QT_MOC_LITERAL(9, 109, 19),
QT_MOC_LITERAL(10, 129, 4),
QT_MOC_LITERAL(11, 134, 14),
QT_MOC_LITERAL(12, 149, 15),
QT_MOC_LITERAL(13, 165, 4),
QT_MOC_LITERAL(14, 170, 4),
QT_MOC_LITERAL(15, 175, 18),
QT_MOC_LITERAL(16, 194, 7),
QT_MOC_LITERAL(17, 202, 18),
QT_MOC_LITERAL(18, 221, 7),
QT_MOC_LITERAL(19, 229, 22),
QT_MOC_LITERAL(20, 252, 25),
QT_MOC_LITERAL(21, 278, 25),
QT_MOC_LITERAL(22, 304, 17),
QT_MOC_LITERAL(23, 322, 7),
QT_MOC_LITERAL(24, 330, 20),
QT_MOC_LITERAL(25, 351, 20),
QT_MOC_LITERAL(26, 372, 23),
QT_MOC_LITERAL(27, 396, 22)
    },
    "CControlWidget\0phiOffsetChanged\0\0"
    "offset\0phi__dOffsetChanged\0"
    "psi__dOffsetChanged\0filterChanged\0"
    "EFilter\0filter\0highpassFlagChanged\0"
    "flag\0lqrFlagChanged\0phiDataReceived\0"
    "CPhi\0data\0phi__dDataReceived\0CPhi__d\0"
    "psi__dDataReceived\0CPsi__d\0"
    "phiOffsetButtonClicked\0phi__dOffsetButtonClicked\0"
    "psi__dOffsetButtonClicked\0phiFilterSelected\0"
    "toggled\0phi__dFilterSelected\0"
    "psi__dFilterSelected\0highpassCheckboxToggled\0"
    "controllerGroupClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CControlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06,
       4,    1,  102,    2, 0x06,
       5,    1,  105,    2, 0x06,
       6,    1,  108,    2, 0x06,
       9,    1,  111,    2, 0x06,
      11,    1,  114,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    1,  117,    2, 0x0a,
      15,    1,  120,    2, 0x0a,
      17,    1,  123,    2, 0x0a,
      19,    0,  126,    2, 0x0a,
      20,    0,  127,    2, 0x0a,
      21,    0,  128,    2, 0x0a,
      22,    1,  129,    2, 0x0a,
      24,    1,  132,    2, 0x0a,
      25,    1,  135,    2, 0x0a,
      26,    1,  138,    2, 0x0a,
      27,    0,  141,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   14,
    QMetaType::Void, 0x80000000 | 18,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,

       0        // eod
};

void CControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CControlWidget *_t = static_cast<CControlWidget *>(_o);
        switch (_id) {
        case 0: _t->phiOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->phi__dOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->psi__dOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->filterChanged((*reinterpret_cast< EFilter(*)>(_a[1]))); break;
        case 4: _t->highpassFlagChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->lqrFlagChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->phiDataReceived((*reinterpret_cast< const CPhi(*)>(_a[1]))); break;
        case 7: _t->phi__dDataReceived((*reinterpret_cast< const CPhi__d(*)>(_a[1]))); break;
        case 8: _t->psi__dDataReceived((*reinterpret_cast< const CPsi__d(*)>(_a[1]))); break;
        case 9: _t->phiOffsetButtonClicked(); break;
        case 10: _t->phi__dOffsetButtonClicked(); break;
        case 11: _t->psi__dOffsetButtonClicked(); break;
        case 12: _t->phiFilterSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->phi__dFilterSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->psi__dFilterSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->highpassCheckboxToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->controllerGroupClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CControlWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::phiOffsetChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CControlWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::phi__dOffsetChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (CControlWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::psi__dOffsetChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (CControlWidget::*_t)(EFilter );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::filterChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (CControlWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::highpassFlagChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (CControlWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::lqrFlagChanged)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject CControlWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CControlWidget.data,
      qt_meta_data_CControlWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CControlWidget.stringdata))
        return static_cast<void*>(const_cast< CControlWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void CControlWidget::phiOffsetChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CControlWidget::phi__dOffsetChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CControlWidget::psi__dOffsetChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CControlWidget::filterChanged(EFilter _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CControlWidget::highpassFlagChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CControlWidget::lqrFlagChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
