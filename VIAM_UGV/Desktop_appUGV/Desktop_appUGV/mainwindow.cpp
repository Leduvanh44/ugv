#include "mainwindow.h"
#include "ui_UGV_UI.h"
#include <QApplication>
#include <qfile.h>
#include <iostream>
QSqlDatabase db;

#include "QDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    QFontDatabase::addApplicationFont(":/Roboto/Roboto-Regular.ttf");

    ui->setupUi(this);
    ui->Page->setCurrentIndex(0);
    ui->Dashboard->setCurrentIndex(0);
// Set up MQTT Client
    mqttClient = new QMqttClient(this);
    mqttClient->setHostname("broker.mqttdashboard.com");
    mqttClient->setPort(1883);
    mqttClient->setUsername("AGV");
    mqttClient->setPassword("123456");
    mqttClient->connectToHost();


// Setup timer for periodic events
    updateorder = new QTimer(this);
    updateorderUGV = new QTimer(this);
    dataLogger = new QTimer(this);
// Timer update order & UGVorder

    updateorder->start(500);

    updateorderUGV->start(500);

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
    plotdata = new PlotData(this);
    plotdata->show();


// Signal Slot
    connect(mqttClient, &QMqttClient::messageReceived, this, &MainWindow::onMQTTopicCallBack);
    connect(mqttClient, &QMqttClient::connected, this, &MainWindow::SubcribeTopics);
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


    QFile f(":/csv/120522XuongC1-B5.csv");
       if (f.open(QIODevice::ReadOnly))
       {

           //file opened successfully
           QString data;
           data = f.readAll();
           wordList = data.split('\n');
           wordList.removeAt(wordList.size()-1);
           qDebug() << wordList;
           f.close();
       }
       for(auto it = 0; it != wordList.size();it++)
       {
             auto data =  wordList[it].split(',');
             coords.push_back(QGeoCoordinate(data[0].toDouble(),data[1].toDouble()));
              currsetheading.push_back(data[2].toDouble());
              currrealheading.push_back(data[3].toDouble());
              currcte.push_back(data[4].toDouble());
      }




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
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("deliveryrobot");
    db.setPassword("123456");
    db.setDatabaseName("delivery_robot");
    if(db.open()){
        qDebug() << "Database Connected Successfully";
    }
    else{
        qDebug() << "Database is not connected";
    }



    w.show();
    return a.exec();
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
//    setupPlot();
    // Search for matching IDs of two end places
    string srcName = location.value(id_robot.value(name)).value(0).toStdString();
    string destName = location.value(id_robot.value(name)).value(1).toStdString();
    float indoor =1.3f;
    if (location.value(id_robot.value(name)).value(0).toStdString()  == "51" and location.value(id_robot.value(name)).value(1).toStdString() != "51")
    {
        indoor = 3.1f;
        srcName = "1";
        destName = location.value(id_robot.value(name)).value(1).toStdString();
    }
    else if(location.value(id_robot.value(name)).value(0).toStdString() == "50" and location.value(id_robot.value(name)).value(1).toStdString() != "50"){
        indoor = 2.1f;
        srcName = "1";
        destName = location.value(id_robot.value(name)).value(1).toStdString();
    }
    else if(location.value(id_robot.value(name)).value(0).toStdString() != "50" and location.value(id_robot.value(name)).value(1).toStdString() == "51"){
        indoor = 1.3f;
        srcName = location.value(id_robot.value(name)).value(0).toStdString();
        destName = "1";
    }
    else if(location.value(id_robot.value(name)).value(0).toStdString() != "51" and location.value(id_robot.value(name)).value(1).toStdString() == "50"){
        indoor = 1.2f;
        srcName = location.value(id_robot.value(name)).value(0).toStdString();
        destName = "1";
    }
    else if(location.value(id_robot.value(name)).value(0).toStdString() == "50" and location.value(id_robot.value(name)).value(1).toStdString() == "51")
        indoor = 2.3f;
    else if(location.value(id_robot.value(name)).value(0).toStdString() == "51" and location.value(id_robot.value(name)).value(1).toStdString() == "50")
        indoor = 3.2f;
    int srcId = IDList[srcName];
    int destId = IDList[destName];
    qDebug() << srcId << destId ;

    // Find the shortest path between two end places
    vector<vertex_descriptor> p(num_vertices(*graph));
    vector<int> d(num_vertices(*graph));
    vertex_descriptor s = vertex(size_t(srcId), *graph);
    dijkstra_shortest_paths(*graph, s, predecessor_map(&p[0]).distance_map(&d[0]));

    // Retrieve coordinates of places along the path (in reverse order)
    QList<QGeoCoordinate> path;
    auto tempId = destId;
    while (tempId != srcId)
    {
      path.push_back(QGeoCoordinate(latList[tempId], lonList[tempId]));
      tempId = p[tempId];
    }
    path.push_back(QGeoCoordinate(latList[srcId], lonList[srcId]));
    emit wayPointSelected(QVariant::fromValue(path));

    // Clear current real path
    emit realPathCleared();

    // Update the desired path
    desiredPath.clear();
    for (auto it = path.rbegin(); it != path.rend(); it++)
    desiredPath.push_back(*it);


    // Clear real path and heading plot
    emit realPathCleared();

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
  System& system = connect_robot.value(id)->system();
  auto mission = std::make_shared<Mission>(system);
  Mission::MissionPlan mission_plan;
  for (auto it = path.begin(); it != path.end(); it++)
  {
    Mission::MissionItem new_item;
    new_item.latitude_deg = it->latitude();
    new_item.longitude_deg = it->longitude();
    new_item.relative_altitude_m = indoor;
    mission_plan.mission_items.push_back(new_item);
  }
  mission->set_return_to_launch_after_mission(false);
  mission->upload_mission(mission_plan);

  // Arm the autopilot
//  auto action = std::make_shared<Action>(system);
//  action->arm();

  // Set the autopilot's mode
  auto mavlink_passthrough = std::make_shared<MavlinkPassthrough>(system);
  {
    mavlink_set_mode_t pack;
    pack.target_system = mavlink_passthrough->get_target_sysid();
    pack.base_mode = 1;
    pack.custom_mode = 2; // LOS_STRAIGHT

    mavlink_message_t msg;
    mavlink_msg_set_mode_encode(mavlink_passthrough->get_our_sysid(), mavlink_passthrough->get_our_compid(), &msg,
                                &pack);
    mavlink_passthrough->send_message(msg);
  }

  // Request the autopilot to start mission
  {
    mavlink_command_long_t pack;
    pack.target_system = mavlink_passthrough->get_target_sysid();
    pack.target_component = mavlink_passthrough->get_target_compid();
    pack.command = MAV_CMD_MISSION_START;

    mavlink_message_t msg;
    mavlink_msg_command_long_encode(mavlink_passthrough->get_our_sysid(), mavlink_passthrough->get_our_compid(), &msg,
                                    &pack);
    mavlink_passthrough->send_message(msg);
  }
}






