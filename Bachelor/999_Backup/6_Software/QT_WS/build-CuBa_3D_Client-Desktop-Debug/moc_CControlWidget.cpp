/****************************************************************************
** Meta object code from reading C++ file 'CControlWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CuBa_3D_Client/CControlWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CControlWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CControlWidget_t {
    QByteArrayData data[22];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CControlWidget_t qt_meta_stringdata_CControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CControlWidget"
QT_MOC_LITERAL(1, 15, 14), // "runControlTest"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "stopControlTest"
QT_MOC_LITERAL(4, 47, 17), // "setCompFilterFlag"
QT_MOC_LITERAL(5, 65, 4), // "flag"
QT_MOC_LITERAL(6, 70, 19), // "setOffsetFilterFlag"
QT_MOC_LITERAL(7, 90, 18), // "startButtonClicked"
QT_MOC_LITERAL(8, 109, 13), // "gDataReceived"
QT_MOC_LITERAL(9, 123, 6), // "CGData"
QT_MOC_LITERAL(10, 130, 4), // "data"
QT_MOC_LITERAL(11, 135, 14), // "ukDataReceived"
QT_MOC_LITERAL(12, 150, 7), // "CUKData"
QT_MOC_LITERAL(13, 158, 14), // "urDataReceived"
QT_MOC_LITERAL(14, 173, 7), // "CURData"
QT_MOC_LITERAL(15, 181, 18), // "torqueDataReceived"
QT_MOC_LITERAL(16, 200, 11), // "CTorqueData"
QT_MOC_LITERAL(17, 212, 15), // "gDisplayClicked"
QT_MOC_LITERAL(18, 228, 5), // "state"
QT_MOC_LITERAL(19, 234, 8), // "saveData"
QT_MOC_LITERAL(20, 243, 22), // "onCompFilterBoxClicked"
QT_MOC_LITERAL(21, 266, 18) // "onOffsetBoxClicked"

    },
    "CControlWidget\0runControlTest\0\0"
    "stopControlTest\0setCompFilterFlag\0"
    "flag\0setOffsetFilterFlag\0startButtonClicked\0"
    "gDataReceived\0CGData\0data\0ukDataReceived\0"
    "CUKData\0urDataReceived\0CURData\0"
    "torqueDataReceived\0CTorqueData\0"
    "gDisplayClicked\0state\0saveData\0"
    "onCompFilterBoxClicked\0onOffsetBoxClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CControlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   87,    2, 0x0a /* Public */,
       8,    1,   88,    2, 0x0a /* Public */,
      11,    1,   91,    2, 0x0a /* Public */,
      13,    1,   94,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,
      17,    1,  100,    2, 0x0a /* Public */,
      19,    0,  103,    2, 0x0a /* Public */,
      20,    0,  104,    2, 0x0a /* Public */,
      21,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void, 0x80000000 | 14,   10,
    QMetaType::Void, 0x80000000 | 16,   10,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CControlWidget *_t = static_cast<CControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runControlTest(); break;
        case 1: _t->stopControlTest(); break;
        case 2: _t->setCompFilterFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setOffsetFilterFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->startButtonClicked(); break;
        case 5: _t->gDataReceived((*reinterpret_cast< const CGData(*)>(_a[1]))); break;
        case 6: _t->ukDataReceived((*reinterpret_cast< const CUKData(*)>(_a[1]))); break;
        case 7: _t->urDataReceived((*reinterpret_cast< const CURData(*)>(_a[1]))); break;
        case 8: _t->torqueDataReceived((*reinterpret_cast< const CTorqueData(*)>(_a[1]))); break;
        case 9: _t->gDisplayClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->saveData(); break;
        case 11: _t->onCompFilterBoxClicked(); break;
        case 12: _t->onOffsetBoxClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CControlWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::runControlTest)) {
                *result = 0;
            }
        }
        {
            typedef void (CControlWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::stopControlTest)) {
                *result = 1;
            }
        }
        {
            typedef void (CControlWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::setCompFilterFlag)) {
                *result = 2;
            }
        }
        {
            typedef void (CControlWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CControlWidget::setOffsetFilterFlag)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CControlWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CControlWidget.data,
      qt_meta_data_CControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CControlWidget.stringdata0))
        return static_cast<void*>(const_cast< CControlWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CControlWidget::runControlTest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CControlWidget::stopControlTest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CControlWidget::setCompFilterFlag(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CControlWidget::setOffsetFilterFlag(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
