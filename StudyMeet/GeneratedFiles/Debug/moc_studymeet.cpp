/****************************************************************************
** Meta object code from reading C++ file 'studymeet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../studymeet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studymeet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StudyMeet_t {
    QByteArrayData data[5];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StudyMeet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StudyMeet_t qt_meta_stringdata_StudyMeet = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StudyMeet"
QT_MOC_LITERAL(1, 10, 20), // "on_heyButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_insertButton_clicked"
QT_MOC_LITERAL(4, 56, 27) // "on_getStartedButton_clicked"

    },
    "StudyMeet\0on_heyButton_clicked\0\0"
    "on_insertButton_clicked\0"
    "on_getStartedButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudyMeet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StudyMeet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StudyMeet *_t = static_cast<StudyMeet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_heyButton_clicked(); break;
        case 1: _t->on_insertButton_clicked(); break;
        case 2: _t->on_getStartedButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StudyMeet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StudyMeet.data,
      qt_meta_data_StudyMeet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StudyMeet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudyMeet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StudyMeet.stringdata0))
        return static_cast<void*>(const_cast< StudyMeet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StudyMeet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
