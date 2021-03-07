/****************************************************************************
** Meta object code from reading C++ file 'GeneralSettingWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ui/Setting/GeneralSettingWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneralSettingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralSettingWidget_t {
    QByteArrayData data[14];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralSettingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralSettingWidget_t qt_meta_stringdata_GeneralSettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "GeneralSettingWidget"
QT_MOC_LITERAL(1, 21, 23), // "searchPathButtonClicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 26), // "openDirectoryButtonClicked"
QT_MOC_LITERAL(4, 73, 18), // "videoButtonClicked"
QT_MOC_LITERAL(5, 92, 18), // "imageButtonClicked"
QT_MOC_LITERAL(6, 111, 21), // "itemListDoubleClicked"
QT_MOC_LITERAL(7, 133, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 150, 4), // "item"
QT_MOC_LITERAL(9, 155, 19), // "deleteButtonClicked"
QT_MOC_LITERAL(10, 175, 20), // "orderByButtonClicked"
QT_MOC_LITERAL(11, 196, 24), // "orderByMenuActionClicked"
QT_MOC_LITERAL(12, 221, 7), // "OrderBy"
QT_MOC_LITERAL(13, 229, 7) // "orderBy"

    },
    "GeneralSettingWidget\0searchPathButtonClicked\0"
    "\0openDirectoryButtonClicked\0"
    "videoButtonClicked\0imageButtonClicked\0"
    "itemListDoubleClicked\0QListWidgetItem*\0"
    "item\0deleteButtonClicked\0orderByButtonClicked\0"
    "orderByMenuActionClicked\0OrderBy\0"
    "orderBy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralSettingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void GeneralSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GeneralSettingWidget *_t = static_cast<GeneralSettingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchPathButtonClicked(); break;
        case 1: _t->openDirectoryButtonClicked(); break;
        case 2: _t->videoButtonClicked(); break;
        case 3: _t->imageButtonClicked(); break;
        case 4: _t->itemListDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->deleteButtonClicked(); break;
        case 6: _t->orderByButtonClicked(); break;
        case 7: _t->orderByMenuActionClicked((*reinterpret_cast< OrderBy(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GeneralSettingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GeneralSettingWidget.data,
      qt_meta_data_GeneralSettingWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GeneralSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralSettingWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GeneralSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
struct qt_meta_stringdata_OrderByMenu_t {
    QByteArrayData data[9];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderByMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderByMenu_t qt_meta_stringdata_OrderByMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "OrderByMenu"
QT_MOC_LITERAL(1, 12, 18), // "orderActionClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 29), // "GeneralSettingWidget::OrderBy"
QT_MOC_LITERAL(4, 62, 7), // "orderBy"
QT_MOC_LITERAL(5, 70, 24), // "orderByNameActionClicked"
QT_MOC_LITERAL(6, 95, 24), // "orderByDateActionClicked"
QT_MOC_LITERAL(7, 120, 23), // "orderByAscActionClicked"
QT_MOC_LITERAL(8, 144, 24) // "orderByDescActionClicked"

    },
    "OrderByMenu\0orderActionClicked\0\0"
    "GeneralSettingWidget::OrderBy\0orderBy\0"
    "orderByNameActionClicked\0"
    "orderByDateActionClicked\0"
    "orderByAscActionClicked\0"
    "orderByDescActionClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderByMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OrderByMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OrderByMenu *_t = static_cast<OrderByMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->orderActionClicked((*reinterpret_cast< GeneralSettingWidget::OrderBy(*)>(_a[1]))); break;
        case 1: _t->orderByNameActionClicked(); break;
        case 2: _t->orderByDateActionClicked(); break;
        case 3: _t->orderByAscActionClicked(); break;
        case 4: _t->orderByDescActionClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrderByMenu::*)(GeneralSettingWidget::OrderBy );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderByMenu::orderActionClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrderByMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_OrderByMenu.data,
      qt_meta_data_OrderByMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OrderByMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderByMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderByMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int OrderByMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
void OrderByMenu::orderActionClicked(GeneralSettingWidget::OrderBy _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
