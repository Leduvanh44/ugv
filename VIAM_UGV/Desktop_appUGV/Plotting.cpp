#include "mainwindow.h"
#include "ui_UGV_UI.h"


void MainWindow::setupPlot()
{


//    plotdata->setupPlot();
//    plotTimer.restart();

    // Restart timer for plotting
    plotTimer.restart();
    headingPlotter->start(30);
    CTEPlotter->start(30);

    ATEPlotter->start(50);
    VelleftPlotter->start(50);
    VelPlotter->start(50);
}

void MainWindow::on_Heading_btn_clicked()
{

    ui->Plot_page->setCurrentIndex(0);
    ui->frame_2->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Heading_btn{ color: rgb(0, 0, 0);  }");
}

void MainWindow::on_CTE_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(1);
    ui->frame_2->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#CTE_btn{ color: rgb(0, 0, 0);  }");
}

void MainWindow::on_ATE_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(2);
    ui->frame_2->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#ATE_btn{ color: rgb(0, 0, 0);  }");
}

void MainWindow::on_Velleft_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(3);
    ui->frame_2->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Velleft_btn{ color: rgb(0, 0, 0);  }");
}

void MainWindow::on_Vel_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(5);
    ui->frame_2->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Vel_btn{ color: rgb(0, 0, 0);  }");
}
void MainWindow::on_pid_stm_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(4);
    ui->frame_2->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Vel_btn{ color: rgb(0, 0, 0);  }");
}

void MainWindow::on_set_pid_btn_clicked()
{
    left.kd = ui->kd_left->text().toDouble();;
    left.ki = ui->ki_left->text().toDouble();;
    left.kp = ui->kp_left->text().toDouble();;
    right.kd = ui->kd_right->text().toDouble();;
    right.kp = ui->kp_right->text().toDouble();;
    right.ki = ui->ki_right->text().toDouble();;
}



void MainWindow::plotHeading()
{
    if (ui->Heading_customPlot->graphCount() == 0) {
            ui->Heading_customPlot->addGraph();
            ui->Heading_customPlot->addGraph();
    }
//    vector<double> heading = {0,0};;
//    heading[0] = currRealHeading[0];
//    heading[1] = currSetheading;
//    qDebug << heading[0] << heading[1];
    static QTime time_heading(QTime::currentTime());
    double key = time_heading.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey_heading = 0;
    if (key-lastPointKey_heading > 0.002)
    {
      // add data to lines:
        ui->Heading_customPlot->graph(0)->addData(key, currSetheading);
        ui->Heading_customPlot->graph(1)->addData(key, currHeading);

        QPen pen(Qt::red);
        pen.setWidth(2);
        ui->Heading_customPlot->graph(0)->setPen(pen); // Màu đỏ cho currSetlheading
        QPen pen1(Qt::blue);
        pen1.setWidth(2);
        ui->Heading_customPlot->graph(1)->setPen(pen1); // Màu xanh cho currRealHeading


        ui->Heading_customPlot->xAxis->setLabel("Time");
        ui->Heading_customPlot->yAxis->setLabel("Heading");
        ui->Heading_customPlot->yAxis->setRange(-180, 180);
      //ui->customPlot->graph(0)->rescaleValueAxis();
      //ui->customPlot->graph(1)->rescaleValueAxis(true);
      lastPointKey_heading = key;
    }

    ui->Heading_customPlot->xAxis->setRange(key, key, Qt::AlignRight);
    ui->Heading_customPlot->replot();

//    static double lastFpsKey_heading;
//    static int frameCount_heading;
//    ++frameCount_heading;
//    if (key-lastFpsKey_heading > 2) {
//      lastFpsKey_heading = key;
//      frameCount_heading = 0;
//    }

    ui->Heading_customPlot->replot();
//    qDebug() << "x=" << x_in;
//     qDebug() << "y=" << y_in;
//  double time = plotTimer.elapsed() * 1e-3;
//  ui->Heading_customPlot->graph(0)->addData(time, 0.78);
//  ui->Heading_customPlot->graph(1)->addData(time, 0.67);
//  ui->Heading_customPlot->xAxis->rescale();
//  ui->Heading_customPlot->replot();
//    if(currsetheading.isEmpty())
//    {
//    }
//    else{
//    plotdata->plotHeading(plotTimer,0.4,0.5);
//    plotdata->plotHeading(plotTimer,currsetheading.first(),currrealheading.first());
//    currsetheading.removeFirst();
//    currrealheading.removeFirst();
//    qDebug() << "lmao: " << coords_alo.back() << coords_alo.size();
//    emit positionReceived(QVariant::fromValue(coords_alo.back()));
//    qDebug() << "lmao: " << QVariant::fromValue(coords.first());
//    coords_alo.removeFirst();
}

void MainWindow::plotCTE()
{
    if (ui->CTE_customPlot->graphCount() == 0) {
            ui->CTE_customPlot->addGraph();
    }
    static QTime time_heading(QTime::currentTime());
    double key = time_heading.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey_heading = 0;
    if (key-lastPointKey_heading > 0.002)
    {
      // add data to lines:
        ui->CTE_customPlot->graph(0)->addData(key, currCTE);

        ui->CTE_customPlot->xAxis->setLabel("Time");
        ui->CTE_customPlot->yAxis->setLabel("CTE");
        ui->CTE_customPlot->yAxis->setRange(-50, 50);
      //ui->customPlot->graph(0)->rescaleValueAxis();
      //ui->customPlot->graph(1)->rescaleValueAxis(true);
      lastPointKey_heading = key;
    }

    ui->CTE_customPlot->xAxis->setRange(key, key, Qt::AlignRight);
    ui->CTE_customPlot->replot();

    static double lastFpsKey_CTE;
    static int frameCount_CTE;
    ++frameCount_CTE;
//    if (key-lastFpsKey_CTE > 2) {
//      lastFpsKey_CTE = key;
//      frameCount_CTE = 0;
//    }

}
//}

