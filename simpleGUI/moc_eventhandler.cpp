/****************************************************************************
** Meta object code from reading C++ file 'eventhandler.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eventhandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EventHandler[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      34,   13,   13,   13, 0x0a,
      54,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EventHandler[] = {
    "EventHandler\0\0menu_open_clicked()\0"
    "menu_exit_clicked()\0btn_run_clicked()\0"
};

const QMetaObject EventHandler::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EventHandler,
      qt_meta_data_EventHandler, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EventHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EventHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EventHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EventHandler))
        return static_cast<void*>(const_cast< EventHandler*>(this));
    return QWidget::qt_metacast(_clname);
}

int EventHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: menu_open_clicked(); break;
        case 1: menu_exit_clicked(); break;
        case 2: btn_run_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
