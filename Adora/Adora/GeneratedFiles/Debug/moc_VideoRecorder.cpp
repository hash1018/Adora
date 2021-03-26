/****************************************************************************
** Meta object code from reading C++ file 'VideoRecorder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lib/ffmpeg/VideoRecorder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoRecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoRecorder_t {
    QByteArrayData data[11];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoRecorder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoRecorder_t qt_meta_stringdata_VideoRecorder = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VideoRecorder"
QT_MOC_LITERAL(1, 14, 10), // "timePassed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "Time&"
QT_MOC_LITERAL(4, 32, 4), // "time"
QT_MOC_LITERAL(5, 37, 7), // "started"
QT_MOC_LITERAL(6, 45, 6), // "paused"
QT_MOC_LITERAL(7, 52, 7), // "stopped"
QT_MOC_LITERAL(8, 60, 7), // "resumed"
QT_MOC_LITERAL(9, 68, 17), // "videoCaptureReady"
QT_MOC_LITERAL(10, 86, 17) // "audioCaptureReady"

    },
    "VideoRecorder\0timePassed\0\0Time&\0time\0"
    "started\0paused\0stopped\0resumed\0"
    "videoCaptureReady\0audioCaptureReady"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoRecorder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VideoRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoRecorder *_t = static_cast<VideoRecorder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timePassed((*reinterpret_cast< Time(*)>(_a[1]))); break;
        case 1: _t->started(); break;
        case 2: _t->paused(); break;
        case 3: _t->stopped(); break;
        case 4: _t->resumed(); break;
        case 5: _t->videoCaptureReady(); break;
        case 6: _t->audioCaptureReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoRecorder::*)(Time & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoRecorder::timePassed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoRecorder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoRecorder::started)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoRecorder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoRecorder::paused)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoRecorder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoRecorder::stopped)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoRecorder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoRecorder::resumed)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoRecorder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VideoRecorder.data,
      qt_meta_data_VideoRecorder,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VideoRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoRecorder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VideoRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void VideoRecorder::timePassed(Time & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoRecorder::started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VideoRecorder::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VideoRecorder::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VideoRecorder::resumed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
