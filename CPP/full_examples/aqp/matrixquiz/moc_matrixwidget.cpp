/****************************************************************************
** Meta object code from reading C++ file 'matrixwidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "matrixwidget.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matrixwidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MatrixWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      28,   13,   13,   13, 0x0a,
      66,   55,   47,   13, 0x0a,
     100,   83,   13,   13, 0x0a,
     149,  128,   13,   13, 0x0a,
     178,   55,   13,   13, 0x2a,
     212,  202,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MatrixWidget[] = {
    "MatrixWidget\0\0clearMatrix()\0"
    "repopulateMatrix()\0QString\0row,column\0"
    "valueAt(int,int)\0row,column,value\0"
    "setValueAt(int,int,QString)\0"
    "row,column,highlight\0setHighlighted(int,int,bool)\0"
    "setHighlighted(int,int)\0read_only\0"
    "setReadOnly(bool)\0"
};

void MatrixWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MatrixWidget *_t = static_cast<MatrixWidget *>(_o);
        switch (_id) {
        case 0: _t->clearMatrix(); break;
        case 1: _t->repopulateMatrix(); break;
        case 2: { QString _r = _t->valueAt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->setValueAt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->setHighlighted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->setHighlighted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setReadOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MatrixWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MatrixWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_MatrixWidget,
      qt_meta_data_MatrixWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MatrixWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MatrixWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MatrixWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MatrixWidget))
        return static_cast<void*>(const_cast< MatrixWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int MatrixWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
