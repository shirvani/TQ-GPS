#include "recordposition.h"

recordPosition::recordPosition()
{
}

recordPosition::recordPosition(MainWindow *win)
    : flag(false)
{
    this->win = win;
}

const bool    &recordPosition::getFlag()
{
    return this->flag;
}

const QFile   &recordPosition::getFile()
{
    return this->f;
}

void    recordPosition::setFlag(bool b)
{
    this->flag = b;
}

void    recordPosition::writeFile()
{
    QTextStream out(&this->f);
    out << "<Placemark>\n" <<
           "<name></name>\n" <<
           "<description></description>\n" <<
           "<TimeSpamp>\n<when>" <<
           this->win->getGPS()->getDate() <<
           "</when>\n</TimeSpamp>\n" <<
           "<Point>\n<coordinates>" <<
            this->win->getGPS()->getQStringLatitude() << ',' << this->win->getGPS()->getQStringLongitude() <<
           "</coordinates>\n</Point>\n</Placemark>\n";
}

bool    recordPosition::init(QString filename)
{
    if (!this->f.isOpen())
    {
        this->f.setFileName(filename);
        if (!this->f.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;
        QTextStream out(&this->f);
        out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" <<
               "<kml xmlns=\"\">\n" <<
               "<Document>\n";
    }
    return true;
}

void    recordPosition::closeFile()
{
    if (this->f.isOpen())
    {
        QTextStream out(&this->f);
        out << "</Document>\n</kml>\n";
        this->f.close();
    }
}
