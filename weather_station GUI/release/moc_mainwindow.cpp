/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[10];
    char stringdata5[21];
    char stringdata6[23];
    char stringdata7[20];
    char stringdata8[12];
    char stringdata9[23];
    char stringdata10[24];
    char stringdata11[6];
    char stringdata12[24];
    char stringdata13[20];
    char stringdata14[22];
    char stringdata15[32];
    char stringdata16[9];
    char stringdata17[34];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "disconnected"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 9),  // "readyRead"
        QT_MOC_LITERAL(35, 9),  // "connected"
        QT_MOC_LITERAL(45, 20),  // "on_btn_Clear_clicked"
        QT_MOC_LITERAL(66, 22),  // "on_btn_Connect_clicked"
        QT_MOC_LITERAL(89, 19),  // "on_btn_Send_clicked"
        QT_MOC_LITERAL(109, 11),  // "updateGraph"
        QT_MOC_LITERAL(121, 22),  // "on_btn_Refresh_clicked"
        QT_MOC_LITERAL(144, 23),  // "on_cb_Monitor_activated"
        QT_MOC_LITERAL(168, 5),  // "index"
        QT_MOC_LITERAL(174, 23),  // "on_btn_Download_clicked"
        QT_MOC_LITERAL(198, 19),  // "on_btn_Load_clicked"
        QT_MOC_LITERAL(218, 21),  // "on_btn_Filter_clicked"
        QT_MOC_LITERAL(240, 31),  // "on_dateEdit_End_dateTimeChanged"
        QT_MOC_LITERAL(272, 8),  // "dateTime"
        QT_MOC_LITERAL(281, 33)   // "on_dateEdit_Start_dateTimeCha..."
    },
    "MainWindow",
    "disconnected",
    "",
    "readyRead",
    "connected",
    "on_btn_Clear_clicked",
    "on_btn_Connect_clicked",
    "on_btn_Send_clicked",
    "updateGraph",
    "on_btn_Refresh_clicked",
    "on_cb_Monitor_activated",
    "index",
    "on_btn_Download_clicked",
    "on_btn_Load_clicked",
    "on_btn_Filter_clicked",
    "on_dateEdit_End_dateTimeChanged",
    "dateTime",
    "on_dateEdit_Start_dateTimeChanged"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    3,  104,    2, 0x08,    7 /* Private */,
       9,    0,  111,    2, 0x08,   11 /* Private */,
      10,    1,  112,    2, 0x08,   12 /* Private */,
      12,    0,  115,    2, 0x08,   14 /* Private */,
      13,    0,  116,    2, 0x08,   15 /* Private */,
      14,    0,  117,    2, 0x08,   16 /* Private */,
      15,    1,  118,    2, 0x08,   17 /* Private */,
      17,    1,  121,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   16,
    QMetaType::Void, QMetaType::QDateTime,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Connect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Send_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_btn_Refresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cb_Monitor_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_btn_Download_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Load_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Filter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_dateEdit_End_dateTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        // method 'on_dateEdit_Start_dateTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->readyRead(); break;
        case 2: _t->connected(); break;
        case 3: _t->on_btn_Clear_clicked(); break;
        case 4: _t->on_btn_Connect_clicked(); break;
        case 5: _t->on_btn_Send_clicked(); break;
        case 6: _t->updateGraph((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 7: _t->on_btn_Refresh_clicked(); break;
        case 8: _t->on_cb_Monitor_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_btn_Download_clicked(); break;
        case 10: _t->on_btn_Load_clicked(); break;
        case 11: _t->on_btn_Filter_clicked(); break;
        case 12: _t->on_dateEdit_End_dateTimeChanged((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 13: _t->on_dateEdit_Start_dateTimeChanged((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        default: ;
        }
    }
}

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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
