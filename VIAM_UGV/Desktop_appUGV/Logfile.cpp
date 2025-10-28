#include "mainwindow.h"


void MainWindow::start_loggingData()
{
// Empty current logging containers
    timestampLog.clear();
    latLog.clear();
    lonLog.clear();
    setHeadingLog.clear();
    realHeadingLog.clear();
    CTELog.clear();
    currMotorVelLog.clear();

// Start periodic logging of data
    dataLogger->start(30);
    logTimer.restart();
}
void MainWindow::stop_loggingData()
{
// Stop logging
    dataLogger->stop();

// Name log file according to current date and time from local time
    auto now = QDateTime::currentDateTime().toString().toStdString();
    string path = "/home/minhduy/";
    string log_name = path + "log" + "_" + now + ".csv";

// Save to current log file
    ofstream log_file(log_name, ios::out);
    auto N = timestampLog.size();
    log_file << setprecision(9) << fixed;
    log_file << "Timestamp, Latitude, Longitude, Set Heading, Real Heading, CTE, Set Left Vel, Set Right Vel, Curr Left Vel, Curr Right Vel" << endl;
    for (size_t i = 0; i < N; i++)
    {
      log_file << timestampLog[i] << ", ";
      log_file << latLog[i] << ", ";
      log_file << lonLog[i] << ", ";
      //log_file << setHeadingLog[i] << ", ";
      log_file << realHeadingLog[i] << ", ";
      log_file << CTELog[i] << ", ";
      log_file << setMotorVelLog[i][0] << ", ";
      log_file << setMotorVelLog[i][1] << ", ";
      log_file << currMotorVelLog[i][0] << ", ";
      log_file << currMotorVelLog[i][1] <<  endl;
    }
}





void MainWindow::logData()
{
  timestampLog.push_back(plotTimer.elapsed() * 1e-3);
  latLog.push_back(currLat[0]);
  lonLog.push_back(currLon[0]);
  //setHeadingLog.push_back(currSetHeading[0]);
  realHeadingLog.push_back(currRealHeading[0]);
  CTELog.push_back(currCTE);
  setMotorVelLog.push_back(currSetMotorVel);
  currMotorVelLog.push_back(currMotorVel);

}
