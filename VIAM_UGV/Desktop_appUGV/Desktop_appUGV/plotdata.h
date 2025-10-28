#ifndef PLOTDATA_H
#define PLOTDATA_H

#include <QMainWindow>
#include <QElapsedTimer>






using namespace std;


namespace Ui {
class PlotData;
}
class MainWindow;
class PlotData : public QMainWindow
{
    Q_OBJECT

public:


    void plotHeading(QElapsedTimer plotTimer,double currSetHeading,double currRealHeading);
    void plotCTE(QElapsedTimer plotTimer,double currCTE);
    void plotATE(QElapsedTimer plotTimer,double currATE);
    void plotvelleft(QElapsedTimer plotTimer,vector<double> currSetMotorVel,vector<double> currMotorVel);
    void plotvel(QElapsedTimer plotTimer,vector<double> currSetMotorVel,vector<double> currMotorVel);
    void setupPlot();
    explicit PlotData(QWidget *parent = nullptr);
    ~PlotData();

private slots:
    void on_Heading_btn_clicked();

    void on_CTE_btn_clicked();

    void on_ATE_btn_clicked();

    void on_Velleft_btn_clicked();

    void on_Vel_btn_clicked();

private:
    Ui::PlotData *ui;

};

#endif // PLOTDATA_H
