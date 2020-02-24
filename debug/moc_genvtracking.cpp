/****************************************************************************
** Meta object code from reading C++ file 'genvtracking.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../genvtracking.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genvtracking.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GenvTracking_t {
    QByteArrayData data[11];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenvTracking_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenvTracking_t qt_meta_stringdata_GenvTracking = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GenvTracking"
QT_MOC_LITERAL(1, 13, 10), // "sendStream"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "sendImg"
QT_MOC_LITERAL(4, 33, 6), // "output"
QT_MOC_LITERAL(5, 40, 20), // "pushButtonChangeText"
QT_MOC_LITERAL(6, 61, 11), // "std::string"
QT_MOC_LITERAL(7, 73, 3), // "txt"
QT_MOC_LITERAL(8, 77, 8), // "recupImg"
QT_MOC_LITERAL(9, 86, 9), // "setStatut"
QT_MOC_LITERAL(10, 96, 10) // "funcStream"

    },
    "GenvTracking\0sendStream\0\0sendImg\0"
    "output\0pushButtonChangeText\0std::string\0"
    "txt\0recupImg\0setStatut\0funcStream"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenvTracking[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GenvTracking::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GenvTracking *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendStream(); break;
        case 1: _t->sendImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->pushButtonChangeText((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->recupImg(); break;
        case 4: _t->setStatut(); break;
        case 5: _t->funcStream(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GenvTracking::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenvTracking::sendStream)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GenvTracking::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenvTracking::sendImg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GenvTracking::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenvTracking::pushButtonChangeText)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GenvTracking::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GenvTracking.data,
    qt_meta_data_GenvTracking,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GenvTracking::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenvTracking::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GenvTracking.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GenvTracking::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GenvTracking::sendStream()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GenvTracking::sendImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GenvTracking::pushButtonChangeText(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
