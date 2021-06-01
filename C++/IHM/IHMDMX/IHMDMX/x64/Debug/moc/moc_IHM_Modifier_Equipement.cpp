/****************************************************************************
** Meta object code from reading C++ file 'IHM_Modifier_Equipement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../IHM_Modifier_Equipement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IHM_Modifier_Equipement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IHM_Modifier_Equipement_t {
    QByteArrayData data[7];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHM_Modifier_Equipement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHM_Modifier_Equipement_t qt_meta_stringdata_IHM_Modifier_Equipement = {
    {
QT_MOC_LITERAL(0, 0, 23), // "IHM_Modifier_Equipement"
QT_MOC_LITERAL(1, 24, 12), // "Connexionbdd"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "Modif_Validation"
QT_MOC_LITERAL(4, 55, 11), // "Placeholder"
QT_MOC_LITERAL(5, 67, 16), // "getAllEquipement"
QT_MOC_LITERAL(6, 84, 7) // "Refresh"

    },
    "IHM_Modifier_Equipement\0Connexionbdd\0"
    "\0Modif_Validation\0Placeholder\0"
    "getAllEquipement\0Refresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHM_Modifier_Equipement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IHM_Modifier_Equipement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHM_Modifier_Equipement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Connexionbdd(); break;
        case 1: _t->Modif_Validation(); break;
        case 2: _t->Placeholder(); break;
        case 3: _t->getAllEquipement(); break;
        case 4: _t->Refresh(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject IHM_Modifier_Equipement::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IHM_Modifier_Equipement.data,
    qt_meta_data_IHM_Modifier_Equipement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IHM_Modifier_Equipement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHM_Modifier_Equipement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IHM_Modifier_Equipement.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IHM_Modifier_Equipement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
