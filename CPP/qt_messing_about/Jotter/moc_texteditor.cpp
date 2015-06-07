/****************************************************************************
** Meta object code from reading C++ file 'texteditor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "texteditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'texteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Texteditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x0a,
      44,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      74,   11,   69,   11, 0x0a,
      93,   86,   11,   11, 0x0a,
     131,   86,   11,   11, 0x0a,
     173,   11,   11,   11, 0x08,
     198,  192,   69,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Texteditor[] = {
    "Texteditor\0\0modified()\0cutItem()\0"
    "copyItem()\0pasteItem()\0deleteItem()\0"
    "bool\0syntaxCpp()\0str,cs\0"
    "findNext(QString,Qt::CaseSensitivity)\0"
    "findPrevious(QString,Qt::CaseSensitivity)\0"
    "somethingChanged()\0event\0event(QEvent*)\0"
};

void Texteditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Texteditor *_t = static_cast<Texteditor *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->cutItem(); break;
        case 2: _t->copyItem(); break;
        case 3: _t->pasteItem(); break;
        case 4: _t->deleteItem(); break;
        case 5: { bool _r = _t->syntaxCpp();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->findNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 7: _t->findPrevious((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 8: _t->somethingChanged(); break;
        case 9: { bool _r = _t->event((*reinterpret_cast< QEvent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Texteditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Texteditor::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_Texteditor,
      qt_meta_data_Texteditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Texteditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Texteditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Texteditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Texteditor))
        return static_cast<void*>(const_cast< Texteditor*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int Texteditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Texteditor::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
