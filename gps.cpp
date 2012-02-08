#include "gps.h"

GPS::GPS()
{
}

GPS::GPS(MainWindow *win)
    : flag(false), web(true), dateflag(true)
{
    this->win = win;
}

float      GPS::getLatitude()
{
    if (this->listGPRMC.size() > 0)
        return this->listGPRMC.at(3).toFloat();
    return 0;
}

float       GPS::getLongitude()
{
    if (this->listGPRMC.size() > 0)
        return this->listGPRMC.at(5).toFloat();
    return 0;
}

QString     GPS::getQStringLatitude()
{
    if (this->listGPRMC.size() > 0)
        return this->listGPRMC.at(3);
    return NULL;
}

QString     GPS::getQStringLongitude()
{
    if (this->listGPRMC.size() > 0)
        return this->listGPRMC.at(5);
    return NULL;
}

QString         GPS::formatDate(int n)
{
    QString s = NULL;
    if(n < 10)
        s = '0' + QString::number(n);
    else
        s = QString::number(n);
    return s;
}

const QString   GPS::getDate()
{
    if (this->listGPRMC.size() > 0)
    {
        int date = this->listGPRMC.at(9).toInt();
        int year = date % 100 + 2000;
        int month = date / 100 % 100;
        int day = date / 10000 % 100;
        const QString s = QString::number(year) + '-' + this->formatDate(month) + '-' + this->formatDate(day);
        return s;
    }
    return NULL;
}

void    GPS::fetchData()
{
    char s[4096];
    while (42) {
        this->f.readLine(s, 4096);
        QString str = s;
        if (str == NULL || str == "\n")
            continue;
        int flag = process_line(str.trimmed());
        if (flag != 0)
            setUi(flag);
        msleep(100);
    }
}

int    GPS::process_line(QString str)
{
    if (QString::compare("$GPRMC", str.left(6), Qt::CaseInsensitive) == 0)
    {
        std::cout << str.toStdString() << std::endl;
        this->listGPRMC = str.split(",");
        if (this->win->getRec()->getFlag())
            this->win->getRec()->writeFile();
        return 1;    
    }
    if (QString::compare("$GPGSA", str.left(6), Qt::CaseInsensitive) == 0)
    {
        std::cout << str.toStdString() << std::endl;
        this->listGPGSA = str.split(",");
        return 2;
    }
    return 0;
}

void    GPS::setUi(int flag)
{
    if (flag == 1)
    {
        this->win->setLabelLongitude(this->listGPRMC.at(3));
        this->win->setLabelLatitude(this->listGPRMC.at(5));
        this->win->setLabelLatitudeDir(this->listGPRMC.at(6));
        this->win->setLabelLongitudeDir(this->listGPRMC.at(4));
        this->win->getHttp()->sendRequest(this->listGPRMC.at(3), this->listGPRMC.at(5), this->listGPRMC.at(4), this->listGPRMC.at(6));
        //if (this->web == true)
        //{
        //    emit webSig();
        //    this->web = false;
        //}
        if (this->dateflag == true)
            this->setDate();
    }
    if (flag == 2)
        this->setGPGSAUi();
}

void    GPS::setGPGSAUi()
{
    int nbSat = 0;
    for (int i = 3;i != 8;i++)
    {
        if (this->listGPGSA.at(i) != NULL)
            nbSat++;
    }
    if (nbSat == 0)
        this->win->setLabelGPGSA("No GPGSA data");
    else if (nbSat == 1)
        this->win->setLabelGPGSA(QString::number(nbSat) + " GPGSA data source");
    else
        this->win->setLabelGPGSA(QString::number(nbSat) + " GPGSA data sources");
    this->win->setLabelPHVDOP(this->listGPGSA.at(15), this->listGPGSA.at(16), this->listGPGSA.at(17));
}

void    GPS::setDate()
{
    int date = this->listGPRMC.at(9).toInt();
    if (date > 0)
    {
        int year = date % 100 + 2000;
        int month = date / 100 % 100;
        int day = date / 10000 % 100;
        QString s = "date -s " + QString::number(year) + QString::number(month) + QString::number(day) + "0000";
        system(s.toStdString().c_str());
        this->dateflag = false;
    }
}

void    GPS::run()
{
    mutex.lock();
    this->fetchData();
    mutex.unlock();
}

void    GPS::stop()
{
    mutex.lock();
    this->f.close();
    mutex.unlock();
}

void    GPS::init()
{
    this->f.setFileName("/dev/tq2440_serial1");
    if(!this->f.open(QIODevice::ReadOnly | QIODevice::Text))
        return;//##ARM##//{}
}
