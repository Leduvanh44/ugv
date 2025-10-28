#include "plotdata.h"
#include "ui_plotdata.h"

PlotData::PlotData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotData)
{
    ui->setupUi(this);
    // Setup plot for heading tracking
    ui->Heading_customPlot->addGraph();
    ui->Heading_customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->Heading_customPlot->graph(0)->setName("Set Value");
    ui->Heading_customPlot->addGraph();
    ui->Heading_customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->Heading_customPlot->graph(1)->setName("Real Value");
    ui->Heading_customPlot->legend->setVisible(true);
    QCPLayoutGrid *subLayout = new QCPLayoutGrid;
    ui->Heading_customPlot->plotLayout()->addElement(1, 0, subLayout);
    subLayout->setMargins(QMargins(5, 0, 5, 5));
    subLayout->addElement(0, 0, ui->Heading_customPlot->legend);
    ui->Heading_customPlot->xAxis->setLabel("Time (second)");
    ui->Heading_customPlot->yAxis->setLabel("Heading (degree)");
    ui->Heading_customPlot->legend->setFillOrder(QCPLegend::foColumnsFirst);
    ui->Heading_customPlot->plotLayout()->setRowStretchFactor(1, 0.001);
    ui->Heading_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->Heading_customPlot->yAxis->setRange(-180,180);

    // Setup plot for cross-track error
    ui->CTE_customPlot->addGraph();
    ui->CTE_customPlot->graph(0)->setPen(QPen(Qt::red));
    ui->CTE_customPlot->xAxis->setLabel("Time (second)");
    ui->CTE_customPlot->yAxis->setLabel("Cross-Track Error (meter)");
    ui->CTE_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // Setup plot for along-track error
    ui->ATE_customPlot->addGraph();
    ui->ATE_customPlot->graph(0)->setPen(QPen(Qt::red));
    ui->ATE_customPlot->xAxis->setLabel("Time (second)");
    ui->ATE_customPlot->yAxis->setLabel("Along-Track Error (meter)");
    ui->ATE_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // Setup plot for vel_left
    ui->Vel_left_customPlot->addGraph();
    ui->Vel_left_customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->Vel_left_customPlot->graph(0)->setName("Set vel_left Value");
    ui->Vel_left_customPlot->addGraph();
    ui->Vel_left_customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->Vel_left_customPlot->graph(1)->setName("Real vel_left Value");

    ui->Vel_left_customPlot->legend->setVisible(true);
     QCPLayoutGrid *subLayout1 = new QCPLayoutGrid;
    ui->Vel_left_customPlot->plotLayout()->addElement(1, 0, subLayout1);
    subLayout1->setMargins(QMargins(5, 0, 5, 5));
    subLayout1->addElement(0, 0, ui->Vel_left_customPlot->legend);
    ui->Vel_left_customPlot->xAxis->setLabel("Time (second)");
    ui->Vel_left_customPlot->yAxis->setLabel("Vel Left (rad/s)");
    ui->Vel_left_customPlot->legend->setFillOrder(QCPLegend::foColumnsFirst);
    ui->Vel_left_customPlot->plotLayout()->setRowStretchFactor(1, 0.001);
    ui->Vel_left_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->Vel_left_customPlot->yAxis->setRange(-15,15);


    // Setup plot for vel_right
    ui->Vel_right_customPlot->addGraph();
    ui->Vel_right_customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->Vel_right_customPlot->graph(0)->setName("Set Value");
    ui->Vel_right_customPlot->addGraph();
    ui->Vel_right_customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->Vel_right_customPlot->graph(1)->setName("Real Value");
    ui->Vel_right_customPlot->legend->setVisible(true);
     QCPLayoutGrid *subLayout2 = new QCPLayoutGrid;
    ui->Vel_right_customPlot->plotLayout()->addElement(1, 0, subLayout2);
    subLayout2->setMargins(QMargins(5, 0, 5, 5));
    subLayout2->addElement(0, 0, ui->Vel_right_customPlot->legend);
    ui->Vel_right_customPlot->xAxis->setLabel("Time (second)");
    ui->Vel_right_customPlot->yAxis->setLabel("Vel Right (rad/s)");
    ui->Vel_right_customPlot->legend->setFillOrder(QCPLegend::foColumnsFirst);
    ui->Vel_right_customPlot->plotLayout()->setRowStretchFactor(1, 0.001);
    ui->Vel_right_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
      ui->Vel_right_customPlot->yAxis->setRange(-15,15);


    // Setup plot for linear_velocity
    ui->Velocity_customPlot->addGraph();
    ui->Velocity_customPlot->graph(0)->setPen(QPen(Qt::blue));\
    ui->Velocity_customPlot->graph(0)->setName("Set Value");
    ui->Velocity_customPlot->addGraph();
    ui->Velocity_customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->Velocity_customPlot->graph(1)->setName("Real Value");
    ui->Velocity_customPlot->legend->setVisible(true);
     QCPLayoutGrid *subLayout3 = new QCPLayoutGrid;
    ui->Velocity_customPlot->plotLayout()->addElement(1, 0, subLayout3);
    subLayout3->setMargins(QMargins(5, 0, 5, 5));
    subLayout3->addElement(0, 0, ui->Velocity_customPlot->legend);
    ui->Velocity_customPlot->xAxis->setLabel("Time (second)");
    ui->Velocity_customPlot->yAxis->setLabel("Velocity (m/s)");
    ui->Velocity_customPlot->legend->setFillOrder(QCPLegend::foColumnsFirst);
    ui->Velocity_customPlot->plotLayout()->setRowStretchFactor(1, 0.001);
    ui->Velocity_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

PlotData::~PlotData()
{
    delete ui;
}

void PlotData::on_Heading_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(0);
    ui->frame->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Heading_btn{ color: rgb(0, 0, 0);  }");
}