void MainWindow::plotATE()
{
//  double time = plotTimer.elapsed() * 1e-3;
//  ui->ATE_customPlot->graph(0)->addData(time, currATE);
//  ui->ATE_customPlot->xAxis->rescale();
//  ui->ATE_customPlot->yAxis->rescale();
//  ui->ATE_customPlot->replot();
    //plotdata->plotATE(plotTimer,currATE);
    if (ui->ATE_customPlot->graphCount() == 0) {
            ui->ATE_customPlot->addGraph();
    }
    static QTime time_ate(QTime::currentTime());
    double key = time_ate.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey_heading = 0;
    if (key-lastPointKey_heading > 0.002)
    {
      // add data to lines:
        ui->ATE_customPlot->graph(0)->addData(key, currATE);

        ui->ATE_customPlot->xAxis->setLabel("Time");
        ui->ATE_customPlot->yAxis->setLabel("ATE");
        ui->ATE_customPlot->yAxis->setRange(-20, 20);
      //ui->customPlot->graph(0)->rescaleValueAxis();
      //ui->customPlot->graph(1)->rescaleValueAxis(true);
      lastPointKey_heading = key;
    }

    ui->ATE_customPlot->xAxis->setRange(key, key, Qt::AlignRight);
    ui->ATE_customPlot->replot();

//    static double lastFpsKey_ATE;
//    static int frameCount_ATE;
//    ++frameCount_ATE;
//    if (key-lastFpsKey_ATE > 2) {
//      lastFpsKey_ATE = key;
//      frameCount_ATE = 0;
//    }

//    ui->ATE_customPlot->replot();

}

void MainWindow::plotvelleft()
{
    if (ui->Vel_left_customPlot->graphCount() == 0) {
            ui->Vel_left_customPlot->addGraph();
            ui->Vel_left_customPlot->addGraph();
    }
    if (ui->Vel_right_customPlot->graphCount() == 0) {
        ui->Vel_right_customPlot->addGraph();
        ui->Vel_right_customPlot->addGraph();
    }
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.003)
    {

        ui->Vel_left_customPlot->graph(0)->addData(key, currSetMotorVel[0]);
        ui->Vel_left_customPlot->graph(1)->addData(key, currMotorVel[0]);

        QPen pen(Qt::red);
        pen.setWidth(2);
        ui->Vel_left_customPlot->graph(0)->setPen(pen); // Màu đỏ cho currSetlheading
        QPen pen1(Qt::blue);
        pen1.setWidth(2);
        ui->Vel_left_customPlot->graph(1)->setPen(pen1); // Màu xanh cho currRealHeading


        ui->Vel_left_customPlot->xAxis->setLabel("Time");
        ui->Vel_left_customPlot->yAxis->setLabel("Vel_left");
        ui->Vel_left_customPlot->yAxis->setRange(-1, 70);

        ui->Vel_right_customPlot->graph(0)->addData(key, currSetMotorVel[1]);
        ui->Vel_right_customPlot->graph(1)->addData(key, currMotorVel[1]);

        ui->Vel_right_customPlot->graph(0)->setPen(pen);
        ui->Vel_right_customPlot->graph(1)->setPen(pen1);

        ui->Vel_right_customPlot->xAxis->setLabel("Time");
        ui->Vel_right_customPlot->yAxis->setLabel("Vel_right");
        ui->Vel_right_customPlot->yAxis->setRange(-1, 70);
      //ui->customPlot->graph(0)->rescaleValueAxis();
      //ui->customPlot->graph(1)->rescaleValueAxis(true";
      lastPointKey = key;
    }

    ui->Vel_left_customPlot->xAxis->setRange(key, key, Qt::AlignRight);
    ui->Vel_left_customPlot->replot();
    ui->Vel_right_customPlot->xAxis->setRange(key, key, Qt::AlignRight);
    ui->Vel_right_customPlot->replot();
//    static double lastFpsKey;
//    static int frameCount;
//    ++frameCount;
//    if (key-lastFpsKey > 2) {
//      lastFpsKey = key;
//      frameCount = 0;
//    }

//    ui->Vel_left_customPlot->replot();
//    ui->Vel_right_customPlot->replot();
//    double time = plotTimer.elapsed() * 1e-3;
//    ui->Vel_left_customPlot->graph(0)->addData(time, currSetMotorVel[0]);
//    ui->Vel_left_customPlot->graph(1)->addData(time, currMotorVel[0]);
//    ui->Vel_left_customPlot->xAxis->rescale();
//    ui->Vel_left_customPlot->replot();

//    ui->Vel_right_customPlot->graph(0)->addData(time, currSetMotorVel[1]);
//    ui->Vel_right_customPlot->graph(1)->addData(time, currMotorVel[1]);
//    ui->Vel_right_customPlot->xAxis->rescale();
//    ui->Vel_right_customPlot->replot();
//    plotvelleft();
}


void MainWindow::plotvel()
{
//    double time = plotTimer.elapsed() * 1e-3;
//    double SetVel = ((currSetMotorVel[0]+currSetMotorVel[1])/2)*0.09;
//    double currVel = ((currMotorVel[0]+currMotorVel[1] )/2)*0.09;
//    ui->Velocity_customPlot->graph(0)->addData(time, SetVel);
//    ui->Velocity_customPlot->graph(1)->addData(time, currVel);

//    ui->Velocity_customPlot->xAxis->rescale();
//    ui->Velocity_customPlot->replot();
//    qDebug() << currVel;
    //plotdata->plotvel(plotTimer,currSetMotorVel,currMotorVel);
}


