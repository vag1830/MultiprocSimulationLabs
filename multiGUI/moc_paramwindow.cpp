/****************************************************************************
** Meta object code from reading C++ file 'paramwindow.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "paramwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ParamWindow[] = {

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
      13,   12,   12,   12, 0x0a,
      36,   12,   12,   12, 0x0a,
      55,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ParamWindow[] = {
    "ParamWindow\0\0btn_defaults_clicked()\0"
    "btn_save_clicked()\0btn_close_clicked()\0"
};

const QMetaObject ParamWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ParamWindow,
      qt_meta_data_ParamWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ParamWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ParamWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ParamWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParamWindow))
        return static_cast<void*>(const_cast< ParamWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ParamWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: btn_defaults_clicked(); break;
        case 1: btn_save_clicked(); break;
        case 2: btn_close_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
