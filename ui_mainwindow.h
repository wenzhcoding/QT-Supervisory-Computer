/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_13;
    QLabel *label_14;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_3;
    QSpinBox *spinBox;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_start;
    QGroupBox *groupBox1;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_6;
    QLabel *label_currentStep;
    QPushButton *pushButton;
    QPushButton *pushButton_clear;
    QLabel *label_17;
    QGroupBox *groupBox_7;
    QSpinBox *spinBox_auto;
    QLabel *label_19;
    QPushButton *pushButton_auto;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_calculate;
    QLineEdit *lineEdit;
    QSpinBox *spinBox_sti_startNum;
    QLabel *label_8;
    QGroupBox *groupBox_6;
    QDoubleSpinBox *doubleSpinBox_a;
    QDoubleSpinBox *doubleSpinBox_b;
    QLabel *label_7;
    QLabel *label_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_Stopmove;
    QPushButton *pushButton_Move;
    QSlider *horizontalSlider;
    QRadioButton *radioButton_back;
    QRadioButton *radioButton_foward;
    QLabel *label_5;
    QPushButton *pushButton_Senddata;
    QPushButton *pushButton_sample;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_mengding;
    QSpinBox *spinBox_mengding;
    QCustomPlot *customPlot_review;
    QGroupBox *groupBox_5;
    QTableWidget *tableWidget_2;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1313, 808);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(0, 30, 681, 411));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 1000)
            tableWidget->setRowCount(1000);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(680, 30, 221, 411));
        QFont font1;
        font1.setFamily(QStringLiteral("Aharoni"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        tableWidget->setFont(font1);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoScroll(false);
        tableWidget->setRowCount(1000);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setDefaultSectionSize(87);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 450, 161, 351));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        groupBox->setFont(font2);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 140, 91, 31));
        QFont font3;
        font3.setPointSize(15);
        lineEdit_3->setFont(font3);
        lineEdit_3->setReadOnly(true);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 60, 91, 31));
        QFont font4;
        font4.setPointSize(13);
        lineEdit_2->setFont(font4);
        lineEdit_2->setReadOnly(true);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 200, 141, 41));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 260, 71, 41));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(84, 260, 71, 41));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 70, 54, 12));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 150, 54, 12));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(680, 440, 621, 351));
        groupBox_2->setFont(font2);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 101, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        label_3->setFont(font5);
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(130, 90, 111, 41));
        QFont font6;
        font6.setPointSize(16);
        doubleSpinBox_2->setFont(font6);
        doubleSpinBox_2->setValue(1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 91, 50));
        label_2->setFont(font5);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 71, 51));
        label->setFont(font5);
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(130, 150, 111, 41));
        doubleSpinBox_3->setMinimumSize(QSize(111, 41));
        doubleSpinBox_3->setFont(font6);
        doubleSpinBox_3->setMinimum(1);
        doubleSpinBox_3->setMaximum(5);
        doubleSpinBox_3->setValue(1);
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 30, 111, 41));
        spinBox->setFont(font6);
        spinBox->setMaximum(500000);
        spinBox->setValue(40);
        pushButton_stop = new QPushButton(groupBox_2);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(260, 210, 161, 61));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font7.setPointSize(18);
        font7.setBold(false);
        font7.setWeight(50);
        pushButton_stop->setFont(font7);
        pushButton_stop->setStyleSheet(QLatin1String("QPushButton{background-color:white;\n"
"			color: red;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: red;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_start = new QPushButton(groupBox_2);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(260, 120, 161, 61));
        pushButton_start->setFont(font7);
        pushButton_start->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:green;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: green;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        groupBox1 = new QGroupBox(groupBox_2);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        groupBox1->setEnabled(false);
        groupBox1->setGeometry(QRect(530, 250, 91, 91));
        radioButton = new QRadioButton(groupBox1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 101, 31));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 101, 31));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(451, 70, 131, 41));
        QFont font8;
        font8.setPointSize(14);
        font8.setBold(false);
        font8.setWeight(50);
        label_6->setFont(font8);
        label_currentStep = new QLabel(groupBox_2);
        label_currentStep->setObjectName(QStringLiteral("label_currentStep"));
        label_currentStep->setGeometry(QRect(451, 110, 131, 41));
        QFont font9;
        font9.setPointSize(20);
        font9.setBold(true);
        font9.setWeight(75);
        label_currentStep->setFont(font9);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 30, 161, 61));
        pushButton->setFont(font7);
        pushButton->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_clear = new QPushButton(groupBox_2);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(450, 170, 136, 41));
        QFont font10;
        font10.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font10.setPointSize(12);
        font10.setBold(false);
        font10.setWeight(50);
        pushButton_clear->setFont(font10);
        pushButton_clear->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 210, 101, 51));
        label_17->setFont(font5);
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 270, 441, 80));
        spinBox_auto = new QSpinBox(groupBox_7);
        spinBox_auto->setObjectName(QStringLiteral("spinBox_auto"));
        spinBox_auto->setGeometry(QRect(130, 20, 111, 41));
        spinBox_auto->setFont(font6);
        spinBox_auto->setMinimum(1);
        spinBox_auto->setMaximum(20);
        spinBox_auto->setValue(5);
        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 20, 101, 51));
        label_19->setFont(font5);
        pushButton_auto = new QPushButton(groupBox_7);
        pushButton_auto->setObjectName(QStringLiteral("pushButton_auto"));
        pushButton_auto->setGeometry(QRect(260, 20, 161, 41));
        pushButton_auto->setFont(font10);
        pushButton_auto->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(160, 450, 201, 351));
        groupBox_3->setFont(font2);
        pushButton_calculate = new QPushButton(groupBox_3);
        pushButton_calculate->setObjectName(QStringLiteral("pushButton_calculate"));
        pushButton_calculate->setGeometry(QRect(40, 260, 81, 31));
        QFont font11;
        font11.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font11.setPointSize(12);
        pushButton_calculate->setFont(font11);
        pushButton_calculate->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:rgb(255, 85, 0);  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color:rgb(255, 85, 0);\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 220, 91, 31));
        QFont font12;
        font12.setPointSize(10);
        font12.setBold(true);
        font12.setWeight(75);
        lineEdit->setFont(font12);
        lineEdit->setReadOnly(true);
        spinBox_sti_startNum = new QSpinBox(groupBox_3);
        spinBox_sti_startNum->setObjectName(QStringLiteral("spinBox_sti_startNum"));
        spinBox_sti_startNum->setGeometry(QRect(100, 60, 71, 31));
        spinBox_sti_startNum->setFont(font12);
        spinBox_sti_startNum->setValue(5);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 60, 71, 31));
        QFont font13;
        font13.setPointSize(10);
        label_8->setFont(font13);
        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 120, 201, 80));
        QFont font14;
        font14.setBold(false);
        font14.setWeight(50);
        groupBox_6->setFont(font14);
        doubleSpinBox_a = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_a->setObjectName(QStringLiteral("doubleSpinBox_a"));
        doubleSpinBox_a->setGeometry(QRect(21, 31, 61, 31));
        QFont font15;
        font15.setPointSize(8);
        font15.setBold(true);
        font15.setWeight(75);
        doubleSpinBox_a->setFont(font15);
        doubleSpinBox_a->setMaximum(9.999e+7);
        doubleSpinBox_b = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_b->setObjectName(QStringLiteral("doubleSpinBox_b"));
        doubleSpinBox_b->setGeometry(QRect(120, 31, 62, 31));
        QFont font16;
        font16.setBold(true);
        font16.setWeight(75);
        doubleSpinBox_b->setFont(font16);
        label_7 = new QLabel(groupBox_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 40, 61, 31));
        QFont font17;
        font17.setPointSize(18);
        font17.setBold(true);
        font17.setWeight(75);
        font17.setKerning(true);
        label_7->setFont(font17);
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 220, 41, 30));
        label_12->setFont(font12);
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 300, 91, 31));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:rgb(255, 85, 0);  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color:rgb(255, 85, 0);\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 300, 51, 31));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:rgb(255, 85, 0);  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color:rgb(255, 85, 0);\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(360, 450, 321, 351));
        groupBox_4->setFont(font2);
        groupBox_4->setStyleSheet(QLatin1String("\n"
"QPushButton { background-color: rgb(255, 132, 139); }\n"
""));
        pushButton_Stopmove = new QPushButton(groupBox_4);
        pushButton_Stopmove->setObjectName(QStringLiteral("pushButton_Stopmove"));
        pushButton_Stopmove->setGeometry(QRect(60, 250, 221, 61));
        QFont font18;
        font18.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font18.setPointSize(12);
        font18.setBold(true);
        font18.setWeight(75);
        pushButton_Stopmove->setFont(font18);
        pushButton_Stopmove->setStyleSheet(QLatin1String("QPushButton{background-color:white;\n"
"			color: red;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: red;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_Move = new QPushButton(groupBox_4);
        pushButton_Move->setObjectName(QStringLiteral("pushButton_Move"));
        pushButton_Move->setGeometry(QRect(200, 170, 71, 61));
        QFont font19;
        font19.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font19.setPointSize(12);
        pushButton_Move->setFont(font19);
        pushButton_Move->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:green;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: green;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        horizontalSlider = new QSlider(groupBox_4);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 80, 231, 41));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(20);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(5);
        horizontalSlider->setValue(1);
        horizontalSlider->setSliderPosition(1);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(true);
        radioButton_back = new QRadioButton(groupBox_4);
        radioButton_back->setObjectName(QStringLiteral("radioButton_back"));
        radioButton_back->setGeometry(QRect(70, 200, 89, 31));
        radioButton_back->setFont(font19);
        radioButton_foward = new QRadioButton(groupBox_4);
        radioButton_foward->setObjectName(QStringLiteral("radioButton_foward"));
        radioButton_foward->setGeometry(QRect(70, 170, 89, 31));
        radioButton_foward->setFont(font19);
        radioButton_foward->setChecked(true);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 80, 71, 41));
        label_5->setFont(font10);
        pushButton_Senddata = new QPushButton(groupBox_4);
        pushButton_Senddata->setObjectName(QStringLiteral("pushButton_Senddata"));
        pushButton_Senddata->setGeometry(QRect(-80, 250, 75, 31));
        pushButton_Senddata->setFont(font10);
        pushButton_Senddata->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_sample = new QPushButton(groupBox_4);
        pushButton_sample->setObjectName(QStringLiteral("pushButton_sample"));
        pushButton_sample->setGeometry(QRect(-190, 240, 75, 31));
        pushButton_sample->setFont(font11);
        pushButton_sample->setStyleSheet(QLatin1String("QPushButton{background-color: white;\n"
"			color:black;  \n"
"			border-radius: 10px;\n"
"		    border: 2px groove gray;\n"
"			border-style: outset;}\n"
"QPushButton:hover{background-color:white; \n"
"				  color: black;\n"
"border-style: inset;}\n"
"QPushButton:pressed{background-color:rgb(85, 170, 255); 							border-style: inset; }"));
        pushButton_sample->setCheckable(true);
        pushButton_sample->setChecked(false);
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(100, 70, 21, 16));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(290, 70, 21, 16));
        pushButton_mengding = new QPushButton(groupBox_4);
        pushButton_mengding->setObjectName(QStringLiteral("pushButton_mengding"));
        pushButton_mengding->setGeometry(QRect(180, 120, 75, 23));
        spinBox_mengding = new QSpinBox(groupBox_4);
        spinBox_mengding->setObjectName(QStringLiteral("spinBox_mengding"));
        spinBox_mengding->setGeometry(QRect(210, 30, 42, 22));
        spinBox_mengding->setValue(50);
        customPlot_review = new QCustomPlot(centralWidget);
        customPlot_review->setObjectName(QStringLiteral("customPlot_review"));
        customPlot_review->setGeometry(QRect(900, 210, 401, 231));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(900, 30, 401, 181));
        groupBox_5->setFont(font11);
        tableWidget_2 = new QTableWidget(groupBox_5);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QFont font20;
        font20.setPointSize(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font20);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font20);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        if (tableWidget_2->rowCount() < 1000)
            tableWidget_2->setRowCount(1000);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font20);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font20);
        tableWidget_2->setItem(3, 1, __qtablewidgetitem5);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(240, 10, 151, 171));
        QFont font21;
        font21.setPointSize(9);
        tableWidget_2->setFont(font21);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setRowCount(1000);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(48);
        tableWidget_2->horizontalHeader()->setHighlightSections(false);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_2->horizontalHeader()->setStretchLastSection(false);
        tableWidget_2->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(28);
        tableWidget_2->verticalHeader()->setMinimumSectionSize(24);
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 48, 91, 21));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 120, 91, 16));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(93, 50, 141, 20));
        label_10->setFont(font13);
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(100, 120, 151, 20));
        doubleSpinBox_4 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(810, 650, 111, 41));
        QFont font22;
        font22.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font22.setPointSize(16);
        doubleSpinBox_4->setFont(font22);
        doubleSpinBox_4->setMinimum(1);
        doubleSpinBox_4->setMaximum(20);
        doubleSpinBox_4->setValue(5);
        MainWindow->setCentralWidget(centralWidget);
        customPlot->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        tableWidget->raise();
        groupBox->raise();
        groupBox_4->raise();
        customPlot_review->raise();
        groupBox_5->raise();
        doubleSpinBox_4->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        customPlot->setWhatsThis(QApplication::translate("MainWindow", "\347\273\230\345\233\276\345\214\272", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273(um)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233(N)", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("MainWindow", "\345\256\236\351\252\214\346\225\260\346\215\256\345\210\227\350\241\250", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\225\260\346\215\256\346\243\200\346\265\213", Q_NULLPTR));
        lineEdit_3->setText(QString());
        lineEdit_2->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\350\260\203\351\233\266", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\243\200  \346\265\213", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\243\200\346\265\213", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\345\200\274\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273\345\200\274\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\256\236\351\252\214\351\235\242\346\235\277", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246(um/s)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        doubleSpinBox_2->setStatusTip(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\255\245\351\225\277", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("MainWindow", "\346\255\245  \351\225\277(um)", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\255\245    \346\225\260", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        doubleSpinBox_3->setStatusTip(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\200\237\345\272\246(0~25)", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        spinBox->setStatusTip(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\255\245\346\225\260", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        pushButton_stop->setStatusTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\234\254\346\254\241\345\256\236\351\252\214", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\256\236\351\252\214", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_start->setStatusTip(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\256\236\351\252\214\345\211\215\350\257\267\347\241\256\345\256\232\346\230\257\345\220\246\346\240\207\345\256\232\351\233\266\347\202\271", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\256\236\351\252\214", Q_NULLPTR));
        groupBox1->setTitle(QString());
        radioButton->setText(QApplication::translate("MainWindow", "\345\211\215\350\277\233", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\345\220\216\351\200\200", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\234\211\346\225\210\346\255\245\346\225\260:", Q_NULLPTR));
        label_currentStep->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("MainWindow", "\346\212\212\345\275\223\345\211\215\344\275\215\347\275\256\350\256\276\344\270\272\351\233\266\347\202\271", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton->setText(QApplication::translate("MainWindow", "\351\233\266\347\202\271\346\240\207\345\256\232", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_clear->setStatusTip(QApplication::translate("MainWindow", "\345\206\215\346\254\241\345\256\236\351\252\214\345\211\215\346\270\205\347\251\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\233\276\350\241\250", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\216\213\345\212\233\357\274\210N\357\274\211", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\256\236\351\252\214\351\235\242\346\235\277", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\256\236\351\252\214\346\254\241\346\225\260", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_auto->setStatusTip(QApplication::translate("MainWindow", "\345\206\215\346\254\241\345\256\236\351\252\214\345\211\215\346\270\205\347\251\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_auto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\256\236\351\252\214", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\244\204\347\220\206\345\214\272", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_calculate->setStatusTip(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\210\232\345\272\246\345\271\266\346\213\237\345\220\210\346\233\262\347\272\277", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_calculate->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\210\232\345\272\246", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        spinBox_sti_startNum->setStatusTip(QApplication::translate("MainWindow", "\345\211\224\351\231\244\345\211\215N\344\270\252\347\202\271", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_8->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\347\202\271\350\256\276\347\275\256:", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\345\210\232\345\272\246\350\276\276\346\240\207\350\214\203\345\233\264", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        doubleSpinBox_a->setStatusTip(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\210\232\345\272\246\344\270\213\351\231\220", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        doubleSpinBox_b->setStatusTip(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\210\232\345\272\246\344\270\212\351\231\220", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_7->setText(QApplication::translate("MainWindow", "  ~", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "N/um", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\210\260\346\211\223\345\215\260\345\210\227\350\241\250", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\346\216\247\345\210\266\351\235\242\346\235\277", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_Stopmove->setStatusTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\224\265\346\234\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_Stopmove->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\247\273\345\212\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_Move->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_Move->setStatusTip(QApplication::translate("MainWindow", "\345\277\253\351\200\237\347\247\273\345\212\250\347\224\265\346\234\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_Move->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        horizontalSlider->setStatusTip(QApplication::translate("MainWindow", "\350\260\203\350\212\202\347\224\265\346\234\272\347\247\273\345\212\250\351\200\237\345\272\246", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        radioButton_back->setText(QApplication::translate("MainWindow", "\345\220\216\351\200\200", Q_NULLPTR));
        radioButton_foward->setText(QApplication::translate("MainWindow", "\345\211\215\350\277\233", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246\350\260\203\350\212\202", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_Senddata->setStatusTip(QApplication::translate("MainWindow", "\346\243\200\346\265\213\345\275\223\345\211\215\346\227\266\345\210\273\344\275\215\347\275\256", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_Senddata->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\346\243\200\346\265\213", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_sample->setStatusTip(QApplication::translate("MainWindow", "\346\243\200\346\265\213\345\275\223\345\211\215\346\227\266\345\210\273\345\216\213\345\212\233", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_sample->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\346\243\200\346\265\213", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\346\205\242", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\345\277\253", Q_NULLPTR));
        pushButton_mengding->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256\346\265\217\350\247\210", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273(mm)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233(N)", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        label_4->setText(QApplication::translate("MainWindow", "\345\256\236\351\252\214\346\227\266\351\227\264 \357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\210\232     \345\272\246\357\274\232", Q_NULLPTR));
        label_10->setText(QString());
        label_11->setText(QString());
#ifndef QT_NO_STATUSTIP
        doubleSpinBox_4->setStatusTip(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\200\237\345\272\246(0~25)", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
