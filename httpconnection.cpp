#include "httpconnection.h"

httpConnection::httpConnection()
{
}

httpConnection::httpConnection(MainWindow *win)
{
    this->win = win;
    this->http = new QHttp(this);
    this->http->setHost("192.168.1.5");
    srand(time(NULL));
    this->sessionId = rand() % 100000;
}

void    httpConnection::sendRequest(const QString &lat, const QString &lon, const QString &latP, const QString &lonP)
{
    QString tmp;

    tmp = "/setposition.php?id=";
    tmp.append(QString::number(this->sessionId));
    tmp.append("&lon=");
    tmp.append(lon);
    tmp.append("&lat=");
    tmp.append(lat);
    tmp.append("&lonP=");
    tmp.append(lonP);
    tmp.append("&latP=");
    tmp.append(latP);
    std::cout << tmp.toStdString() << std::endl;
    this->http->get(tmp);
}

void    httpConnection::clearData()
{
    QString tmp;

    tmp = "clear.php?id=";
    tmp.append(QString::number(this->sessionId));
    this->http->get(tmp);
    this->http->closeConnection();
}
