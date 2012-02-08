/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Dec 25 18:04:57 2011
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelTextLatitude;
    QLabel *labelTextLongitude;
    QLabel *labelLatitude;
    QLabel *labelLongitude;
    QPushButton *buttonLauncher;
    QPushButton *buttonStop;
    QLabel *labelStatement;
    QPushButton *buttonRecord;
    QPushButton *buttonStopRecord;
    QLabel *labelTitleGPRMC;
    QLabel *labelTitleGPGSA;
    QLabel *labelLatitudeDir;
    QLabel *labelLongitudeDir;
    QLabel *labelGPGSA;
    QLabel *labelTitlePDOP;
    QLabel *labelTitleHDOP;
    QLabel *labelPDOP;
    QLabel *labelHDOP;
    QLabel *labelTitleVDOP;
    QLabel *labelVDOP;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 194);
        MainWindow->setStyleSheet(QString::fromUtf8("#labelTitleGPGSA, #labelTitleGPRMC {\n"
"font-size:15px;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"#labelStatement {\n"
"font-size:12px;\n"
"font-weight: bold;\n"
"color: red;\n"
"}\n"
"\n"
"QMainWindow {\n"
"background-color: white;\n"
"}\n"
"\n"
"QPushButton {\n"
"min-width: 54px;\n"
"border: 1px solid #DCDCDC;\n"
"text-align: center;\n"
"color: #444444;\n"
"font-size: 85%;\n"
"font-weight: bold;\n"
"height: 27px;\n"
"padding: 0 8px;\n"
"border-radius: 2px;\n"
"background-color: #F5F5F5;\n"
"background-image: -webkit-gradient(linear,left top,left\n"
"bottom,from(#f5f5f5),to(#f1f1f1));\n"
"background-image: -webkit-linear-gradient(top,#f5f5f5,#f1f1f1);\n"
"background-image: -moz-linear-gradient(top,#f5f5f5,#f1f1f1);\n"
"background-image: -ms-linear-gradient(top,#f5f5f5,#f1f1f1);\n"
"background-image: -o-linear-gradient(top,#f5f5f5,#f1f1f1);\n"
"background-image: linear-gradient(top,#f5f5f5,#f1f1f1);\n"
"text-decoration: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border: 1px solid #C6C6C6;\n"
"color: #333;\n"
"b"
                        "ackground-color: #F8F8F8;\n"
"background-image: -webkit-gradient(linear,left top,left bottom,from(#f8f8f8),to(#f1f1f1));\n"
"background-image: -webkit-linear-gradient(top,#f8f8f8,#f1f1f1);\n"
"background-image: -moz-linear-gradient(top,#f8f8f8,#f1f1f1);\n"
"background-image: -ms-linear-gradient(top,#f8f8f8,#f1f1f1);\n"
"background-image: -o-linear-gradient(top,#f8f8f8,#f1f1f1);\n"
"background-image: linear-gradient(top,#f8f8f8,#f1f1f1);\n"
"text-decoration: none;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelTextLatitude = new QLabel(centralwidget);
        labelTextLatitude->setObjectName(QString::fromUtf8("labelTextLatitude"));
        labelTextLatitude->setGeometry(QRect(20, 80, 61, 17));
        labelTextLongitude = new QLabel(centralwidget);
        labelTextLongitude->setObjectName(QString::fromUtf8("labelTextLongitude"));
        labelTextLongitude->setGeometry(QRect(210, 80, 71, 17));
        labelLatitude = new QLabel(centralwidget);
        labelLatitude->setObjectName(QString::fromUtf8("labelLatitude"));
        labelLatitude->setGeometry(QRect(90, 80, 67, 17));
        labelLongitude = new QLabel(centralwidget);
        labelLongitude->setObjectName(QString::fromUtf8("labelLongitude"));
        labelLongitude->setGeometry(QRect(290, 80, 67, 17));
        buttonLauncher = new QPushButton(centralwidget);
        buttonLauncher->setObjectName(QString::fromUtf8("buttonLauncher"));
        buttonLauncher->setGeometry(QRect(20, 20, 97, 27));
        buttonStop = new QPushButton(centralwidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setGeometry(QRect(150, 20, 97, 27));
        labelStatement = new QLabel(centralwidget);
        labelStatement->setObjectName(QString::fromUtf8("labelStatement"));
        labelStatement->setGeometry(QRect(260, 20, 61, 31));
        buttonRecord = new QPushButton(centralwidget);
        buttonRecord->setObjectName(QString::fromUtf8("buttonRecord"));
        buttonRecord->setGeometry(QRect(20, 150, 97, 27));
        buttonStopRecord = new QPushButton(centralwidget);
        buttonStopRecord->setObjectName(QString::fromUtf8("buttonStopRecord"));
        buttonStopRecord->setGeometry(QRect(150, 150, 97, 27));
        labelTitleGPRMC = new QLabel(centralwidget);
        labelTitleGPRMC->setObjectName(QString::fromUtf8("labelTitleGPRMC"));
        labelTitleGPRMC->setGeometry(QRect(20, 60, 67, 17));
        labelTitleGPGSA = new QLabel(centralwidget);
        labelTitleGPGSA->setObjectName(QString::fromUtf8("labelTitleGPGSA"));
        labelTitleGPGSA->setGeometry(QRect(20, 100, 67, 17));
        labelLatitudeDir = new QLabel(centralwidget);
        labelLatitudeDir->setObjectName(QString::fromUtf8("labelLatitudeDir"));
        labelLatitudeDir->setGeometry(QRect(160, 80, 21, 17));
        labelLongitudeDir = new QLabel(centralwidget);
        labelLongitudeDir->setObjectName(QString::fromUtf8("labelLongitudeDir"));
        labelLongitudeDir->setGeometry(QRect(360, 80, 21, 17));
        labelGPGSA = new QLabel(centralwidget);
        labelGPGSA->setObjectName(QString::fromUtf8("labelGPGSA"));
        labelGPGSA->setGeometry(QRect(20, 120, 111, 17));
        labelTitlePDOP = new QLabel(centralwidget);
        labelTitlePDOP->setObjectName(QString::fromUtf8("labelTitlePDOP"));
        labelTitlePDOP->setGeometry(QRect(150, 120, 41, 17));
        labelTitleHDOP = new QLabel(centralwidget);
        labelTitleHDOP->setObjectName(QString::fromUtf8("labelTitleHDOP"));
        labelTitleHDOP->setGeometry(QRect(220, 120, 41, 17));
        labelPDOP = new QLabel(centralwidget);
        labelPDOP->setObjectName(QString::fromUtf8("labelPDOP"));
        labelPDOP->setGeometry(QRect(190, 120, 31, 17));
        labelHDOP = new QLabel(centralwidget);
        labelHDOP->setObjectName(QString::fromUtf8("labelHDOP"));
        labelHDOP->setGeometry(QRect(260, 120, 31, 17));
        labelTitleVDOP = new QLabel(centralwidget);
        labelTitleVDOP->setObjectName(QString::fromUtf8("labelTitleVDOP"));
        labelTitleVDOP->setGeometry(QRect(290, 120, 41, 17));
        labelVDOP = new QLabel(centralwidget);
        labelVDOP->setObjectName(QString::fromUtf8("labelVDOP"));
        labelVDOP->setGeometry(QRect(330, 120, 61, 20));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        labelTextLatitude->setText(QApplication::translate("MainWindow", "Latitude", 0, QApplication::UnicodeUTF8));
        labelTextLongitude->setText(QApplication::translate("MainWindow", "Longitude", 0, QApplication::UnicodeUTF8));
        labelLatitude->setText(QString());
        labelLongitude->setText(QString());
        buttonLauncher->setText(QApplication::translate("MainWindow", "Launch", 0, QApplication::UnicodeUTF8));
        buttonStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        labelStatement->setText(QString());
        buttonRecord->setText(QApplication::translate("MainWindow", "Record", 0, QApplication::UnicodeUTF8));
        buttonStopRecord->setText(QApplication::translate("MainWindow", "Stop Rec", 0, QApplication::UnicodeUTF8));
        labelTitleGPRMC->setText(QApplication::translate("MainWindow", "GPRMC", 0, QApplication::UnicodeUTF8));
        labelTitleGPGSA->setText(QApplication::translate("MainWindow", "GPGSA", 0, QApplication::UnicodeUTF8));
        labelLatitudeDir->setText(QString());
        labelLongitudeDir->setText(QString());
        labelGPGSA->setText(QString());
        labelTitlePDOP->setText(QApplication::translate("MainWindow", "PDOP", 0, QApplication::UnicodeUTF8));
        labelTitleHDOP->setText(QApplication::translate("MainWindow", "HDOP", 0, QApplication::UnicodeUTF8));
        labelPDOP->setText(QString());
        labelHDOP->setText(QString());
        labelTitleVDOP->setText(QApplication::translate("MainWindow", "VDOP", 0, QApplication::UnicodeUTF8));
        labelVDOP->setText(QString());
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
