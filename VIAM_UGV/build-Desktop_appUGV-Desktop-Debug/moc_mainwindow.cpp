/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Desktop_appUGV/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[65];
    char stringdata0[1200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "positionReceived"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "point"
QT_MOC_LITERAL(4, 35, 16), // "wayPointSelected"
QT_MOC_LITERAL(5, 52, 9), // "pointList"
QT_MOC_LITERAL(6, 62, 15), // "realPathCleared"
QT_MOC_LITERAL(7, 78, 13), // "OrderReceived"
QT_MOC_LITERAL(8, 92, 7), // "myorder"
QT_MOC_LITERAL(9, 100, 7), // "Myorder"
QT_MOC_LITERAL(10, 108, 16), // "UGVorderReceived"
QT_MOC_LITERAL(11, 125, 8), // "UGVorder"
QT_MOC_LITERAL(12, 134, 28), // "on_Signin_btn_signin_clicked"
QT_MOC_LITERAL(13, 163, 28), // "on_Signin_btn_signup_clicked"
QT_MOC_LITERAL(14, 192, 30), // "on_Signin_btn_settings_clicked"
QT_MOC_LITERAL(15, 223, 27), // "on_Signin_btn_login_clicked"
QT_MOC_LITERAL(16, 251, 29), // "on_Account__btnlogout_clicked"
QT_MOC_LITERAL(17, 281, 11), // "resizeEvent"
QT_MOC_LITERAL(18, 293, 13), // "QResizeEvent*"
QT_MOC_LITERAL(19, 307, 5), // "event"
QT_MOC_LITERAL(20, 313, 26), // "on_Main_btn_robots_clicked"
QT_MOC_LITERAL(21, 340, 26), // "on_Main_btn_orders_clicked"
QT_MOC_LITERAL(22, 367, 28), // "on_Main_btn_tracking_clicked"
QT_MOC_LITERAL(23, 396, 28), // "on_Signup_btn_signup_clicked"
QT_MOC_LITERAL(24, 425, 20), // "on_Clear_btn_clicked"
QT_MOC_LITERAL(25, 446, 18), // "CheckButtonClicked"
QT_MOC_LITERAL(26, 465, 6), // "RowNum"
QT_MOC_LITERAL(27, 472, 20), // "UncheckButtonClicked"
QT_MOC_LITERAL(28, 493, 10), // "AddMyorder"
QT_MOC_LITERAL(29, 504, 11), // "AddUGVorder"
QT_MOC_LITERAL(30, 516, 11), // "updateOrder"
QT_MOC_LITERAL(31, 528, 14), // "updateUGVorder"
QT_MOC_LITERAL(32, 543, 19), // "on_UGV1_btn_clicked"
QT_MOC_LITERAL(33, 563, 24), // "on_Allorders_btn_clicked"
QT_MOC_LITERAL(34, 588, 23), // "on_Connect_UGV1_clicked"
QT_MOC_LITERAL(35, 612, 23), // "on_Connect_UGV2_clicked"
QT_MOC_LITERAL(36, 636, 32), // "on_Main_btn_createorders_clicked"
QT_MOC_LITERAL(37, 669, 21), // "on_Start_UGV1_clicked"
QT_MOC_LITERAL(38, 691, 18), // "onMQTTopicCallBack"
QT_MOC_LITERAL(39, 710, 3), // "msg"
QT_MOC_LITERAL(40, 714, 14), // "QMqttTopicName"
QT_MOC_LITERAL(41, 729, 5), // "topic"
QT_MOC_LITERAL(42, 735, 14), // "SubcribeTopics"
QT_MOC_LITERAL(43, 750, 18), // "on_CTE_btn_clicked"
QT_MOC_LITERAL(44, 769, 22), // "on_Heading_btn_clicked"
QT_MOC_LITERAL(45, 792, 18), // "on_ATE_btn_clicked"
QT_MOC_LITERAL(46, 811, 22), // "on_Velleft_btn_clicked"
QT_MOC_LITERAL(47, 834, 18), // "on_Vel_btn_clicked"
QT_MOC_LITERAL(48, 853, 14), // "subscribeToGPS"
QT_MOC_LITERAL(49, 868, 17), // "handleMqttMessage"
QT_MOC_LITERAL(50, 886, 7), // "message"
QT_MOC_LITERAL(51, 894, 17), // "addUserToDatabase"
QT_MOC_LITERAL(52, 912, 8), // "username"
QT_MOC_LITERAL(53, 921, 8), // "password"
QT_MOC_LITERAL(54, 930, 23), // "on_creorder_btn_clicked"
QT_MOC_LITERAL(55, 954, 28), // "on_Main_btn_products_clicked"
QT_MOC_LITERAL(56, 983, 25), // "on_comNum_sb_valueChanged"
QT_MOC_LITERAL(57, 1009, 4), // "arg1"
QT_MOC_LITERAL(58, 1014, 25), // "on_bunNum_sb_valueChanged"
QT_MOC_LITERAL(59, 1040, 26), // "on_cafeNum_sb_valueChanged"
QT_MOC_LITERAL(60, 1067, 24), // "on_miNum_sb_valueChanged"
QT_MOC_LITERAL(61, 1092, 29), // "on_src_ccb_currentTextChanged"
QT_MOC_LITERAL(62, 1122, 31), // "on_src_ccb_2_currentTextChanged"
QT_MOC_LITERAL(63, 1154, 22), // "on_pid_stm_btn_clicked"
QT_MOC_LITERAL(64, 1177, 22) // "on_set_pid_btn_clicked"

    },
    "MainWindow\0positionReceived\0\0point\0"
    "wayPointSelected\0pointList\0realPathCleared\0"
    "OrderReceived\0myorder\0Myorder\0"
    "UGVorderReceived\0UGVorder\0"
    "on_Signin_btn_signin_clicked\0"
    "on_Signin_btn_signup_clicked\0"
    "on_Signin_btn_settings_clicked\0"
    "on_Signin_btn_login_clicked\0"
    "on_Account__btnlogout_clicked\0resizeEvent\0"
    "QResizeEvent*\0event\0on_Main_btn_robots_clicked\0"
    "on_Main_btn_orders_clicked\0"
    "on_Main_btn_tracking_clicked\0"
    "on_Signup_btn_signup_clicked\0"
    "on_Clear_btn_clicked\0CheckButtonClicked\0"
    "RowNum\0UncheckButtonClicked\0AddMyorder\0"
    "AddUGVorder\0updateOrder\0updateUGVorder\0"
    "on_UGV1_btn_clicked\0on_Allorders_btn_clicked\0"
    "on_Connect_UGV1_clicked\0on_Connect_UGV2_clicked\0"
    "on_Main_btn_createorders_clicked\0"
    "on_Start_UGV1_clicked\0onMQTTopicCallBack\0"
    "msg\0QMqttTopicName\0topic\0SubcribeTopics\0"
    "on_CTE_btn_clicked\0on_Heading_btn_clicked\0"
    "on_ATE_btn_clicked\0on_Velleft_btn_clicked\0"
    "on_Vel_btn_clicked\0subscribeToGPS\0"
    "handleMqttMessage\0message\0addUserToDatabase\0"
    "username\0password\0on_creorder_btn_clicked\0"
    "on_Main_btn_products_clicked\0"
    "on_comNum_sb_valueChanged\0arg1\0"
    "on_bunNum_sb_valueChanged\0"
    "on_cafeNum_sb_valueChanged\0"
    "on_miNum_sb_valueChanged\0"
    "on_src_ccb_currentTextChanged\0"
    "on_src_ccb_2_currentTextChanged\0"
    "on_pid_stm_btn_clicked\0on_set_pid_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  254,    2, 0x06 /* Public */,
       4,    1,  257,    2, 0x06 /* Public */,
       6,    0,  260,    2, 0x06 /* Public */,
       7,    1,  261,    2, 0x06 /* Public */,
      10,    1,  264,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  267,    2, 0x08 /* Private */,
      13,    0,  268,    2, 0x08 /* Private */,
      14,    0,  269,    2, 0x08 /* Private */,
      15,    0,  270,    2, 0x08 /* Private */,
      16,    0,  271,    2, 0x08 /* Private */,
      17,    1,  272,    2, 0x08 /* Private */,
      20,    0,  275,    2, 0x08 /* Private */,
      21,    0,  276,    2, 0x08 /* Private */,
      22,    0,  277,    2, 0x08 /* Private */,
      23,    0,  278,    2, 0x08 /* Private */,
      24,    0,  279,    2, 0x08 /* Private */,
      25,    1,  280,    2, 0x08 /* Private */,
      27,    1,  283,    2, 0x08 /* Private */,
      28,    1,  286,    2, 0x08 /* Private */,
      29,    1,  289,    2, 0x08 /* Private */,
      30,    0,  292,    2, 0x08 /* Private */,
      31,    0,  293,    2, 0x08 /* Private */,
      32,    0,  294,    2, 0x08 /* Private */,
      33,    0,  295,    2, 0x08 /* Private */,
      34,    0,  296,    2, 0x08 /* Private */,
      35,    0,  297,    2, 0x08 /* Private */,
      36,    0,  298,    2, 0x08 /* Private */,
      37,    0,  299,    2, 0x08 /* Private */,
      38,    2,  300,    2, 0x08 /* Private */,
      42,    0,  305,    2, 0x08 /* Private */,
      43,    0,  306,    2, 0x08 /* Private */,
      44,    0,  307,    2, 0x08 /* Private */,
      45,    0,  308,    2, 0x08 /* Private */,
      46,    0,  309,    2, 0x08 /* Private */,
      47,    0,  310,    2, 0x08 /* Private */,
      48,    0,  311,    2, 0x08 /* Private */,
      49,    2,  312,    2, 0x08 /* Private */,
      51,    2,  317,    2, 0x08 /* Private */,
      54,    0,  322,    2, 0x08 /* Private */,
      55,    0,  323,    2, 0x08 /* Private */,
      56,    1,  324,    2, 0x08 /* Private */,
      58,    1,  327,    2, 0x08 /* Private */,
      59,    1,  330,    2, 0x08 /* Private */,
      60,    1,  333,    2, 0x08 /* Private */,
      61,    1,  336,    2, 0x08 /* Private */,
      62,    1,  339,    2, 0x08 /* Private */,
      63,    0,  342,    2, 0x08 /* Private */,
      64,    0,  343,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 40,   39,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 40,   50,   41,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   52,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionReceived((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->wayPointSelected((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->realPathCleared(); break;
        case 3: _t->OrderReceived((*reinterpret_cast< myorder(*)>(_a[1]))); break;
        case 4: _t->UGVorderReceived((*reinterpret_cast< myorder(*)>(_a[1]))); break;
        case 5: _t->on_Signin_btn_signin_clicked(); break;
        case 6: _t->on_Signin_btn_signup_clicked(); break;
        case 7: _t->on_Signin_btn_settings_clicked(); break;
        case 8: _t->on_Signin_btn_login_clicked(); break;
        case 9: _t->on_Account__btnlogout_clicked(); break;
        case 10: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 11: _t->on_Main_btn_robots_clicked(); break;
        case 12: _t->on_Main_btn_orders_clicked(); break;
        case 13: _t->on_Main_btn_tracking_clicked(); break;
        case 14: _t->on_Signup_btn_signup_clicked(); break;
        case 15: _t->on_Clear_btn_clicked(); break;
        case 16: _t->CheckButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->UncheckButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->AddMyorder((*reinterpret_cast< myorder(*)>(_a[1]))); break;
        case 19: _t->AddUGVorder((*reinterpret_cast< myorder(*)>(_a[1]))); break;
        case 20: _t->updateOrder(); break;
        case 21: _t->updateUGVorder(); break;
        case 22: _t->on_UGV1_btn_clicked(); break;
        case 23: _t->on_Allorders_btn_clicked(); break;
        case 24: _t->on_Connect_UGV1_clicked(); break;
        case 25: _t->on_Connect_UGV2_clicked(); break;
        case 26: _t->on_Main_btn_createorders_clicked(); break;
        case 27: _t->on_Start_UGV1_clicked(); break;
        case 28: _t->onMQTTopicCallBack((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QMqttTopicName(*)>(_a[2]))); break;
        case 29: _t->SubcribeTopics(); break;
        case 30: _t->on_CTE_btn_clicked(); break;
        case 31: _t->on_Heading_btn_clicked(); break;
        case 32: _t->on_ATE_btn_clicked(); break;
        case 33: _t->on_Velleft_btn_clicked(); break;
        case 34: _t->on_Vel_btn_clicked(); break;
        case 35: _t->subscribeToGPS(); break;
        case 36: _t->handleMqttMessage((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QMqttTopicName(*)>(_a[2]))); break;
        case 37: { bool _r = _t->addUserToDatabase((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->on_creorder_btn_clicked(); break;
        case 39: _t->on_Main_btn_products_clicked(); break;
        case 40: _t->on_comNum_sb_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_bunNum_sb_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_cafeNum_sb_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_miNum_sb_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_src_ccb_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->on_src_ccb_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->on_pid_stm_btn_clicked(); break;
        case 47: _t->on_set_pid_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< myorder >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< myorder >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< myorder >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< myorder >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::positionReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::wayPointSelected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::realPathCleared)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(myorder );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::OrderReceived)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(myorder );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UGVorderReceived)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::positionReceived(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::wayPointSelected(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::realPathCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::OrderReceived(myorder _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::UGVorderReceived(myorder _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
