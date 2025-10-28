#include "mainwindow.h"
#include "ui_UGV_UI.h"

void MainWindow::on_Signin_btn_login_clicked()
{
//    user = ui->Signin_login->text();
//    password = ui->Signin_password->text();
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("users.db");
//    if (!db.open()) {
//        qDebug() << "Failed to open database!";
//        return;
//    }
//    QSqlQuery query;
//    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
//    query.bindValue(":username", user);
//    query.bindValue(":password", password);
//    if (query.exec()) {
//        if (query.next()) {
            qDebug() << "Login successful!";
            ui->Dashboard->setCurrentIndex(1);
            ui->Page->setCurrentIndex(2);
            ui->Orders_page->setCurrentIndex(0);
//            ui->Account_username->setText(query.value(2).toString());
//        } else {
//            QMessageBox::warning(this,"SIGN IN","Username or Password is not correct");
//            qDebug() << "Login failed!";
//        }
//    } else {
//        QMessageBox::warning(this,"SIGN IN","Query failed!");
//        qDebug() << "Query failed!";
//    }

//    db.close();

//            foreach(QLineEdit* le, ui->LineEdit_sigin->findChildren<QLineEdit*>()) {
//            le->clear();
//            }
}

void MainWindow::on_Signup_btn_signup_clicked()
{
    QString username, password, name, phone;

    username = ui->Signup_username->text();

    password = ui->Signup_password->text();
    name = ui->Signup_name->text();
    phone = ui->Signup_phone->text();
    if(username != "" && password !=""){
    QSqlQuery qry;
    qry.prepare("INSERT INTO staff (username, password, name, phone)"
                 "VALUES (:username, :password, :name, :phone)");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    qry.bindValue(":name", name);
    qry.bindValue(":phone",phone);
    if(qry.exec()){
        ui->Page->setCurrentIndex(0);
        ui->Signin_btn->setStyleSheet("QPushButton#Signin_btn_signin{ background-color: rgb(216, 229, 254); color: rgb(0, 41, 77); }");
            }
            else
            {
                QMessageBox::information(this,"SIGN UP","Sign up failed!");
            }
    }
    else
    {
        QMessageBox::information(this,"SIGN UP","Sign up failed");
    }
    foreach(QLineEdit* le, ui->LineEdit_signup->findChildren<QLineEdit*>()) {
    le->clear();
    }
}
