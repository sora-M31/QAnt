/****************************************************************************
** Meta object code from reading C++ file 'GLWindow.h'
**
** Created: Wed Apr 20 16:41:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GLWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtGLWindow__GLWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   22,   21,   21, 0x0a,
      50,   21,   21,   21, 0x0a,
      65,   21,   21,   21, 0x0a,
      80,   21,   21,   21, 0x0a,
     100,   95,   21,   21, 0x0a,
     124,   95,   21,   21, 0x0a,
     148,   95,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QtGLWindow__GLWindow[] = {
    "QtGLWindow::GLWindow\0\0_mode\0"
    "toggleWireframe(bool)\0setRotationX()\0"
    "setRotationY()\0setRotationZ()\0_dis\0"
    "setTranslationX(double)\0setTranslationY(double)\0"
    "setTranslationZ(double)\0"
};

const QMetaObject QtGLWindow::GLWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_QtGLWindow__GLWindow,
      qt_meta_data_QtGLWindow__GLWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtGLWindow::GLWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtGLWindow::GLWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtGLWindow::GLWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtGLWindow__GLWindow))
        return static_cast<void*>(const_cast< GLWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int QtGLWindow::GLWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: toggleWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setRotationX(); break;
        case 2: setRotationY(); break;
        case 3: setRotationZ(); break;
        case 4: setTranslationX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: setTranslationY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: setTranslationZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
