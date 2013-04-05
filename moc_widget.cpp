/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Fri Apr 5 22:33:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      23,    7,    7,    7, 0x08,
      36,    7,    7,    7, 0x08,
      56,    7,    7,    7, 0x08,
      90,    7,    7,    7, 0x08,
     123,    7,    7,    7, 0x08,
     152,    7,    7,    7, 0x08,
     181,    7,    7,    7, 0x08,
     210,    7,    7,    7, 0x08,
     238,    7,    7,    7, 0x08,
     267,    7,    7,    7, 0x08,
     302,  296,    7,    7, 0x08,
     340,  296,    7,    7, 0x08,
     387,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0creatActions()\0removeSlot()\0"
    "refreshTime(qint64)\0"
    "on_toolButton_playpause_clicked()\0"
    "on_toolButton_playstop_clicked()\0"
    "on_toolButton_stop_clicked()\0"
    "on_toolButton_open_clicked()\0"
    "on_toolButton_list_clicked()\0"
    "on_toolButton_lrc_clicked()\0"
    "on_toolButton_next_clicked()\0"
    "on_toolButton_last_clicked()\0index\0"
    "on_doubleClick_listItems(QModelIndex)\0"
    "on_tableWidget_list_doubleClicked(QModelIndex)\0"
    "next_media()\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->creatActions(); break;
        case 1: _t->removeSlot(); break;
        case 2: _t->refreshTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->on_toolButton_playpause_clicked(); break;
        case 4: _t->on_toolButton_playstop_clicked(); break;
        case 5: _t->on_toolButton_stop_clicked(); break;
        case 6: _t->on_toolButton_open_clicked(); break;
        case 7: _t->on_toolButton_list_clicked(); break;
        case 8: _t->on_toolButton_lrc_clicked(); break;
        case 9: _t->on_toolButton_next_clicked(); break;
        case 10: _t->on_toolButton_last_clicked(); break;
        case 11: _t->on_doubleClick_listItems((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_tableWidget_list_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->next_media(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
