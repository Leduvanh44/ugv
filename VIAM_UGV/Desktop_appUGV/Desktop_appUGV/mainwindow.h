#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QQuickWidget>
#include <QMainWindow>
#include <QFontDatabase>
#include <QMainWindow>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtMqtt/QtMqtt>
#include <QComboBox>
#include <QGeoCoordinate>
#include <QQuickItem>
#include <QQuickView>
#include <QThread>
#include <mavsdk/mavsdk.h>
#include <mavsdk/system.h>
#include <mavsdk/plugins/mavlink_passthrough/mavlink_passthrough.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <mavsdk/plugins/mission/mission.h>
#include <mavsdk/plugins/action/action.h>
#include <QTableWidgetItem>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "plotdata.h"


#include <iostream>
#include <fstream>
#include <iomanip>

typedef struct
{
    QString order_id;
    QString order_date;
    QString customer_name;
    QString order_products;
    QString order_price;
    QString order_address;
    QString order_QRcode;
    QString order_robot;
    QString order_status;
}myorder;

Q_DECLARE_METATYPE(myorder);

using namespace mavsdk;
using namespace boost;
using namespace std;

typedef adjacency_list<listS, vecS, directedS, no_property, property<edge_weight_t, double>> graph_t;
typedef graph_traits<graph_t>::vertex_descriptor vertex_descriptor;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



extern    QSqlDatabase db;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:
  void positionReceived(QVariant point);
//  void wayPointSelected(QVariant pointList);
//  void realPathCleared();
  void wayPointSelected(QVariant pointList);
  void realPathCleared();
  void OrderReceived(myorder Myorder);
  void UGVorderReceived(myorder UGVorder);

private slots:
    void on_Signin_btn_signin_clicked();

    void on_Signin_btn_signup_clicked();

    void on_Signin_btn_settings_clicked();

    void on_Signin_btn_login_clicked();

    void on_Account__btnlogout_clicked();

    void resizeEvent(QResizeEvent *event);

    void on_Main_btn_robots_clicked();

    void on_Main_btn_orders_clicked();

    void on_Main_btn_tracking_clicked();

    void on_Signup_btn_signup_clicked();

    void on_Clear_btn_clicked();

    void CheckButtonClicked(int RowNum);

    void UncheckButtonClicked(int RowNum);

    void AddMyorder(myorder Myorder);

    void AddUGVorder(myorder UGVorder);

    void updateOrder();

    void updateUGVorder();

    void on_UGV1_btn_clicked();

    void on_Allorders_btn_clicked();

    void on_Connect_UGV1_clicked();

    void on_Connect_UGV2_clicked();

    void on_Main_btn_createorders_clicked();

    void on_Start_UGV1_clicked();

    void onMQTTopicCallBack(const QByteArray &msg, const QMqttTopicName &topic);

    void SubcribeTopics();

    void on_CTE_btn_clicked();

    void on_Heading_btn_clicked();

    void on_ATE_btn_clicked();

    void on_Velleft_btn_clicked();

    void on_Vel_btn_clicked();


private:
    Ui::MainWindow *ui;
    PlotData *plotdata;
    QString user, password, rules, name;

    QTimer* updateorder;
    QTimer* updateorderUGV;
    QTimer* dataLogger;
    QElapsedTimer plotTimer;
    QElapsedTimer logTimer;
    QTimer* headingPlotter;
    QTimer* CTEPlotter;
    QTimer* ATEPlotter;
    QTimer* VelleftPlotter;
    QTimer* VelPlotter;

    QSignalMapper ButtonSignalMapper;
    QSignalMapper ButtonSignalMapper1;

    QStringList Orderid_list;
    QMqttClient* mqttClient;


    map<string, int> IDList;
    map<int, double> latList;
    map<int, double> lonList;
    QStringList Listlocation;
    QMap<QString,QString> changelocate;
    QStringList llist = {"0","1","2","3","4","5","50","51"};

    QList<System*> system;
    QMap<QString,int> id_robot;
    QMap<int,Mavsdk*>  connect_robot;
    QMap<int,QStringList> listaddr_robot;
    graph_t* graph;
    QList<QGeoCoordinate> desiredPath;


    double currCTE;
    double currATE;
    vector<double> currLat = {0,0};
    vector<double> currLon = {0,0};
    vector<double> currSetHeading  = {0,0};
    vector<double> currRealHeading = {0,0};
    vector<double> currSetMotorVel = {0, 0};
    vector<double> currMotorVel = {0, 0};

    QList<QString>wordList;
    QList<QGeoCoordinate> coords;
    QList<double> currlat;
    QList<double> currlon;
    QList<double> currsetheading;
    QList<double> currrealheading;
    QList<double> currcte;


    vector<double> timestampLog;
    vector<double> latLog;
    vector<double> lonLog;
    vector<double> setHeadingLog;
    vector<double> realHeadingLog;
    vector<double> CTELog;
    vector<vector<double>> setMotorVelLog;
    vector<vector<double>> currMotorVelLog;

    QQuickItem* mapView;

    void connectUGV(QString robot);
    double convertLatLonToDistance(double lat1, double lon1, double lat2, double lon2);
    void startMission(const QList<QGeoCoordinate>& path, int id, float indoor);
    void startUGV(QString name,QMap<int,QStringList>& location);
    void logData();
    void start_loggingData();
    void stop_loggingData();
    void openPlottingData();
    void plotHeading();
    void plotCTE();
    void plotATE();
    void plotvelleft();
    void plotvel();
    void setupPlot();
    void resetPlot();
};
#endif // MAINWINDOW_H
