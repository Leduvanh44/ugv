#include "mainwindow.h"
#include "ui_UGV_UI.h"
#include "QDebug"


void MainWindow::resizeEvent(QResizeEvent *event) {
    ui->Allorders_table->setColumnWidth(0, 2*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(1, 4*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(2, 3*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(3, 5*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(4, 3*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(5, 3*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(6, 2*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(7, 3*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(8, 1*(ui->Page->width())/27);
    ui->Allorders_table->setColumnWidth(9, 1*(ui->Page->width())/27);

    ui->UGV1_table->setColumnWidth(0, 2*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(1, 4*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(2, 3*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(3, 4*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(4, 3*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(5, 3*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(6, 2*(ui->Page->width())/24);
    ui->UGV1_table->setColumnWidth(7, 3*(ui->Page->width())/24);
    mapView->setHeight(ui->tracking_outdoor->height());
    mapView->setWidth(ui->tracking_outdoor->width());
}

void MainWindow::updateOrder(){
    QSqlQuery qry;
    QSqlQuery qry1;
    int rowIndex = ui->Allorders_table->rowCount();
    if (rowIndex == 0){
        qry.prepare("SELECT order_id FROM delivery_robot.order WHERE order_robot is NULL AND order_status ='0' ORDER BY order_id   ");

    }
    else{
        qry.prepare("SELECT order_id FROM delivery_robot.order WHERE order_date > :date AND order_robot IS NULL, order_status ='0'");
        qry.bindValue(":date",QDateTime::fromString(ui->Allorders_table->item(rowIndex-1,1)->text(),"dd-MM-yyyy hh:mm:ss").toString("yyyy:MM:dd hh:mm:ss"));
    }

    if(!qry.exec())
        return;
    else{

        Orderid_list.clear();
        while (qry.next()) {
            Orderid_list.append(qry.value(0).toString());
            qry1.prepare("SELECT\
                         order_date, customer_fullname, GROUP_CONCAT(product_name,' x ',quantity) AS itemlist, order_total_price, order_address, order_QRcode\
                     FROM	\
                         delivery_robot.orderdetails\
                         JOIN	delivery_robot.`order` ON order.order_id = orderdetails.order_id\
                         JOIN	delivery_robot.customer ON customer.customer_id = order.customer_id\
                         JOIN	delivery_robot.product ON product.product_id = orderdetails.product_id\
                     WHERE orderdetails.order_id = :order_id");
             qry1.bindValue(":order_id",qry.value(0));
             qry1.exec();
             while (qry1.next()){
                myorder Myorder;
                Myorder.order_id = qry.value(0).toString();
                Myorder.order_date = qry1.value(0).toDateTime().toString("dd-MM-yyyy hh:mm:ss");
                Myorder.customer_name = qry1.value(1).toString();
                Myorder.order_products = qry1.value(2).toString();
                Myorder.order_price = qry1.value(3).toString();
                Myorder.order_address = qry1.value(4).toString();
                Myorder.order_QRcode = qry1.value(5).toString();
                emit OrderReceived(Myorder);
             }
       }
    }
}

void MainWindow::updateUGVorder()
{
    QSqlQuery qry;
    QSqlQuery qry1;
    int rowIndex = ui->UGV1_table->rowCount();
    if (rowIndex == 0){
        qry.prepare("SELECT order_id FROM delivery_robot.order WHERE order_robot = 'VIAM_UGV500' AND order_status ='1' ORDER BY order_id   ");
    }
    else{
        qry.prepare("SELECT order_id FROM delivery_robot.order WHERE order_date > :date AND order_robot = 'VIAM_UGV500' AND order_status ='1'");
        qry.bindValue(":date",QDateTime::fromString(ui->UGV1_table->item(rowIndex-1,1)->text(),"dd-MM-yyyy hh:mm:ss").toString("yyyy:MM:dd hh:mm:ss"));
    }

    if(!qry.exec())
        return;
    else{
        Orderid_list.clear();
        while (qry.next()) {
            Orderid_list.append(qry.value(0).toString());
            qry1.prepare("SELECT\
                         order_date, customer_fullname, GROUP_CONCAT(product_name,' x ',quantity) AS itemlist, order_total_price, order_address, order_QRcode, order_tracking\
                     FROM	\
                         delivery_robot.orderdetails\
                         JOIN	delivery_robot.`order` ON order.order_id = orderdetails.order_id\
                         JOIN	delivery_robot.customer ON customer.customer_id = order.customer_id\
                         JOIN	delivery_robot.product ON product.product_id = orderdetails.product_id\
                     WHERE orderdetails.order_id = :order_id");
             qry1.bindValue(":order_id",qry.value(0));
             qry1.exec();
             while (qry1.next()){
                myorder UGVorder;
                UGVorder.order_id = qry.value(0).toString();
                UGVorder.order_date = qry1.value(0).toDateTime().toString("dd-MM-yyyy hh:mm:ss");
                UGVorder.customer_name = qry1.value(1).toString();
                UGVorder.order_products = qry1.value(2).toString();
                UGVorder.order_price = qry1.value(3).toString();
                UGVorder.order_address = qry1.value(4).toString();
                UGVorder.order_QRcode = qry1.value(5).toString();
                UGVorder.order_status = qry1.value(6).toString();
                emit UGVorderReceived(UGVorder);
             }
       }
    }
}

void MainWindow::AddMyorder(myorder Myorder)
{
   int rowIndex = ui->Allorders_table->rowCount();
   ui->Allorders_table->insertRow(rowIndex);
   ui->Allorders_table->setRowHeight(rowIndex,35);
   //         item->setCheckState(Qt::Unchecked);

   QPushButton* pButton = new QPushButton();
   pButton->setIcon(QIcon(":/icon/Check_icon.png"));
   pButton->setIconSize(QSize(30,30));
   ui->Allorders_table->setCellWidget(rowIndex, 8,(QWidget*)pButton);
   ButtonSignalMapper.setMapping(pButton, rowIndex);
   connect(pButton, SIGNAL(clicked()), &ButtonSignalMapper, SLOT(map()));

   QPushButton* item = new QPushButton();
   item->setIcon(QIcon(":/icon/Uncheck_icon.png"));
   item->setIconSize(QSize(30,30));
   ui->Allorders_table->setCellWidget(rowIndex, 9,(QWidget*)item);
   ButtonSignalMapper1.setMapping(item, rowIndex);
   connect(item, SIGNAL(clicked()), &ButtonSignalMapper1, SLOT(map()));

   QComboBox* myComboBox = new QComboBox();
   myComboBox->addItem("");
   myComboBox->addItem("VIAM_UGV500");
   myComboBox->addItem("VIAM_UGV1000");
   ui->Allorders_table->setCellWidget(rowIndex,7,myComboBox);
   QString value;
   for(int j = 0; j != 7; j++){
       switch (j) {
       case 0:
       {
          value = Myorder.order_id;
           break;
       }
       case 1:
       {
           value = Myorder.order_date;
           break;
       }
       case 2:
       {
           value = Myorder.customer_name;
           break;
       }
       case 3:
       {
          value = Myorder.order_products;
           break;
       }
       case 4:
       {
          value = QString("%L1").arg(Myorder.order_price.toDouble()) + " VNĐ";
           break;
       }
       case 5:
       {
           value = Myorder.order_address;
           break;
       }
       case 6:
       {
           value = Myorder.order_QRcode;
           break;
       }
       default:
           break;
       }

      QTableWidgetItem *orderitem = new QTableWidgetItem(value);
      ui->Allorders_table->setItem(rowIndex, j , orderitem);
      orderitem->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::AddUGVorder(myorder UGVorder)
{
   int rowIndex = ui->UGV1_table->rowCount();
   ui->UGV1_table->insertRow(rowIndex);
   ui->UGV1_table->setRowHeight(rowIndex,35);
   QString value;
   for(int j = 0; j != 8; j++){
       switch (j) {
       case 0:
       {
          value = UGVorder.order_id;
           break;
       }
       case 1:
       {
           value = UGVorder.order_date;
           break;
       }
       case 2:
       {
           value = UGVorder.customer_name;
           break;
       }
       case 3:
       {
          value = UGVorder.order_products;
           break;
       }
       case 4:
       {
          value = QString("%L1").arg(UGVorder.order_price.toDouble()) + " VNĐ";
           break;
       }
       case 5:
       {
           value = UGVorder.order_address;
           break;
       }
       case 6:
       {
           value = UGVorder.order_QRcode;
           break;
       }
       case 7:
       {
           if (UGVorder.order_status == "0") value = "PACKING";
           else if(UGVorder.order_status == "1") value = "SHIPPING";
           else if(UGVorder.order_status == "2") value = "DELIVERED";
           break;
       }
       default:
           break;
       }

      QTableWidgetItem *orderitem = new QTableWidgetItem(value);
      ui->UGV1_table->setItem(rowIndex, j , orderitem);
      orderitem->setTextAlignment(Qt::AlignCenter);
    }
}
