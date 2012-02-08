#ifndef RECORDPOSITION_H
#define RECORDPOSITION_H

#include <QTextStream>
#include <QFile>
#include "mainwindow.h"

class MainWindow;

class recordPosition
{
private:
    MainWindow *win;
    bool        flag;
    QFile       f;

public:
    recordPosition();
    recordPosition(MainWindow*);

    const bool    &getFlag();
    const QFile   &getFile();

    void    setFlag(bool b);
    void    writeFile();
    void    closeFile();
    bool    init(QString);
};

#endif // RECORDPOSITION_H
