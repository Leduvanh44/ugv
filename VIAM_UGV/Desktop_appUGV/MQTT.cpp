#include "mainwindow.h"
#include "ui_UGV_UI.h"

void MainWindow::onMQTTopicCallBack(const QByteArray& msg, const QMqttTopicName& topic)
{

 if(topic.name() == "delivery") {
    QList<QString> data = QString(msg.data()).split(' ');
    if (data[1] == "done"){
        ui->UGV1_table->setItem(ui->UGV1_table->findItems(data[2],Qt::MatchExactly).at(0)->row(),7,new QTableWidgetItem("DELIVERED"));
        ui->UGV1_table->item(ui->UGV1_table->findItems(data[2],Qt::MatchExactly).at(0)->row(),7)->setForeground(QBrush(QColor(0,255,0)));
    //listaddr_robot[id_robot.value(data[0])].removeFirst();
//    desiredPath.clear();
//    if (listaddr_robot[id_robot.value(data[0])].isEmpty()) return;
//    stop_loggingData();
//    startUGV(data[0],listaddr_robot);
    }
  }
 if (topic.name() == "order")
 {

   // Save data of the message to the table
   QList<QString> data = QString(msg.data()).split(',');
//   QList<QByteArray> product = data[2].split(',');
    qDebug() << data;
// add data to Database

   QSqlQuery qry;
   qry.prepare("INSERT INTO delivery_robot.order (order_date, order_id, customer_id,order_total_price, order_address, order_QRcode )\
               VALUES (:date, :orderid, :customerid, :price, :address, :qrcode)");
   qry.bindValue(":date", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
   qry.bindValue(":orderid", data[0].toInt());
   qry.bindValue(":customerid", data[1].toInt());
   qry.bindValue(":price",data[2].toFloat());
   qry.bindValue(":address",data[3]);
   qry.bindValue(":qrcode",data[4]);
   qry.exec();

}

}

void MainWindow::SubcribeTopics(){
    while( !mqttClient->subscribe(QMqttTopicFilter("order")) or !mqttClient->subscribe(QMqttTopicFilter("delivery"))){
       QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
    }
}


void MainWindow::publishCommand()
{
    QString topic = "command";
    QByteArray mes;
    mes.append(start_cmd);
    if (!topic.isEmpty() && !mes.isEmpty() && mqttClient->state() == QMqttClient::Connected) {
        QMqttTopicName mqttTopic(topic);
        mqttClient->publish(mqttTopic, mes, 0);
        qDebug() << "Published: Topic: " + topic + " Message: " + QString::fromLatin1(mes.constData(), mes.size());;
    } else if (topic.isEmpty() && mes.isEmpty()){
        QMessageBox::warning(this, "Warning", "Please enter both topic and message.");
    }
    topic = "/mission/item_list";
    if (!topic.isEmpty() && mqttClient->state() == QMqttClient::Connected && !path.isEmpty()) {
        QString message;
        QString mes_command = QString::number(command) + "|";
        message += mes_command;
        QList <QGeoCoordinate> repath;
        QList<QGeoCoordinate>::const_reverse_iterator rit;
        for (rit = path.rbegin(); rit != path.rend(); ++rit) {
            repath.append(*rit);
        }
        for (const auto &coordinate : repath) {
           QString coordinateString = QString::number(coordinate.latitude(), 'f', 6) + ", " + QString::number(coordinate.longitude(), 'f', 6);
            message += coordinateString + "|";
        }
        message.chop(1);
        QMqttTopicName mqttTopic(topic);
        mqttClient->publish(mqttTopic, message.toUtf8(), 0);
        qDebug() << "Published path to topic: " << message;
    }
    topic = "pid_setting";
    if (mqttClient->state() == QMqttClient::Connected) {
        QJsonArray pidArray;
        QJsonObject pidObject;
        pidObject["name"] = "pid_left";
        pidObject["kp"] = left.kp;
        pidObject["kd"] = left.kd;
        pidObject["ki"] = left.ki;
        pidArray.append(pidObject);
        pidObject["name"] = "pid_right";
        pidObject["kp"] = right.kp;
        pidObject["kd"] = right.kd;
        pidObject["ki"] = right.ki;
        pidArray.append(pidObject);
        QJsonDocument jsonDoc(pidArray);
        QByteArray pidMessage = jsonDoc.toJson(QJsonDocument::Compact);

        QMqttTopicName mqttTopic(topic);
        mqttClient->publish(mqttTopic, pidMessage, 0);
        qDebug() << "Published PID settings to topic: " << topic << " Message: " << pidMessage;
    }
}






