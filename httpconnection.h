#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <QtNetwork/QHttp>
#include <QUrl>
#include <QHttpRequestHeader>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <iostream>
#include <time.h>
#include "mainwindow.h"

class MainWindow;

class httpConnection : public QObject
{
private:
    QHttp      *http;
    MainWindow *win;
    int       sessionId;

public:
    httpConnection();
    httpConnection(MainWindow*);

    void sendRequest(const QString&, const QString&, const QString&, const QString&);
    void clearData();
};

#endif // HTTPCONNECTION_H
