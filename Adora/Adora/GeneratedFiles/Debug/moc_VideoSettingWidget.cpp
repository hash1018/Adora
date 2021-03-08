/****************************************************************************
** Meta object code from reading C++ file 'VideoSettingWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ui/Setting/VideoSettingWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoSettingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoSettingWidget_t {
    QByteArrayData data[11];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoSettingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoSettingWidget_t qt_meta_stringdata_VideoSettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "VideoSettingWidget"
QT_MOC_LITERAL(1, 19, 24), // "startStopCheckBoxToggled"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 7), // "checked"
QT_MOC_LITERAL(4, 53, 26), // "pauseResumeCheckBoxToggled"
QT_MOC_LITERAL(5, 80, 28), // "includeCursorCheckBoxToggled"
QT_MOC_LITERAL(6, 109, 27), // "useHwEncoderCheckBoxToggled"
QT_MOC_LITERAL(7, 137, 29), // "fpsComboBoxCurrentTextChanged"
QT_MOC_LITERAL(8, 167, 4), // "text"
QT_MOC_LITERAL(9, 172, 31), // "videoBitrateSpinBoxValueChanged"
QT_MOC_LITERAL(10, 204, 5) // "value"

    },
    "VideoSettingWidget\0startStopCheckBoxToggled\0"
    "\0checked\0pauseResumeCheckBoxToggled\0"
    "includeCursorCheckBoxToggled\0"
    "useHwEncoderCheckBoxToggled\0"
    "fpsComboBoxCurrentTextChanged\0text\0"
    "videoBitrateSpinBoxValueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoSettingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void VideoSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoSettingWidget *_t = static_cast<VideoSettingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startStopCheckBoxToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->pauseResumeCheckBoxToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->includeCursorCheckBoxToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->useHwEncoderCheckBoxToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->fpsComboBoxCurrentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->videoBitrateSpinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoSettingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoSettingWidget.data,
      qt_meta_data_VideoSettingWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VideoSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoSettingWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VideoSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
