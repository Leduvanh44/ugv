#include "mainwindow.h"
#include "ui_UGV_UI.h"

void MainWindow::on_Signin_btn_signin_clicked()
{
    ui->Page->setCurrentIndex(0);
    ui->Signin_btn->setStyleSheet("QPushButton#Signin_btn_signin{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_Signin_btn_signup_clicked()
{
    ui->Page->setCurrentIndex(1);
    ui->Signin_btn->setStyleSheet("QPushButton#Signin_btn_signup{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_Signin_btn_settings_clicked()
{
    ui->Signin_btn->setStyleSheet("QPushButton#Signin_btn_settings{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_Account__btnlogout_clicked()
{
    ui->Dashboard->setCurrentIndex(0);
    ui->Page->setCurrentIndex(0);
}

void MainWindow::on_Main_btn_robots_clicked()
{
    ui->Page->setCurrentIndex(3);
    ui->Main_btn->setStyleSheet("QPushButton#Main_btn_robots{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_Main_btn_orders_clicked()
{
    ui->Page->setCurrentIndex(2);
    ui->Main_btn->setStyleSheet("QPushButton#Main_btn_orders{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_Main_btn_tracking_clicked()
{
    ui->Page->setCurrentIndex(4);
    ui->stackedWidget->setCurrentIndex(0);
    ui->Main_btn->setStyleSheet("QPushButton#Main_btn_tracking{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");

}

void MainWindow::on_Main_btn_products_clicked()
{
    ui->Page->setCurrentIndex(5);
    ui->stackedWidget->setCurrentIndex(0);
    ui->Main_btn->setStyleSheet("QPushButton#Main_btn_products{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::on_Clear_btn_clicked()
{
    ui->Allorders_table->setRowCount(0);
    ui->UGV1_table->setRowCount(0);
}

void MainWindow::on_Main_btn_createorders_clicked()
{
    ui->Page->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(1);
    ui->Main_btn->setStyleSheet("QPushButton#Main_btn_createorders{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
}

void MainWindow::CheckButtonClicked(int RowNum)
{
    QComboBox *myCB = qobject_cast<QComboBox*>(ui->Allorders_table->cellWidget(RowNum,7));
    if(myCB->currentText() != "")
    {
    QSqlQuery qry;
     qry.prepare("UPDATE delivery_robot.order SET order_robot = :robot, order_status = '1', order_tracking = '0' WHERE order_id = :orderid");
     qry.bindValue(":robot",myCB->currentText());
     qry.bindValue(":orderid",ui->Allorders_table->item(RowNum,0)->text());
     if (qry.exec()) ui->Allorders_table->hideRow(RowNum);
    }
}

void MainWindow::UncheckButtonClicked(int RowNum)
{
    QSqlQuery qry;
    qry.prepare("UPDATE delivery_robot.order SET order_status = '2' WHERE order_id = :orderid");
    qry.bindValue(":orderid",ui->Allorders_table->item(RowNum,0)->text());
    if (qry.exec()) ui->Allorders_table->hideRow(RowNum);

}

void MainWindow::on_UGV1_btn_clicked()
{
    ui->Menu_frame->setStyleSheet("QPushButton#UGV1_btn{ color: rgb(46, 52, 54);} QFrame#underline_2{ background-color: rgb(0, 41, 77); border-radius:2px; }");
    ui->Orders_page->setCurrentIndex(1);
}

void MainWindow::on_Allorders_btn_clicked()
{
    ui->Menu_frame->setStyleSheet("QPushButton#Allorders_btn{  color: rgb(46, 52, 54);}QFrame#underline_1{ background-color: rgb(0, 41, 77); border-radius:2px; }");
    ui->Orders_page->setCurrentIndex(0);

}
