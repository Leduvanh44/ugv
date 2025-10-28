#include "mainwindow.h"
#include "ui_UGV_UI.h"
#include <QDebug>
int i=0;

void MainWindow::on_Connect_UGV1_clicked()
{
    setupPlot();
//    if(!connect_robot.value(1)){
//        id_robot.insert("UGV1",0);
//        connect_robot.insert(0,new Mavsdk);
//        connectUGV(QString("UGV1"));
//            currLat[0] = 0;
//            currLon[0] = 0;
//            currRealHeading[0] = 0;
        auto status = "Status_UGV1";
        ui->Page_robots->findChild<QLabel *>(status)->setStyleSheet("background-color: rgb(0, 255, 0); ");

//        }

}

void MainWindow::on_Connect_UGV2_clicked()
{
    if(!connect_robot.value(2)){
        id_robot.insert("UGV2",1);
        connect_robot.insert(1,new Mavsdk);
        connectUGV(QString("UGV2"));
    }
}

void MainWindow::connectUGV(QString robot)
{
    QString IP = "IPAddress_" + robot;
    QString port = "Port_" + robot;
    QString status = "Status_" + robot;

// Open MAVLink's connection with the autopilot
      connect_robot.value(id_robot.value(robot))->set_configuration(Mavsdk::Configuration(255, 0));
      QString url = "udp://" + ui->Page_robots->findChild<QLineEdit *>(IP)->text() + ":" + ui->Page_robots->findChild<QLineEdit *>(port)->text();
      connect_robot.value(id_robot.value(robot))->add_any_connection(url.toStdString());
// Check connect fail
      int i=0;
      while (!connect_robot.value(id_robot.value(robot))->is_connected()){
          if (i == 2){
             QMessageBox::critical(this, QLatin1String("Connect fail"), QLatin1String("Is Robot power on?"));
             connect_robot.value(id_robot.value(robot))->~Mavsdk();
             connect_robot.remove(id_robot.value(robot));
             return;
          }
          sleep(1);
          i = i +1;
      }

    ui->Page_robots->findChild<QLabel *>(status)->setStyleSheet("background-color: rgb(0, 255, 0); ");

    // Subscribe to the current odometry
    System &system = connect_robot.value(id_robot.value(robot))->system();
    auto mavlink_passthrough = std::make_shared<MavlinkPassthrough>(system);

    mavlink_passthrough->subscribe_message_async(
        MAVLINK_MSG_ID_VIAM_ODOMETRY, [mavlink_passthrough,robot, this](const mavlink_message_t& msg) {
          mavlink_viam_odometry_t pack;
          mavlink_msg_viam_odometry_decode(&msg, &pack);
          currLat[id_robot.value(robot)] = pack.lat * 1e-7;
          currLon[id_robot.value(robot)] = pack.lon * 1e-7;
          currRealHeading[id_robot.value(robot)] = double(pack.yaw * 180.0f / M_PIf32);

          emit positionReceived(QVariant::fromValue(QGeoCoordinate( currLat[id_robot.value(robot)], currLon[id_robot.value(robot)])));
        });

    // Subscribe to the current setpoint for heading tracking
    mavlink_passthrough->subscribe_message_async(MAVLINK_MSG_ID_VIAM_SETPOINT,
                                                 [mavlink_passthrough,robot, this](const mavlink_message_t& msg) {
                                                   mavlink_viam_setpoint_t pack;
                                                   mavlink_msg_viam_setpoint_decode(&msg, &pack);
                                                   currSetHeading[id_robot.value(robot)] = double(pack.yaw * 180.0f / M_PIf32);
                                                 });

    // Subscribe to the current CTE for heading tracking
    mavlink_passthrough->subscribe_message_async(MAVLINK_MSG_ID_VIAM_ERROR,
                                                 [mavlink_passthrough, this](const mavlink_message_t& msg) {
                                                   mavlink_viam_error_t pack;
                                                   mavlink_msg_viam_error_decode(&msg, &pack);
                                                   currCTE = double(pack.cross_track);

                                                 });

    // Subscribe to the current set velocity for left and right pairs of wheels
    mavlink_passthrough->subscribe_message_async(MAVLINK_MSG_ID_VIAM_DIFF_VEL,
                                                 [mavlink_passthrough, this](const mavlink_message_t& msg) {
                                                   mavlink_viam_diff_vel_t pack;
                                                   mavlink_msg_viam_diff_vel_decode(&msg, &pack);
                                                   currSetMotorVel[0] = double(pack.left_vel);
                                                   currSetMotorVel[1] = double(pack.right_vel);


                                                 });
  //   Subscribe to the current set velocity for left and right pairs of wheels
    mavlink_passthrough->subscribe_message_async(MAVLINK_MSG_ID_VIAM_INDOOR,
                                                 [mavlink_passthrough, this](const mavlink_message_t& msg) {
                                                   mavlink_viam_indoor_t pack;
                                                   mavlink_msg_viam_indoor_decode(&msg, &pack);
                                                  currMotorVel[0] = double(pack.x_in);
                                                  currMotorVel[1] = double(pack.y_in);
                                                 });

}

void MainWindow::on_Start_UGV1_clicked()
{
    listaddr_robot.clear();
    Listlocation.append("0");
    for(int i = 0; i != ui->UGV1_table->rowCount();i++){
        Listlocation.append(changelocate.values(ui->UGV1_table->item(i,5)->text()));
        ui->UGV1_table->item(i,7)->setText("SHIPPING");
    }
    Listlocation.append("0");
    listaddr_robot.insert(id_robot.value(ui->Robot_label1->text()),Listlocation);
    startUGV("UGV1",listaddr_robot);
    updateorderUGV->stop();



}



