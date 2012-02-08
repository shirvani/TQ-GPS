#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    this->gps = new GPS(this);
    this->gps->init();
    this->rec = new recordPosition(this);
    this->http = new httpConnection(this);
    ui->buttonStop->setEnabled(false);
    ui->buttonStopRecord->setEnabled(false);
    QObject::connect(ui->buttonLauncher, SIGNAL(clicked()), this, SLOT(startData()));
    QObject::connect(ui->buttonStop, SIGNAL(clicked()), this, SLOT(stopData()));
    QObject::connect(ui->buttonRecord, SIGNAL(clicked()), SLOT(startRecord()));
    QObject::connect(ui->buttonStopRecord, SIGNAL(clicked()), SLOT(stopRecord()));
    QObject::connect(this->gps, SIGNAL(webSig()), this, SLOT(setWeb()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow  *MainWindow::getUi()
{
    return this->ui;
}

recordPosition  *MainWindow::getRec()
{
    return this->rec;
}

GPS  *MainWindow::getGPS()
{
    return this->gps;
}

httpConnection  *MainWindow::getHttp()
{
    return this->http;
}

void    MainWindow::setLabelLongitude(const QString &s)
{
    this->ui->labelLongitude->setText(s);
}

void    MainWindow::setLabelLatitude(const QString &s)
{
    this->ui->labelLatitude->setText(s);
}

void    MainWindow::setLabelLongitudeDir(const QString &s)
{
    this->ui->labelLongitudeDir->setText(s);
}

void    MainWindow::setLabelLatitudeDir(const QString &s)
{
    this->ui->labelLatitudeDir->setText(s);
}

void    MainWindow::setLabelStatement(bool b)
{
    b == true ? this->ui->labelStatement->setText("Running") : this->ui->labelStatement->setText("Stopped");
}

void    MainWindow::setLabelGPGSA(const QString &s)
{
    this->ui->labelGPGSA->setText(s);
}

void    MainWindow::setLabelPHVDOP(const QString &p, const QString &h, const QString &v)
{
    this->ui->labelPDOP->setText(p);
    this->ui->labelHDOP->setText(h);
    this->ui->labelVDOP->setText(v);
}

void    MainWindow::setWeb()
{
/*    ui->webView->load(QUrl("http://192.168.1.5/index.php?lng=" +
                       s.setNum(this->gps->getLongitude()) +
                       "&lat=" + s.setNum(this->gps->getLatitude())));*/
    //## Because QT 4.5 is too old... :(
}

void    MainWindow::stopData()
{
    this->rec->setFlag(false);
    if (this->rec->getFile().isOpen())
        this->rec->closeFile();
    this->setLabelStatement(false);
    ui->buttonLauncher->setEnabled(true);
    ui->buttonStop->setEnabled(false);
    //    this->gps->wait(); ## Because QThread suxx!
}

void    MainWindow::startData()
{
    this->gps->start();
    this->setLabelStatement(true);
    ui->buttonStop->setEnabled(true);
    ui->buttonLauncher->setEnabled(false);
}

void    MainWindow::startRecord()
{
    QFileDialog *dial = new QFileDialog;
    dial->setFixedSize(200, 200);
    QString filename = dial->getSaveFileName(this, "Save file", "", "KML File (*.kml)");
    if (this->rec->init(filename))
        this->rec->setFlag(true);
    ui->buttonRecord->setEnabled(false);
    ui->buttonStopRecord->setEnabled(true);
}

void    MainWindow::stopRecord()
{
    this->rec->setFlag(false);
    this->rec->closeFile();
    ui->buttonStopRecord->setEnabled(false);
    ui->buttonRecord->setEnabled(true);
}

void    MainWindow::cleanData()
{
    this->http->clearData();
    if (this->rec->getFile().isOpen())
        this->rec->closeFile();
}

void    MainWindow::closeEvent(QCloseEvent *event)
{
    cleanData();
    event->accept();
}