void PlotData::on_CTE_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(1);
    ui->frame->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#CTE_btn{ color: rgb(0, 0, 0);  }");
}

void PlotData::on_ATE_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(2);
    ui->frame->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#ATE_btn{ color: rgb(0, 0, 0);  }");
}

void PlotData::on_Velleft_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(3);
    ui->frame->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Velleft_btn{ color: rgb(0, 0, 0);  }");
}

void PlotData::on_Vel_btn_clicked()
{
    ui->Plot_page->setCurrentIndex(4);
    ui->frame->setStyleSheet("*{color: rgb(211, 215, 207); }  QPushButton#Vel_btn{ color: rgb(0, 0, 0);  }");
}

void PlotData::plotHeading(QElapsedTimer plotTimer,double currSetHeading,double currRealHeading)
{
//     qDebug() << "y=" << y_in;
  double time = plotTimer.elapsed() * 1e-3;
  ui->Heading_customPlot->graph(0)->addData(time, currSetHeading);
  ui->Heading_customPlot->graph(1)->addData(time, currRealHeading);

  ui->Heading_customPlot->xAxis->rescale();
  ui->Heading_customPlot->replot();


}

void PlotData::plotCTE(QElapsedTimer plotTimer,double currCTE)
{
  double time = plotTimer.elapsed() * 1e-3;
  ui->CTE_customPlot->graph(0)->addData(time, currCTE);
  ui->CTE_customPlot->xAxis->rescale();
  ui->CTE_customPlot->yAxis->rescale();
  ui->CTE_customPlot->replot();

}

void PlotData::plotATE(QElapsedTimer plotTimer,double currATE)
{
  double time = plotTimer.elapsed() * 1e-3;
  ui->ATE_customPlot->graph(0)->addData(time, currATE);
  ui->ATE_customPlot->xAxis->rescale();
  ui->ATE_customPlot->yAxis->rescale();
  ui->ATE_customPlot->replot();

}

void PlotData::plotvelleft(QElapsedTimer plotTimer,vector<double> currSetMotorVel,vector<double> currMotorVel)
{
    double time = plotTimer.elapsed() * 1e-3;
    ui->Vel_left_customPlot->graph(0)->addData(time, currSetMotorVel[0]);
    ui->Vel_left_customPlot->graph(1)->addData(time, currMotorVel[0]);
    ui->Vel_left_customPlot->xAxis->rescale();
    ui->Vel_left_customPlot->replot();

    ui->Vel_right_customPlot->graph(0)->addData(time, currSetMotorVel[1]);
    ui->Vel_right_customPlot->graph(1)->addData(time, currMotorVel[1]);
    ui->Vel_right_customPlot->xAxis->rescale();
    ui->Vel_right_customPlot->replot();
}


void PlotData::plotvel(QElapsedTimer plotTimer,vector<double> currSetMotorVel,vector<double> currMotorVel)
{
//    qDebug() << currSetMotorVel[0] << currSetMotorVel[1];
    double time = plotTimer.elapsed() * 1e-3;
    double SetVel = ((currSetMotorVel[0]+currSetMotorVel[1])/2)*0.09;
    double currVel = ((currMotorVel[0]+currMotorVel[1] )/2)*0.09;
    ui->Velocity_customPlot->graph(0)->addData(time, SetVel);
    ui->Velocity_customPlot->graph(1)->addData(time, currVel);

    ui->Velocity_customPlot->xAxis->rescale();
    ui->Velocity_customPlot->replot();
//    qDebug() << currVel;
}


void PlotData::setupPlot()
{

    ui->Heading_customPlot->graph(0)->data().data()->clear();
    ui->Heading_customPlot->graph(1)->data().data()->clear();
    ui->Heading_customPlot->replot();
    ui->CTE_customPlot->graph(0)->data().data()->clear();
    ui->CTE_customPlot->replot();
//    ui->ATE_customPlot->graph(0)->data().data()->clear();
//    ui->ATE_customPlot->replot();
//    ui->Vel_left_customPlot->graph(0)->data().data()->clear();
//    ui->Vel_left_customPlot->graph(1)->data().data()->clear();
//    ui->Vel_left_customPlot->replot();
//    ui->Vel_right_customPlot->graph(0)->data().data()->clear();
//    ui->Vel_right_customPlot->graph(1)->data().data()->clear();
//    ui->Vel_right_customPlot->replot();
//    ui->Velocity_customPlot->graph(0)->data().data()->clear();
//    ui->Velocity_customPlot->graph(1)->data().data()->clear();
//    ui->Velocity_customPlot->replot();

}
