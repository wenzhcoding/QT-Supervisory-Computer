#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qcw_indicatorlamp.h"
#include <widget.h>

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "windows.h"
#include <QTimer>
#include <QMessageBox>
#include <QTime>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QMenu>
#include <QMenuBar>
#include <dayin.h>
#include <shuoming.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Widget correct;
    QcwIndicatorLamp qcw;


    dayin A;
    shuoming B;

    QSerialPort* My_Port1;

    bool auto_flg = 0;
    int SHIYANCISHU = 0;
    int test_cnt = 0;
    int step;//步数
    int pulse;//每步所需脉冲数
    const double mini = 0.04;//最小步进距离um
    double len; // um
    double spd; // um/us
    double time;//电机一个step加采样的总时间 us
    double time2;
    double T;   //电机一个mini总时间
    double T3 = 0;  //采样时间
    int N = 1000;      //采样次数
    double dis; //位移  um
    double previous;
    double pre; //压力  N
    double pre_detect_ave[1000];
    double pre_detect;
    double angle;//    rad
    double torque;//   Nm
    double dis_sum;
    double pre_sum;
    double dis_pre_sum;
    double dis_sqr_sum;
    double angle_sum;
    double torque_sum;
    double angle_torque_sum;
    double angle_sqr_sum;
    double sti_test;
    double sti; //刚度 stiffness  Nm/rad  N/m
    double k;
    double k_test;
    double b;
    const double R = 0.0005;//m
    int rowCount;
    int step_cnt;
    int pulse_cnt;
    int stop_cnt;
    int stop_cnt_2;
    int step_cnt_new;
    int remsr_cnt;
    int mengding_cnt;
    int flg;
    int flg_ins;
    double pre_zero;
    double pre_ave[1000];
    int pre_num;
    double dis_total[1000];
    double dis_total_new[1000];
    double dis_sqr_total[1000];
    double pre_total[1000];
    double pre_total_new[1000];
    double dis_pre_total[1000];
    double angle_total[1000];
    double torque_total[1000];
    double angle_torque_total[1000];
    double angle_sqr_total[1000];

    double pre_ave_sec[20];
    double pre_sec_total;
    int ave_cnt = 0;

    double total;
    double average;

    double down;
    double up;
    int detect_cnt =0;
    bool pre_flg = false;
    bool flg_new = false;
    bool flg_touched = false;   //接触到以后为true，自动实验使用。

    //////////////////
    double distance_wrong_data_correction[1000];
    double pressure_wrong_data_correction[1000];
    //////////////////

    int convert;// 0 false,1 true

    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer_auto;
    QTimer *timer_auto_2;
    QTimer *mengding;
    QTimer *houtui;

    QDate  currentDate;
    QTime  currentTime;
    QString strDate;
    QString strTime;
    QString saveSamplePath;
    QTextStream *out;
    QFile *file;
    quint8 portVal;


    QByteArray serialPortData;

    void Port1_Init();
    void QCP_Init();
    void QCP_Review_Init();
    void Sample();
    void sendData_1();
    void sendData_2();
    void sendData_3();
    void Draw_Customplot();
    void tblWidget();
    void saveData();
    void openDocument();
    void processCurvedata();
    void getData();
    void getData_previous();
    void timer_Pause();
    void timer_Start();
    void timer_stop();
    void Sample_clicked();



    double setZero; //开始实验时的零点

    void SetDo_High();
    void SetDo_Low();

    void MessageFunc();

    void MessageFunc(int *_, QString str1, QString str2);
private slots:
    void processPort1();

    void timeout();
    void timeout2();
    void timeout3();
    void timer_auto_out();
    void timer_auto_out_2();
    void houtui_out();
    void mengding_out();
    void jishi_out();

    void inspect();
    void instruction();
    void review();
    void about();
    void correctsti();


    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    //void on_spinBox_editingFinished();
    //void on_spinBox_2_editingFinished();

    //void on_pushButton_clicked();

    void on_pushButton_calculate_clicked();
    void on_pushButton_clear_clicked();

    //void on_pushButton_foward_clicked();
    void on_pushButton_Stopmove_clicked();
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_Move_clicked();

    //void on_radioButton_2_clicked();

    //void on_radioButton_clicked();
    //void on_horizontalSlider_sliderMoved(int position);




    void on_pushButton_sample_clicked();
    void on_pushButton_Senddata_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_auto_clicked();
    void on_pushButton_mengding_clicked();
};

#endif // MAINWINDOW_H
