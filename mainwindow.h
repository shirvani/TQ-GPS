#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QThread>
#include <QFileDialog>
#include <QCloseEvent>
#include "gps.h"
#include "recordposition.h"
#include "httpconnection.h"

class GPS;
class recordPosition;
class httpConnection;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    recordPosition  *getRec();
    GPS             *getGPS();
    httpConnection  *getHttp();
    Ui::MainWindow  *getUi();

    void    setLabelLongitude(const QString &);
    void    setLabelLatitude(const QString &);
    void    setLabelLongitudeDir(const QString &);
    void    setLabelLatitudeDir(const QString &);
    void    setLabelStatement(bool);
    void    setLabelGPGSA(const QString &);
    void    setLabelPHVDOP(const QString &, const QString &, const QString &);

private:
    Ui::MainWindow *ui;
    GPS            *gps;
    recordPosition *rec;
    httpConnection *http;

protected:
    void    closeEvent(QCloseEvent *event);

private slots:
    void    stopData();
    void    startData();
    void    startRecord();
    void    stopRecord();
    void    cleanData();
    void    setWeb();
};

#endif // MAINWINDOW_H
