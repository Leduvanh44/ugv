QT      += core gui
QT      += sql
QT      += mqtt positioning qml quick printsupport
 QT += quickwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_LFLAGS += -no-pie
CONFIG += c++11
TARGET = Desktop_appUGV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dashboard.cpp \
    Logfile.cpp \
    MQTT.cpp \
    ManageRobot.cpp \
    Order.cpp \
    Plotting.cpp \
    SigninSignup.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    UGV_UI.ui \
    plotdata.ui

TRANSLATIONS += \
    Desktop_appUGV_vi_VN.ts

# Default rules for deployment.


#target.path = -L/usr/local/lib/ -lmavsdk
#target.path = -L/usr/local/lib/ -lmavsdk_mavlink_passthrough
#target.path = -L/usr/local/lib/ -lmavsdk_telemetry
#target.path = -L/usr/local/lib/ -lmavsdk_mission
#target.path = -L/usr/local/lib/ -lmavsdk_action

#INCLUDEPATH += /usr/local/include/mavsdk
#DEPENDPATH += /usr/local/include/mavsdk

RESOURCES += \
    resources/icon.qrc

DISTFILES += \
    resources/logo/Logo BK.png \
    resources/logo/Name_icon.png \
    resources/logo/User_icon.png \
    resources/logo/akar-icons_person.png \
    resources/logo/createorder_icon.png \
    resources/logo/icon_manage.png \
    resources/logo/icon_shop.png \
    resources/logo/icon_tracking.png \
    resources/logo/logout_icon.png \
    resources/logo/phone_ic.png \
    resources/logo/phone_icon.png \
    resources/logo/products_icon.png \
    resources/logo/setting_icon.png \
    resources/logo/staff_icon.png
