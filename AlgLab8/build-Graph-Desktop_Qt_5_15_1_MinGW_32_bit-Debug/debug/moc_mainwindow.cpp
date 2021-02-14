/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Graph/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_createButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_tableWidget_cellChanged"
QT_MOC_LITERAL(4, 63, 3), // "row"
QT_MOC_LITERAL(5, 67, 6), // "column"
QT_MOC_LITERAL(6, 74, 10), // "printGraph"
QT_MOC_LITERAL(7, 85, 10), // "printArrow"
QT_MOC_LITERAL(8, 96, 2), // "x1"
QT_MOC_LITERAL(9, 99, 2), // "y1"
QT_MOC_LITERAL(10, 102, 2), // "x2"
QT_MOC_LITERAL(11, 105, 2), // "y2"
QT_MOC_LITERAL(12, 108, 15), // "QGraphicsScene&"
QT_MOC_LITERAL(13, 124, 5), // "scene"
QT_MOC_LITERAL(14, 130, 23), // "on_searchButton_clicked"
QT_MOC_LITERAL(15, 154, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(16, 178, 26), // "on_execOrderButton_clicked"
QT_MOC_LITERAL(17, 205, 3), // "bfs"
QT_MOC_LITERAL(18, 209, 1), // "n"
QT_MOC_LITERAL(19, 211, 3), // "dfs"
QT_MOC_LITERAL(20, 215, 6), // "bool[]"
QT_MOC_LITERAL(21, 222, 4), // "used"
QT_MOC_LITERAL(22, 227, 8), // "dijkstra"
QT_MOC_LITERAL(23, 236, 5), // "floyd"
QT_MOC_LITERAL(24, 242, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(25, 274, 5) // "index"

    },
    "MainWindow\0on_createButton_clicked\0\0"
    "on_tableWidget_cellChanged\0row\0column\0"
    "printGraph\0printArrow\0x1\0y1\0x2\0y2\0"
    "QGraphicsScene&\0scene\0on_searchButton_clicked\0"
    "on_deleteButton_clicked\0"
    "on_execOrderButton_clicked\0bfs\0n\0dfs\0"
    "bool[]\0used\0dijkstra\0floyd\0"
    "on_comboBox_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    2,   75,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    5,   81,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    1,   95,    2, 0x08 /* Private */,
      19,    2,   98,    2, 0x08 /* Private */,
      22,    1,  103,    2, 0x08 /* Private */,
      23,    0,  106,    2, 0x08 /* Private */,
      24,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, 0x80000000 | 12,    8,    9,   10,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 20,   18,   21,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_createButton_clicked(); break;
        case 1: _t->on_tableWidget_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->printGraph(); break;
        case 3: _t->printArrow((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< QGraphicsScene(*)>(_a[5]))); break;
        case 4: _t->on_searchButton_clicked(); break;
        case 5: _t->on_deleteButton_clicked(); break;
        case 6: _t->on_execOrderButton_clicked(); break;
        case 7: _t->bfs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->dfs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)[]>(_a[2]))); break;
        case 9: _t->dijkstra((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->floyd(); break;
        case 11: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
