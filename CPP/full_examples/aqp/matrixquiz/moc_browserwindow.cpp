/****************************************************************************
** Meta object code from reading C++ file 'browserwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../browserwindow/browserwindow.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browserwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BrowserWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x05,
      41,   37,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   37,   14,   14, 0x0a,
      77,   72,   14,   14, 0x0a,
      97,   94,   14,   14, 0x0a,
     122,  115,   14,   14, 0x0a,
     142,   14,   14,   14, 0x08,
     152,   14,   14,   14, 0x08,
     161,   14,   14,   14, 0x08,
     175,  170,   14,   14, 0x08,
     194,   14,   14,   14, 0x08,
     213,   15,   14,   14, 0x08,
     230,   37,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BrowserWindow[] = {
    "BrowserWindow\0\0ok\0loadFinished(bool)\0"
    "url\0urlChanged(QUrl)\0load(QString)\0"
    "html\0setHtml(QString)\0on\0showToolBar(bool)\0"
    "enable\0enableActions(bool)\0zoomOut()\0"
    "zoomIn()\0setUrl()\0zoom\0setZoomFactor(int)\0"
    "popUpHistoryMenu()\0loadFinish(bool)\0"
    "urlChange(QUrl)\0"
};

void BrowserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BrowserWindow *_t = static_cast<BrowserWindow *>(_o);
        switch (_id) {
        case 0: _t->loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->urlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: _t->load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->showToolBar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->enableActions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->zoomOut(); break;
        case 7: _t->zoomIn(); break;
        case 8: _t->setUrl(); break;
        case 9: _t->setZoomFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->popUpHistoryMenu(); break;
        case 11: _t->loadFinish((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->urlChange((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BrowserWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BrowserWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_BrowserWindow,
      qt_meta_data_BrowserWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BrowserWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BrowserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BrowserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrowserWindow))
        return static_cast<void*>(const_cast< BrowserWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int BrowserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void BrowserWindow::loadFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BrowserWindow::urlChanged(const QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
