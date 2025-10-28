#include "mainwindow.h"
#include "ui_UGV_UI.h"
#include <QApplication>
#include <qfile.h>
#include <iostream>

#include "QDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  //  QFontDatabase::addApplicationFont(":/Roboto/Roboto-Regular.ttf");

    ui->setupUi(this);
    ui->Page->setCurrentIndex(0);
    ui->Dashboard->setCurrentIndex(1);
// Set up MQTT Client
    mqttClient = new QMqttClient(this);
//    mqttClient->setHostname("10.28.79.230");
//    mqttClient->setPort(4040);
//    mqttClient->setUsername("AGV");
//    mqttClient->setPassword("123456");
//    mqttClient->connectToHost();
    num_com = 0;
    num_bun = 0;
    num_cafe = 0;
    num_mi = 0;
    first_loc = 0;
    des_loc = 0;
    price = 0;
    left.kd = 0;
    left.kp = 10;
    left.ki = 1;
    right.kd = 0;
    right.kp = 9;
    right.ki = 1;
    ui->UGV1_table->setColumnWidth(0, 2*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(1, 4*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(2, 3*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(3, 4*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(4, 3*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(5, 3*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(6, 2*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(7, 3*(ui->Page->width())/24);
// Setup timer for periodic events
    updateorder = new QTimer(this);
    updateorderUGV = new QTimer(this);
    dataLogger = new QTimer(this);
    currentTime = QDateTime::currentDateTime();
    command = 16;
//    updateorder->start(500);

//    updateorderUGV->start(500);

// Load .qml root file into the system
    QQuickView* view = new QQuickView();
    view->setSource(QUrl("qrc:/qml/map.qml"));
    ui->verticalLayout_27->addWidget(QWidget::createWindowContainer(view, this));
    mapView = view->rootObject();


    headingPlotter = new QTimer(this);
    CTEPlotter = new QTimer(this);
    ATEPlotter = new QTimer(this);

    VelleftPlotter = new QTimer(this);
    VelPlotter = new QTimer(this);
    dataLogger = new QTimer(this);
//    plotdata = new QCustomPlot(this);
//    plotdata->show();

// Signal Slot
  /*  connect(mqttClient, &QMqttClient::messageReceived, this, &MainWindow::onMQTTopicCallBack);
    connect(mqttClient, &QMqttClient::connected, this, &MainWindow::SubcribeTopics)*/;
    connect(updateorder, &QTimer::timeout, this, &MainWindow::updateOrder);
    connect(updateorderUGV, &QTimer::timeout, this, &MainWindow::updateUGVorder);
    connect(&ButtonSignalMapper, SIGNAL(mapped(int)), this, SLOT(CheckButtonClicked(int)));
    connect(&ButtonSignalMapper1, SIGNAL(mapped(int)), this, SLOT(UncheckButtonClicked(int)));
    connect(this, SIGNAL(positionReceived(QVariant)), mapView, SLOT(updateRealPath(QVariant)));  
    connect(this, SIGNAL(wayPointSelected(QVariant)), mapView, SLOT(createDesiredPath(QVariant)));
    connect(this, SIGNAL(realPathCleared()), mapView, SLOT(clearRealPath()));
    connect(this,SIGNAL(OrderReceived(myorder)), this, SLOT(AddMyorder(myorder)));
    connect(this,SIGNAL(UGVorderReceived(myorder)),this, SLOT(AddUGVorder(myorder)));
    connect(dataLogger, &QTimer::timeout, this, &MainWindow::logData);
    connect(headingPlotter, &QTimer::timeout, this, &MainWindow::plotHeading);
    connect(CTEPlotter, &QTimer::timeout, this, &MainWindow::plotCTE);
    connect(ATEPlotter, &QTimer::timeout, this, &MainWindow::plotATE);
    connect(VelleftPlotter, &QTimer::timeout, this, &MainWindow::plotvelleft);
    connect(VelPlotter, &QTimer::timeout, this, &MainWindow::plotvel);
// Retrieve related data of places from .qml
    QStringList lat = mapView->property("latList").toStringList();
    QStringList lon = mapView->property("lonList").toStringList();
    QStringList name = mapView->property("nameList").toStringList();
    QStringList edge = mapView->property("edgeList").toStringList();
    QStringList locate = mapView->property("location").toStringList();
    for (int i = 0; i < name.size(); i++)
    {
      IDList.insert(make_pair(name[i].toStdString(), i));
      latList.insert(make_pair(i, lat[i].toDouble()));
      lonList.insert(make_pair(i, lon[i].toDouble()));
    }

    for (int i=0; i!=llist.count();i++){
        changelocate.insert(locate[i],llist[i]);
    }

// Initialize graph for shortest-path planning
    typedef pair<int, int> Edge;
    vector<Edge> edges;
    vector<double> weights;
    for (auto it : edge)
    {
      // Create edges
      QStringList id = it.split(QLatin1Char(','));
      int id0 = id[0].toInt();
      int id1 = id[1].toInt();
      edges.push_back(Edge(id0, id1));

      // Create distance-based weights
        double dist = convertLatLonToDistance(latList[id0], latList[id0], latList[id1], latList[id1]);
//        double dist = 1.0;
        weights.push_back(dist);
    }
    graph = new graph_t(edges.data(), edges.data() + edges.size(), weights.data(), size_t(name.size()));


    QFile f(":/csv/log_test_C1newroom_09052022(IN).csv");
       if (f.open(QIODevice::ReadOnly))
       {

           //file opened successfully
           QString data;
           data = f.readAll();
           wordList = data.split('\n');
           wordList.removeAt(wordList.size()-1);
//          qDebug() << wordList;
           f.close();
       }
       for(auto it = 0; it != wordList.size();it++)
       {
             auto data =  wordList[it].split(',');
//             coords.push_back(QGeoCoordinate(data[0].toDouble(),data[1].toDouble()));
              currsetheading.push_back(data[2].toDouble());
              currrealheading.push_back(data[3].toDouble());
              currcte.push_back(data[4].toDouble());
      }
//MQTT setting
       publishTimer = new QTimer(this);
       connect(publishTimer, &QTimer::timeout, this, &MainWindow::publishCommand);
       publishTimer->start(2000);
       start_cmd = 0x30;

       subcriberTimer = new QTimer(this);
       connect(subcriberTimer, &QTimer::timeout, this, &MainWindow::subscribeToGPS);
       subcriberTimer->setInterval(5000);
       subcriberTimer->start();
       connect(mqttClient, &QMqttClient::messageReceived, this, &MainWindow::handleMqttMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
// Connect Database
    //db = QSqlDatabase::addDatabase("QMYSQL");
  //  db.setHostName("127.0.0.1");
   // db.setUserName("deliveryrobot");
   // db.setPassword("123456");
   // db.setDatabaseName("delivery_robot");
   // if(db.open()){
//        qDebug() << "Database Connected Successfully";
//    }
//    else{
//        qDebug() << "Database is not connected";
//    }



    w.show();
    return a.exec();
}

bool MainWindow::addUserToDatabase(const QString& username, const QString& password) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Failed to open database!";
        return false;
    }
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "username TEXT PRIMARY KEY,"
                    "password TEXT)")) {
        qDebug() << "Failed to create table!";
        return false;
    }
    query.prepare("INSERT INTO users (username, password) "
                  "VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Failed to add user!";
        return false;
    }

    db.close();

    return true;
}

void MainWindow::subscribeToGPS() {
    auto subscription_err = mqttClient->subscribe(QMqttTopicFilter("err"));
    auto subscription_gps = mqttClient->subscribe(QMqttTopicFilter("gps"));
    auto subscription_h = mqttClient->subscribe(QMqttTopicFilter("heading"));
    auto subscription_vel = mqttClient->subscribe(QMqttTopicFilter("setvel"));
    auto subscription_realvel = mqttClient->subscribe(QMqttTopicFilter("realvel"));
    auto subscription_desire = mqttClient->subscribe(QMqttTopicFilter("desirepoint"));
    if (!subscription_realvel && mqttClient->state() == QMqttClient::Connected) {
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
            return;
        }
}

void MainWindow::handleMqttMessage(const QByteArray &message, const QMqttTopicName &topic) {
if (topic == QMqttTopicName("gps")) {
    alo = QString::fromUtf8(message).split(',');
    if (coords_alo.size() == 10) {
        coords_alo.clear();
    }
//    coords_alo.clear();
    coords_alo.push_back(QGeoCoordinate(alo[0].toDouble(), alo[1].toDouble()));
    bool ok3;
    double value3 = alo[2].toDouble(&ok3);
    if (ok3) {
        currRealHeading[0] = value3;
    }

    qDebug() << "lmao: " << coords_alo.back() << coords_alo.size();
    emit positionReceived(QVariant::fromValue(coords_alo.back()));

 /*   for(auto it = 0; it < alo.size();it++)
    {
          auto data =  alo[it];
          coords.push_back(QGeoCoordinate(data[0].toDouble(),data[1].toDouble()));*/
    qDebug() << alo;
}
//    coords.push_back(QGeoCoordinate(data[0].toDouble(),data[1].toDouble()));
if (topic == QMqttTopicName("setvel")) {
    QList<QString> values = QString::fromUtf8(message).split(",");
    qDebug() << values;
    if (values.size() == 2) {
        bool ok1;
        double value1 = values[0].toDouble(&ok1);
        if (ok1) {
            currSetMotorVel[0] = value1;
        }
        bool ok2;
        double value2 = values[1].toDouble(&ok2);
        if (ok2) {
            currSetMotorVel[1] = value2;
        }

}
    qDebug() << currSetMotorVel;

}
if (topic == QMqttTopicName("realvel")) {
QList<QString> values = QString::fromUtf8(message).split(",");
qDebug() << values;
if (values.size() == 2) {
   bool ok1;
   double value1 = values[0].toDouble(&ok1);
   if (ok1) {
       currMotorVel[0] = value1;
   }
   bool ok2;
   double value2 = values[1].toDouble(&ok2);
   if (ok2) {
       currMotorVel[1] = value2;
   }
}
qDebug() << currMotorVel;

}
    if (topic == QMqttTopicName("err")) {
    QList<QString> values = QString::fromUtf8(message).split(",");
    qDebug() << values;
    if (values.size() == 2) {
        bool ok1;
        double value1 = values[0].toDouble(&ok1);
        if (ok1) {
            currATE = value1;
        }
        bool ok2;
        double value2 = values[1].toDouble(&ok2);
        if (ok2) {
            currCTE = value2;
        }
    }
    qDebug() << currCTE << "alo";

}
    if (topic == QMqttTopicName("desirepoint")) {
    QList<QString> values = QString::fromUtf8(message).split(",");
    qDebug() << values;
    if (values.size() == 2) {
        bool ok1;
        double value1 = values[1].toDouble(&ok1);
        if (ok1) {
            currSetheading = value1;
        }
}
    qDebug() << currSetheading << "heading";
    }
    if (topic == QMqttTopicName("heading")) {

        currHeading = message.toDouble();


    }
}

double MainWindow::convertLatLonToDistance(double lat1, double lon1, double lat2, double lon2)
{
  // Calculate distance in meter between two coordinates
  double rlat1, rlat2, drlat, drlng, a, c, distance;
  double R = 6371000;
  rlat1 = lat1 * M_PI / 180.0;
  rlat2 = lat2 * M_PI / 180.0;
  drlat = (lat2 - lat1) * M_PI / 180.0;
  drlng = (lon2 - lon1) * M_PI / 180.0;
  a = sin(drlat / 2) * sin(drlat / 2) + cos(rlat1) * cos(rlat2) * sin(drlng / 2) * sin(drlng / 2);
  c = 2 * atan2(sqrt(a), sqrt(1 - a));
  distance = fabs(R * c);
  return distance;
}

void MainWindow::startUGV(QString name,QMap<int,QStringList>& location){
    setupPlot();
    // Search for matching IDs of two end places
//    string srcName = location.value(id_robot.value(name)).value(0).toStdString();
//    string destName = location.value(id_robot.value(name)).value(1).toStdString();
    string srcName = std::to_string(first_loc);
    string destName = std::to_string(des_loc);
//    float indoor =1.3f;
//    if (location.value(id_robot.value(name)).value(0).toStdString()  == "51" and location.value(id_robot.value(name)).value(1).toStdString() != "51")
//    {
//        indoor = 3.1f;
//        srcName = "1";
//        destName = location.value(id_robot.value(name)).value(1).toStdString();
//    }
//    else if(location.value(id_robot.value(name)).value(0).toStdString() == "50" and location.value(id_robot.value(name)).value(1).toStdString() != "50"){
//        indoor = 2.1f;
//        srcName = "1";
//        destName = location.value(id_robot.value(name)).value(1).toStdString();
//    }
//    else if(location.value(id_robot.value(name)).value(0).toStdString() != "50" and location.value(id_robot.value(name)).value(1).toStdString() == "51"){
//        indoor = 1.3f;
//        srcName = location.value(id_robot.value(name)).value(0).toStdString();
//        destName = "1";
//    }
//    else if(location.value(id_robot.value(name)).value(0).toStdString() != "51" and location.value(id_robot.value(name)).value(1).toStdString() == "50"){
//        indoor = 1.2f;
//        srcName = location.value(id_robot.value(name)).value(0).toStdString();
//        destName = "1";
//    }
//    else if(location.value(id_robot.value(name)).value(0).toStdString() == "50" and location.value(id_robot.value(name)).value(1).toStdString() == "51")
//        indoor = 2.3f;
//    else if(location.value(id_robot.value(name)).value(0).toStdString() == "51" and location.value(id_robot.value(name)).value(1).toStdString() == "50")
//        indoor = 3.2f;
    int srcId = IDList[srcName];
    int destId = IDList[destName];
    qDebug() << srcId << destId;

    // Find the shortest path between two end places
    vector<vertex_descriptor> p(num_vertices(*graph));
    vector<int> d(num_vertices(*graph));
    vertex_descriptor s = vertex(size_t(srcId), *graph);
    dijkstra_shortest_paths(*graph, s, predecessor_map(&p[0]).distance_map(&d[0]));

    // Retrieve coordinates of places along the path (in reverse order)

    auto tempId = destId;
    qDebug() << tempId;
    while (tempId != srcId)
    {
      path.push_back(QGeoCoordinate(double(latList[tempId]), double(lonList[tempId])));
      tempId = p[tempId];
      qDebug() << tempId;
    }
    path.push_back(QGeoCoordinate(latList[srcId], lonList[srcId]));
    if (currMotorVel[0] != 0 && currMotorVel[1] != 0) {
        setupPlot();
    }
    for (int i = 0; i < path.size(); i++) {
        emit wayPointSelected(QVariant::fromValue(path[i]));
        qDebug() << QVariant::fromValue(path);
    }
//    emit wayPointSelected(QVariant::fromValue(path));
    qDebug() << "path: "<<(path);

    emit realPathCleared();

    // Update the desired path

//    desiredPath.clear();
//    for (auto it = path.rbegin(); it != path.rend(); it++)
//    desiredPath.push_back(*it);


    // Clear real path and heading plot
//    emit realPathCleared();

////     Start mission with the current path
//    if(indoor == 3.1f || indoor == 2.1f){
//        startMission(desiredPath,id_robot.value(name),indoor);
//        usleep(500);
//    }
//    startMission(desiredPath,id_robot.value(name),indoor);


}


void MainWindow::startMission(const QList<QGeoCoordinate>& path,int id, float indoor)
{
  // Send mission items to autopilot
//  System& system = connect_robot.value(id)->system();
//  auto mission = std::make_shared<Mission>(system);
//  Mission::MissionPlan mission_plan;
//  for (auto it = path.begin(); it != path.end(); it++)
//  {
//    Mission::MissionItem new_item;
//    new_item.latitude_deg = it->latitude();
//    new_item.longitude_deg = it->longitude();
//    new_item.relative_altitude_m = indoor;
//    mission_plan.mission_items.push_back(new_item);
//  }
//  mission->set_return_to_launch_after_mission(false);
//  mission->upload_mission(mission_plan);

//  // Arm the autopilot
////  auto action = std::make_shared<Action>(system);
////  action->arm();

//  // Set the autopilot's mode
//  auto mavlink_passthrough = std::make_shared<MavlinkPassthrough>(system);
//  {
//    mavlink_set_mode_t pack;
//    pack.target_system = mavlink_passthrough->get_target_sysid();
//    pack.base_mode = 1;
//    pack.custom_mode = 2; // LOS_STRAIGHT

//    mavlink_message_t msg;
//    mavlink_msg_set_mode_encode(mavlink_passthrough->get_our_sysid(), mavlink_passthrough->get_our_compid(), &msg,
//                                &pack);
//    mavlink_passthrough->send_message(msg);
//  }

//  // Request the autopilot to start mission
//  {
//    mavlink_command_long_t pack;
//    pack.target_system = mavlink_passthrough->get_target_sysid();
//    pack.target_component = mavlink_passthrough->get_target_compid();
//    pack.command = MAV_CMD_MISSION_START;

//    mavlink_message_t msg;
//    mavlink_msg_command_long_encode(mavlink_passthrough->get_our_sysid(), mavlink_passthrough->get_our_compid(), &msg,
//                                    &pack);
//    mavlink_passthrough->send_message(msg);
//  }
}



void MainWindow::on_creorder_btn_clicked()
{
    int rowIndex = ui->UGV1_table->rowCount();qDebug() << "rowIndex: " << rowIndex;

    ui->UGV1_table->setRowCount(rowIndex + 1);
    ui->UGV1_table->setColumnCount(8);
    QString value;
    for(int j = 0; j != 8; j++){
        switch (j) {
        case 0:
        {
           value = QString::number(rowIndex + 1);
            break;
        }
        case 1:
        {
            value = ui->date_time_le->text();
            break;
        }
        case 2:
        {
            value = ui->customer_name_le->text();
            break;
        }
        case 3:
        {
           value = "lmao";
            break;
        }
        case 4:
        {
           value = QString("%L1").arg(price) + "000 VNĐ";
            break;
        }
        case 5:
        {
            value = ui->src_ccb_2->currentText();
            break;
        }
        case 6:
        {
            value = "#404";
            break;
        }
        case 7:
        {
            value = "PACKING";
//            if (UGVorder.order_status == "0") value = "PACKING";
//            else if(UGVorder.order_status == "1") value = "SHIPPING";
//            else if(UGVorder.order_status == "2") value = "DELIVERED";
            break;
        }
        default:
            break;
        }

       QTableWidgetItem *orderitem = new QTableWidgetItem(value);
       ui->UGV1_table->setItem(rowIndex, j , orderitem);
       orderitem->setTextAlignment(Qt::AlignCenter);
     }
    ui->priceNum_lcd->display(0);
    ui->customer_name_le->clear();
    ui->date_time_le->clear();
    ui->comNum_sb->clear();
    ui->bunNum_sb->clear();
    ui->cafeNum_sb->clear();
    ui->miNum_sb->clear();
    ui->UGV1_table->show();
    ui->Page->setCurrentIndex(2);
    ui->Main_btn->setStyleSheet("QPushButton#Main_btn_orders{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_comNum_sb_valueChanged(int arg1)
{
    num_com = arg1;
    price = (num_com * 30 + num_bun * 30 + num_cafe * 15 + num_mi * 25);
    qDebug() << num_com * 30 << "  "<< price;
    ui->priceNum_lcd->display(price);
}

void MainWindow::on_bunNum_sb_valueChanged(int arg1)
{
    num_bun = arg1;
    price = num_com * 30 + num_bun * 30 + num_cafe * 15 + num_mi * 25;
    ui->priceNum_lcd->display(price);
}

void MainWindow::on_cafeNum_sb_valueChanged(int arg1)
{
    num_cafe = arg1;
    price = num_com * 30 + num_bun * 30 + num_cafe * 15 + num_mi * 25;
    ui->priceNum_lcd->display(price);
}

void MainWindow::on_miNum_sb_valueChanged(int arg1)
{
    num_mi = arg1;
    price = num_com * 30 + num_bun * 30 + num_cafe * 15 + num_mi * 25;
    ui->priceNum_lcd->display(price);
}



void MainWindow::on_src_ccb_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Toa B3") {
        first_loc = 0;
    }
    else if (arg1 == "Toa A1") {
        first_loc = 2;
    }
    else {
        first_loc = 3;
    }
}

void MainWindow::on_src_ccb_2_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Toa B3") {
        des_loc = 0;
    }
    else if (arg1 == "Toa A1") {
        des_loc = 2;
    }
    else {
        des_loc = 3;
    }
}

