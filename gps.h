#ifndef GPS_H
#define GPS_H

#include <iostream>
#include <QString>
#include <QFile>
#include <stdio.h>
#include <QTextStream>
#include <QThread>
#include <QMutex>
#include "mainwindow.h"

class MainWindow;

class GPS : public QThread
{
    Q_OBJECT

private:
    MainWindow *win;
    bool        flag, web, dateflag;
    QFile       f;
    QStringList listGPGSA, listGPRMC;
    QMutex      mutex;

    QString     formatDate(int n);
    int         process_line(QString);
    void        setUi(int);
    void        setDate();
    void        fetchData();
    void        setGPGSAUi();

public:
    GPS();
    GPS(MainWindow*);

    float   getLatitude();
    float   getLongitude();
    QString     getQStringLatitude();
    QString     getQStringLongitude();
    const QString getDate();

    void        run();
    void        stop();
    void        init();

signals:
     void   webSig();
};

#endif // GPS_H
