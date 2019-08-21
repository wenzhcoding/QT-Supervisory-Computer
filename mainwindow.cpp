#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "winio.h"
#include "qcustomplot.h"
#include <QThread>
#include <random>
#include <windows.h>
#include <iostream>

#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>


#define ADC_ADDRESS (0x280)
#define ADC_CHANNEL (4)
#define DO_ADDRESS (0x284)
#define DO_HIGH (0Xff)
#define DO_LOW (0x00)



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qcw.setParent(ui->groupBox_4);
    qcw.setGeometry(130,130,50,50);
    qcw.setAlarm(false);
    qcw.show();

    //A = new dayin(this);
    //B = new shuoming(this);

    A.move(0,200);
    A.show();
    B.move(1650,200);
    B.show();


    this->setWindowTitle("刚度仪测试软件");

    ui->pushButton_sample->setVisible(false);

    ui->tableWidget->verticalHeader()->setVisible(true);

//    correct.show();

    QMenuBar *qmenuBar;
    qmenuBar = new QMenuBar(this);

    QMenu *qmenuA = new QMenu("工具");
    QMenu *qmenuB = new QMenu("帮助");
    QAction *actionA = new QAction("自检");
    QAction *actionB = new QAction("历史数据");
    QAction *actionC = new QAction("使用说明");
    QAction *actionD = new QAction("打印");
    QAction *actionE = new QAction("刚度校准");
    qmenuBar->addMenu(qmenuA);
    qmenuBar->addMenu(qmenuB);
    qmenuA->addAction(actionA);
    qmenuA->addAction(actionB);
    qmenuA->addAction(actionE);
    qmenuB->addAction(actionC);
    qmenuB->addAction(actionD);

    connect(actionA,SIGNAL(triggered(bool)),this,SLOT(inspect()));
    connect(actionB,SIGNAL(triggered(bool)),this,SLOT(review()));
    connect(actionC,SIGNAL(triggered(bool)),this,SLOT(instruction()));
    connect(actionD,SIGNAL(triggered(bool)),this,SLOT(about()));
    connect(actionE,SIGNAL(triggered(bool)),this,SLOT(correctsti()));


    QCP_Init();                    //QCP初始化
    QCP_Review_Init();
//    openDocument();

    rowCount = 0;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格内容为只读

    My_Port1=new QSerialPort(this);//串口实例化
    My_Port1->setPortName("COM1");
    Port1_Init();

    bool b_initWinioRes=false;
    b_initWinioRes = InitializeWinIo();    //初始化IO操作的链接库
    if(b_initWinioRes==false){
        QMessageBox::warning(this,"警告","采集卡故障",QMessageBox::Yes);
    }

//    SetPortVal(DO_ADDRESS,DO_LOW,1);          //设置DO输出为全零
    SetDo_High();        //设置DO输出为全零

    timer = new QTimer();           //定时器实例化
    timer->setInterval(time);          //设置间隔为走完一个STEP的时间
    timer->stop();                  //停止定时器

    timer2 = new QTimer();
    timer2->stop();
    time2 = 20;

    timer3 =new QTimer();
    timer3->stop();

    timer_auto = new QTimer(this);
    timer_auto->stop();

    timer_auto_2 = new QTimer(this);
    timer_auto_2->stop();

    mengding = new QTimer(this);
    mengding->stop();
    houtui = new QTimer(this);
    houtui->stop();


    step_cnt = 0;
    step_cnt_new = 0 ;

    pulse_cnt = 0;
    stop_cnt = 0;
    remsr_cnt = 0;
    setZero = 0;

    pre_num = 0;
    angle_sum = 0;
    torque_sum = 0;
    angle_torque_sum = 0;
    angle_sqr_sum = 0;


     connect(My_Port1,SIGNAL(readyRead()),this,SLOT(processPort1()));
     connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));  //连接信号和槽
     connect(timer2,SIGNAL(timeout()),this,SLOT(timeout2()));
     connect(timer3,SIGNAL(timeout()),this,SLOT(timeout3()));
     connect(timer_auto,SIGNAL(timeout()),this,SLOT (timer_auto_out()));
     connect(timer_auto_2,SIGNAL(timeout()),this,SLOT (timer_auto_out_2()));

     connect(mengding,SIGNAL(timeout()),this,SLOT(mengding_out()));
     connect(houtui,SIGNAL(timeout()),this,SLOT(houtui_out()));

     ui->radioButton_foward->setChecked(false);
     ui->radioButton_back->setChecked(false);

     portVal=0;

     flg = 0;
     dis = 0;
     pre = 0;
     pre_detect = 0;
     down = 0,up=0;

     qcw.m_alarm = false;
     qcw.m_state = false;

     emit on_pushButton_4_clicked();
//     sendData_1();//位置标定

     //timer2->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::QCP_Init()
{

    ui->customPlot->addGraph(); // blue line
    ui->customPlot->xAxis->setLabel("位移（um）");
    ui->customPlot->xAxis->setRange(0,30);
    ui->customPlot->yAxis->setLabel("力（N）");
    ui->customPlot->yAxis->setRange(20,0);
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(0)->setName("原始曲线");
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(1)->setName("拟合曲线");
    ui->customPlot->graph(1)->setVisible(true);
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->rescaleAxes(false);

    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
}

void MainWindow::QCP_Review_Init()
{
    ui->customPlot_review->addGraph(); // blue line
    ui->customPlot_review->xAxis->setLabel("位移（um）");
    ui->customPlot_review->xAxis->setRange(0,30);
    ui->customPlot_review->yAxis->setLabel("力（N）");
    ui->customPlot_review->yAxis->setRange(20,0);
    ui->customPlot_review->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot_review->graph(0)->setName("原始曲线");
    ui->customPlot_review->addGraph(); // red line
    ui->customPlot_review->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot_review->graph(1)->setName("拟合曲线");
    ui->customPlot_review->graph(1)->setVisible(true);
    ui->customPlot_review->legend->setVisible(true);
    ui->customPlot_review->rescaleAxes(true);

    ui->customPlot_review->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
}

void MainWindow::openDocument()
{
    //save data
    currentTime=QTime::currentTime();
    currentDate=QDate::currentDate();
    strDate = currentDate.toString(Qt::ISODate);
    strTime = currentTime.toString("hh-mm-ss");
    saveSamplePath="C:/Users/Administrator/Desktop/test_repeat/"+strDate+" "+strTime+".txt";
    file = new QFile(saveSamplePath);
    //ui->label_curPath->setText(saveSamplePath);
//    qDebug()<<strDate<<strTime<<saveSamplePath;

    if(!file->open(QFile::WriteOnly|QFile::Text))
   {
        QMessageBox::warning(this,"warning","cannot open",QMessageBox::Yes);
        this->close();
    }
   out = new QTextStream(file);

   //read config
   // iniFile=new readIni(IniFilePath);
}

void MainWindow::Port1_Init()
{
    //
    if(My_Port1->open(QIODevice::ReadWrite))
    {

        //设置波特率
        My_Port1->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);
        //设置数据位
        My_Port1->setDataBits(QSerialPort::Data8);
        //设置校验位
        My_Port1->setParity(QSerialPort::NoParity);
        //设置停止位
        My_Port1->setStopBits(QSerialPort::OneStop);
        //
        My_Port1->setFlowControl(QSerialPort::NoFlowControl);
        //
        My_Port1->setReadBufferSize(1024);
    }
    else
    {
        QMessageBox::about(NULL, "提示", "串口1没有打开！");
        return;
    }
}

void MainWindow::processPort1()//distance
{

    QByteArray arr_1;

    arr_1=My_Port1->readAll();
    serialPortData.append(arr_1);

    if(serialPortData.size()>=13){
//        qDebug()<<"size="<<serialPortDatA.size()<<"   "<<serialPortDatA.data();
        //this->dis_total[dis_num] = (arr_1.at(4)*256+arr_1.at(5)*1)*65536+(arr_1.at(6)*256+arr_1.at(7)*1);   ////*************
        long long length = ((quint64)(((quint16)serialPortData.at(3)<<8)|serialPortData.at(4))<<16)|(quint64)(((quint16)(serialPortData.at(5)<<8)|(quint8)serialPortData.at(6)));
        dis = length/10000.f;

        switch(flg)
        {
        case 0:
//            qDebug()<<"flg"<<flg;
            ui->lineEdit_3->setText(QString::number(dis));
            break;
        case 1:
//            qDebug()<<"flg"<<flg;
            setZero = length/10000.f;
            qDebug()<<"zero"<< setZero;
            break;
        case 2:
    //      qDebug()<<"flg"<<flg<<dis;
//            qDebug()<<"step_cnt"<<step_cnt;
            dis = dis - setZero;
            dis_total[step_cnt] = dis;    //--ZZ
            if(step_cnt!=0)
            {

                if(dis_total[step_cnt] == dis_total[step_cnt-1])//相同
                {
                    qDebug()<<"相同";
                     qDebug()<<"dis="<<dis<<"pre="<<pre;
                    pre_ave_sec[ave_cnt] = pre;
                    pre_sec_total += pre_ave_sec[ave_cnt];  //累加
                    ave_cnt++;

                    flg_new = true;

                }
                else
                {
                    //qDebug()<<"不相同";
                   if(flg_new == false)                                     //从不同到不同
                   {
                       //qDebug()<<"dis="<<dis<<"pre="<<pre;
                       pre_total_new[step_cnt_new] = pre;
                       dis_total_new[step_cnt_new] = dis;
    //                       qDebug()<<"pre_new:"<< pre_total_new[step_cnt_new]<<""

                   }
                   else if(flg_new == true)                                   //从相同到不同
                   {
                        qDebug()<<"dis="<<dis<<"pre="<<pre;
                        qDebug()<<"pre_sec_total:"<<pre_sec_total;
                       pre_total_new[step_cnt_new] = pre_sec_total/(ave_cnt);
                       dis_total_new[step_cnt_new] = dis_total[step_cnt-1];
                       ave_cnt = 0;
                       pre_sec_total = 0;
                       flg_new = false;

                   }
                   tblWidget();
                   Draw_Customplot();
                   saveData();
                   dis_sqr_total[step_cnt_new] =(dis_total_new[step_cnt_new])*(dis_total_new[step_cnt_new]);      //位移平方
                   dis_pre_total[step_cnt_new] = (dis_total_new[step_cnt_new]) * pre_total_new[step_cnt_new];   //位移乘压力
                   step_cnt_new++;



                }
            }
            else if(step_cnt == 0)
            {
                pre_total_new[0] = pre;
                dis_total_new[0] = dis;
                tblWidget();
                Draw_Customplot();
                saveData();
                dis_sqr_total[step_cnt_new] =(dis_total_new[step_cnt_new])*(dis_total_new[step_cnt_new]);      //位移平方
                dis_pre_total[step_cnt_new] = (dis_total_new[step_cnt_new]) * pre_total_new[step_cnt_new];   //位移乘压力
                step_cnt_new++;

            }




            break;
        case 3:
//            qDebug()<<"flg"<<flg;
            if((!dis==0)&&(!pre_detect==0)) flg_ins = 0;
            else if((!dis==0)&&(pre_detect==0)) flg_ins = 1;
            else if((dis==0)&&(!pre_detect==0)) flg_ins = 2;
            else if((dis==0)&&(pre_detect==0)) flg_ins = 3;

            switch(flg_ins)
            {
            case 0 :QMessageBox::about(NULL,"提示","串口正常, AD正常");break;
            case 1 :QMessageBox::about(NULL,"提示","串口正常, AD无输入");break;
            case 2 :QMessageBox::about(NULL,"提示","串口无输入, AD正常");break;
            case 3 :QMessageBox::about(NULL,"提示","串口无输入, AD无输入");break;
            }

        }

//        qDebug()<<flg;
        serialPortData.clear();
    }
}

void MainWindow::processCurvedata()      //
{


    for(int n=0;n<N;n++)
    {
        pre += pre_ave[n];
    }
    pre = pre/N - pre_zero;
    pre_total[step_cnt] = pre;

    torque =  pre * R;

//    torque_total[step_cnt] = torque;   //力矩


}

void MainWindow::saveData()
{

    currentTime=QTime::currentTime();
    currentDate=QDate::currentDate();
    strDate = currentDate.toString(Qt::ISODate);
    strTime = currentTime.toString("h:m:s");
      (*out)<<strDate<<" ";
      (*out)<<strTime<<"\t";
      (*out)<<QString::number(dis,'f',4)<<" ";
      (*out)<<QString::number(pre,'f',7);
//      (*out)<<QString::number(angle)<<"\t";
//      (*out)<<QString::number(torque)<<"\t";
      (*out)<<"\n";
      out->flush();

}

void MainWindow::sendData_2()
{
    flg = 2;
        QByteArray sendData;
        sendData.resize(8);
        sendData[0] = 0x09;
        sendData[1] = 0x03;
        sendData[2] = 0x00;
        sendData[3] = 0x01;
        sendData[4] = 0x00;
        sendData[5] = 0x04;
        sendData[6] = 0x14;
        sendData[7] = 0x81;
        My_Port1->write(sendData,8);
        My_Port1->waitForBytesWritten();

//        dis_total[dis_num]=(qrand()%100);
//        qDebug()<<"fine";
//        dis_num++;
}

void MainWindow::sendData_1()
{
    flg = 1;
        QByteArray sendData;
        sendData.resize(8);
        sendData[0] = 0x09;
        sendData[1] = 0x03;
        sendData[2] = 0x00;
        sendData[3] = 0x01;
        sendData[4] = 0x00;
        sendData[5] = 0x04;
        sendData[6] = 0x14;
        sendData[7] = 0x81;
        My_Port1->write(sendData,8);
        My_Port1->waitForBytesWritten();

//        dis_total[dis_num]=(qrand()%100);
//        qDebug()<<"distance="<<dis_total[dis_num];
//        dis_num++;
}

void MainWindow::on_pushButton_start_clicked()
{
    if(true==auto_flg){
        if(test_cnt<SHIYANCISHU){
            step_cnt_new = 0;
            timer3->stop();

            step = ui->spinBox->value();
            len = ui->doubleSpinBox_2->value();
            float x = len/mini + 0.5;
            pulse = x;
         //    qDebug()<<len<<mini<<pulse<<x;
            spd = ui->doubleSpinBox_3->value();
            T = (mini/spd)*1000;          //total time   Tmin = 2 SPDmax = 39
            time = T/2;                  //timer interval
            timer->setInterval(time);

            getData_previous();
            openDocument();
            (*out)<<strDate<<" "<<strTime<<"\n";
            out->flush();
            timer->start();

            angle_sum = 0;
            torque_sum = 0;
            angle_torque_sum = 0;
            angle_sqr_sum = 0;
            ui->pushButton_start->setEnabled(false);
            ui->pushButton_Move->setEnabled(false);
            ui->pushButton_stop->setEnabled(false);
            qDebug()<<"it is running now";
        }
        else{
            emit on_pushButton_2_clicked();//dayinliebiao
            Sleep(100);
            auto_flg = false;
            total = 0;
            average = 0;
            ui->pushButton_start->setEnabled(true);
            ui->pushButton_stop->setEnabled(true);
            ui->pushButton_Move->setEnabled(true);
            qDebug()<<"自动实验结束";
        }
    }
    else {
           QMessageBox::StandardButton rb = QMessageBox::question(NULL,"提示","确定要开始实验?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            if(rb ==QMessageBox::Yes )
            {
                 step_cnt_new = 0;
                timer3->stop();

            step = ui->spinBox->value();
            len = ui->doubleSpinBox_2->value();
            float x = len/mini + 0.5;
            pulse = x;
        //    qDebug()<<len<<mini<<pulse<<x;
            spd = ui->doubleSpinBox_3->value();
            T = (mini/spd)*1000;          //total time   Tmin = 2 SPDmax = 39
            time = T/2;                  //timer interval
            timer->setInterval(time);

            getData_previous();
            openDocument();
            (*out)<<strDate<<" "<<strTime<<"\n";
            out->flush();
            timer->start();

            angle_sum = 0;
            torque_sum = 0;
            angle_torque_sum = 0;
            angle_sqr_sum = 0;
            ui->pushButton_start->setEnabled(false);
            ui->pushButton_Move->setEnabled(false);
            ui->pushButton_auto->setEnabled(false);

            qDebug()<<"it is running now";

            }

          }
}

void MainWindow::timer_Start()
{
    timer->start();

}

void MainWindow::timeout()
{


    if((step_cnt < step)&&(pre<ui->doubleSpinBox_4->value()))
    {
        if(pulse_cnt/2 < pulse)
        {
//            qDebug()<<"pulse_cnt:"<<pulse_cnt;
            if(ui->radioButton->isChecked())
            {
//                SetPortVal(0x284,portVal,1);
//                portVal ^= 0x01;//大
                if(portVal==48)                                         //小
                   {
                       portVal=56;
                   SetPortVal(0x284,portVal,1);
//                   qDebug()<<"exp_foward"<<portVal;  //foward,div1   0000->0001

                   }

                else
                   {
                       portVal=48;
                       SetPortVal(0x284,portVal,1);
//                       qDebug()<<"exp_foward"<<portVal;  //foward,div1   0000->0001
                   }

                pulse_cnt++;
            }
            else if(ui->radioButton_2->isChecked())
            {
//                SetPortVal(0x284,portVal,1);
//                portVal ^= 0x02;//大
                if(portVal==40)                                           //小
                    {
                        portVal=32;
                    SetPortVal(0x284,portVal,1);
        //             qDebug()<<"back1: "<<portVal;
                    }
                    else
                    {
                        portVal=40;
                        SetPortVal(0x284,portVal,1);
        //                 qDebug()<<"back2: "<<portVal;
                    }
//                qDebug()<<"test_back"<<portVal;    //back,div1   0000->0010
                pulse_cnt++;
            }
        }
        else
        {
//           qDebug()<<"pulse_cnt:"<<pulse_cnt;
            timer_Pause();
            Sleep(5);
            getData();

        }
    }
    else
    {
//       qDebug()<<"step"<<step_cnt;
       timer_stop();
    }



}

void MainWindow::timeout2()
{

    if(ui->radioButton_foward->isChecked())                         // 正转
    {
//         if(portVal==0x04)                                           //大 div 2  0100->0101  大电机
//            {
//                portVal=0x05;
//            SetPortVal(0x284,portVal,1);

//            }

//         else
//            {
//                portVal=0x04;
//                SetPortVal(0x284,portVal,1);
//            }

//         if(stop_cnt > 40)
//         {
//             emit on_pushButton_sample_clicked();
//             if(pre_detect > 3.5)
//             {
//                 emit on_pushButton_Stopmove_clicked();

//             }
//         }

         if(portVal==48)                                         //小
            {
                portVal=56;
            SetPortVal(0x284,portVal,1);
//            qDebug()<<portVal;
            }

         else
            {
                portVal=48;
                SetPortVal(0x284,portVal,1);
//                qDebug()<<portVal;
            }

         if(stop_cnt > 40)                                          //检测力
         {
             emit on_pushButton_sample_clicked();
             stop_cnt = 0;
             if(pre_detect > 0.25)
             {
                 flg_touched = true;    //接触到了
                 emit on_pushButton_Stopmove_clicked();
//                 emit on_pushButton_start_clicked();

             }
             else{
                 flg_touched = false;   //没接触到
             }
         }

         stop_cnt++;
//         qDebug()<<"stop_cnt "<<stop_cnt;
//        portVal ^= 0x01;
//        portVal &=~0x02;
//        SetPortVal(0x284,portVal,1);
//        qDebug()<<"foward: "<<portVal;
    }

    else if(ui->radioButton_back->isChecked())                      //反转
    {
//        if(portVal==0x04)                                           //大 div 2  0100->0110
//            {
//                portVal=0x06;
//            SetPortVal(0x284,portVal,1);
//            }
//            else
//            {
//                portVal=0x04;
//                SetPortVal(0x284,portVal,1);
//            }

        if(portVal==40)                                           //小
            {
                portVal=32;
            SetPortVal(0x284,portVal,1);
//             qDebug()<<"back1: "<<portVal;
            }
            else
            {
                portVal=40;
                SetPortVal(0x284,portVal,1);
//                 qDebug()<<"back2: "<<portVal;
            }


//        portVal ^= 0x02;
//        portVal &=~0x01;
//        SetPortVal(0x284,portVal,1);

    }

    else
    {
        emit on_pushButton_Stopmove_clicked();
        QMessageBox::warning(this,"warning","没有选择方向",QMessageBox::Yes);
    }
}

void MainWindow::timeout3()
{
    emit on_pushButton_sample_clicked();
    emit on_pushButton_Senddata_clicked();
}

void MainWindow::getData()
{
    step_cnt++;
    pre = 0;
    for(int k=0;k<N;k++)
        {
            Sample();  //采样压力
        }
       pre_num = 0;

       processCurvedata();//process pre
       sendData_2();//采样位移

//    dis_num = 0;


//    Draw_Customplot();
//    tblWidget();
//    saveData();


    timer_Start();

}

void MainWindow::getData_previous()
{

    pre = 0;
    for(int k=0;k<N;k++)
        {
            Sample();  //采样压力
        }
       pre_num = 0;

       processCurvedata();//process pre
       sendData_2();//采样位移

}

void MainWindow::on_pushButton_stop_clicked()
{

    QMessageBox::StandardButton rb =QMessageBox::warning(NULL,"警告","确定终止实验?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb==QMessageBox::Yes)
    {

        pulse_cnt = 0;

    //    flg =false;
        timer->stop();              //停止定时器
        qDebug()<<"it is stop now";
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_Move->setEnabled(true);
        QMessageBox::about(NULL,"提示","实验结束");
    }

}

void MainWindow::timer_stop()
{
     if(true==auto_flg){
         step_cnt = 0;
         pulse_cnt = 0;
         portVal = 0;
     //    flg =false;
         timer->stop();              //停止定时器
         qDebug()<<"it is stop now";
         ui->pushButton_start->setEnabled(true);
         ui->pushButton_Move->setEnabled(true);

         emit on_pushButton_calculate_clicked();

         Sleep(100);
         test_cnt++;
         ui->radioButton_back->setChecked(true);
         emit on_pushButton_Move_clicked();
         Sleep(100);

         flg_touched = false;
         timer_auto->start(2500);//计时完毕后向前移动
         timer_auto_2->start(500);//计时完毕后开始实验

     }
     else
         {
         QMessageBox::about(NULL,"提示","实验结束");
         step_cnt = 0;
         pulse_cnt = 0;
         portVal = 0;
     //    flg =false;
         timer->stop();              //停止定时器
         qDebug()<<"it is stop now";
         ui->pushButton_start->setEnabled(true);
         ui->pushButton_Move->setEnabled(true);
     }


}

void MainWindow::timer_Pause()
{
     pulse_cnt = 0;
     timer->stop();
}


void MainWindow::Sample()
{

    WORD baseAddress = 0x280;
        quint8 channel = 0x00;
        DWORD value[2];
        int timeout=0;
        SetPortVal(baseAddress,channel,1);
        SetPortVal(baseAddress,channel,1);
        for(int i=0;i<7000;i++)
        {

        }
        SetPortVal(baseAddress+1,0,1);
        SetPortVal(baseAddress+1,0,1);


        timeout=0;
        do{
            timeout++;
            GetPortVal (baseAddress+3,value,1);
            if((value[0]&0x80)==0x00) {
//                qDebug()<<"EOC"<<value[0];
                break;
            }
        }while(timeout<100);

        value[0]=0;value[1]=0;
        GetPortVal (baseAddress+2,value,2);
        //single Polar, range from 20
        float volt = ((qint16)((value[0]|(value[1]<<8))&0xfff)-2047.5f)/4096.f*20.;
        pre_ave[pre_num] =  -((volt+0.4)/4.5)*20;
        pre_num++;
//        qDebug()<<value[0]<<"<==>"<<value[1]<<"<==>"<<volt;

//    pre_ave[pre_num]=(qrand()%100);
//    qDebug()<<"pressure="<<pre_ave[pre_num];
//    pre_num++;

}

void MainWindow::Draw_Customplot()
{
    ui->customPlot->graph(0)->addData(dis_total_new[step_cnt_new]*1000,pre_total_new[step_cnt_new]);
    ui->customPlot->graph(0)->setVisible(true);
    ui->customPlot->rescaleAxes(false);
    ui->customPlot->replot();
}

void MainWindow::tblWidget()
{

    ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem(QString::number(dis_total_new[step_cnt_new]*1000)));
    ui->tableWidget->setItem(rowCount,1,new QTableWidgetItem(QString::number(pre_total_new[step_cnt_new])));

    distance_wrong_data_correction[rowCount] = dis;
    pressure_wrong_data_correction[rowCount] = pre;

    ui->label_currentStep->setText(QString::number(rowCount));
    ui->tableWidget->scrollToItem(ui->tableWidget->item(rowCount,0),QAbstractItemView::PositionAtBottom);


    rowCount++;
}


void MainWindow::on_pushButton_calculate_clicked()
{
    down = ui->doubleSpinBox_a->value();
    up = ui->doubleSpinBox_b->value();

    QString filename = "C:/Users/Administrator/Desktop/Em2018.3.26/Em2018.1.16/Em2018.1.14/Em/sti_makeup";

    QFile file(filename);
    QTextStream textStream(&file);
    QString sti_makeup_str;
    double sti_makeup_dbl;
       if (file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           sti_makeup_str = textStream.readAll();
           sti_makeup_dbl =  sti_makeup_str.toDouble();
//           qDebug()<<"sti_makeup:"<<sti_makeup_dbl;

       }

       else    //---打开文件失败
       {
//           QMessageBox ::information(NULL, NULL, "调取补偿刚度失败");
       }




//    qDebug()<<"step"<<step;
    dis_sum = 0;
    pre_sum = 0;
    dis_pre_sum = 0;
    dis_sqr_sum = 0;
      angle_sum = 0;
      torque_sum = 0;
      angle_torque_sum = 0;
      angle_sqr_sum = 0;

    int start_position = ui->spinBox_sti_startNum->value();  //选择排除前几个数值,排除掉飞值
    int real_step = step_cnt_new-start_position;

    qDebug()<<"step_cnt:"<<step_cnt<<"real step:"<<real_step;


    for( int i = start_position; i<rowCount; i++){

          dis_sum+=dis_total_new[i];
          pre_sum+=pre_total_new[i];
          dis_pre_sum+=dis_pre_total[i];
          dis_sqr_sum+=dis_sqr_total[i];

//        dis_sum+=distance_wrong_data_correction[i];
//        pre_sum+=pressure_wrong_data_correction[i];
//        dis_pre_sum+=distance_wrong_data_correction[i]*pressure_wrong_data_correction[i];
//        dis_sqr_sum+=distance_wrong_data_correction[i]*distance_wrong_data_correction[i];
        //qDebug()<<"dis_corr"<<distance_wrong_data_correction[i]<<"pre_corr"<<pressure_wrong_data_correction[i];
    }


    k_test =  (real_step*dis_pre_sum-dis_sum*pre_sum)/(real_step*dis_sqr_sum-dis_sum*dis_sum);//实测斜率
    b = pre_sum/real_step-(k_test)*((dis_sum)/real_step);
    sti_test = ((real_step*(dis_pre_sum/1000)-(dis_sum/1000)*pre_sum)/(real_step*(dis_sqr_sum/1000000)-(dis_sum/1000)*(dis_sum/1000)))/1000000;//实测刚度
    total += sti_test;
    average = total/(test_cnt+1);

    sti = (sti_test*sti_makeup_dbl)/(sti_makeup_dbl-sti_test);//补偿后刚度
    k = sti*1000;//补偿后斜率

//    qDebug()<<"sti"<<sti<<"b"<<b<<"sti_makeup"<<sti_makeup_dbl<<"sti_test"<<sti_test;

//    if(ui->radioButton_a->isChecked())
//    {

//       ui->lineEdit->setText(QString::number(sti).left(8));

//       if(sti>down&&sti<up)  QMessageBox::about(NULL,"提示","刚度达标");
//       if(sti<down||sti>up)  QMessageBox::about(NULL,"提示","刚度未达标");

//       double x[2] ={0,dis*1000};           //曲线拟合
//       double y[2];
//       for(int i = 0;i<2;i++)
//       {

//           y[i] = (sti)*x[i]+(b);

//           ui->customPlot->graph(1)->addData(x[i],y[i]);
//           ui->customPlot->replot();

//       }
//    }
//    else if(ui->radioButton_a_2->isChecked())
//    {
       ui->lineEdit->setText(QString::number(average).left(8));
       qDebug()<<"\033[35m"<<"zhenshizhi:"<<sti_test<<"\033[0m";


       if(average>down&&average<up)  MessageFunc(NULL,"提示","刚度");
       if(average<down||average>up)  MessageFunc(NULL,"提示","刚度未达标");

       double x[2] ={0,dis*1000};           //曲线拟合
       double y[2];
       for(int i = 0;i<2;i++)
       {
           y[i] = (sti_test)*x[i]+(b);
           //ui->customPlot->graph(1)->addData(x[i],y[i]);
           //ui->customPlot->replot();
       }
       //重新划线
       QVector<double> xxV,yyV;
        xxV.push_back(x[0]);
        xxV.push_back(x[1]);
        yyV.push_back(y[0]);
        yyV.push_back(y[1]);
        qDebug()<<"xxV:"<<xxV;
        qDebug()<<"yyV"<<yyV;
        ui->customPlot->graph(1)->setData(xxV,yyV);
        ui->customPlot->rescaleAxes(true);
        ui->customPlot->replot();

//    }

    (*out)<<average<<" ";
    (*out)<<sti<<"\t";                    //刚度值存盘
    (*out)<<b;
    out->flush();

}

void MainWindow::on_pushButton_clear_clicked()         //清空图表
{
//    QMessageBox::StandardButton rb = QMessageBox::warning(NULL,"警告","确定要清除图表吗?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
//    if(rb == QMessageBox::Yes)
//    {
    ui->customPlot->clearGraphs();
    ui->tableWidget->clearContents();
    //ui->customPlot->addGraph(0);
    //ui->tableWidget->clearContents();
    QCP_Init();
    ui->customPlot->replot();
    //ui->tableWidget->clear();

    rowCount=0;
//    }
//    else
//    {

//    }


}


void MainWindow::SetDo_Low()
{
    SetPortVal(DO_ADDRESS,DO_LOW,1);
}

void MainWindow::SetDo_High()
{
    SetPortVal(DO_ADDRESS,DO_HIGH,1);
}

void MainWindow::on_pushButton_Stopmove_clicked()
{
    portVal = 0;
    timer2->stop();
    qDebug()<<"move is stop now";
    ui->pushButton_Move->setEnabled(true);
    ui->pushButton_start->setEnabled(true);
    qcw.m_state = false;
    update();


}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    time2 = value;
    timer2->setInterval(time2);

}

void MainWindow::on_pushButton_Move_clicked()
{
    if(true==auto_flg){
        timer2->start(1);
        qDebug()<<"move now"<<time2;
        ui->pushButton_Move->setEnabled(false);
        ui->pushButton_start->setEnabled(false);
        qcw.m_state = true;
        update();
    }
    else
    {


//    QMessageBox::StandardButton rb =QMessageBox::question(NULL,"提示","确定要移动?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
//    if(rb == QMessageBox::Yes)
//    {
        timer2->start(1);
        qDebug()<<"move now"<<time2;
        ui->pushButton_Move->setEnabled(false);
        ui->pushButton_start->setEnabled(false);
        qcw.m_state = true;
        update();
//    }

    }

}



void MainWindow::on_pushButton_sample_clicked()
{  
        detect_cnt = 0;
        pre_detect = 0;
        for(int i=0;i<N;i++)
        {
            Sample_clicked();
        }
        for(int n=0;n<N;n++)
        {
            pre_detect += pre_detect_ave[n];
        }
        pre_detect = pre_detect/N ;
        if(pre_flg == false)
        {
//            qDebug()<<pre_flg;
            ui->lineEdit_2->setText(QString::number(pre_detect));
        }
        else
        {
//            qDebug()<<pre_flg;
            pre_detect = pre_detect - pre_zero;
            ui->lineEdit_2->setText(QString::number(pre_detect).left(8));
        }


//    pre_ave[pre_num]=(qrand()%100);          //*****************************
//    qDebug()<<"pressure="<<pre_ave[pre_num];

}

void MainWindow::Sample_clicked()
{
    WORD baseAddress = 0x280;
        quint8 channel = 0x00;
        DWORD value[2];
        int timeout=0;
        SetPortVal(baseAddress,channel,1);
        SetPortVal(baseAddress,channel,1);
        for(int i=0;i<7000;i++){}
        SetPortVal(baseAddress+1,0,1);
        SetPortVal(baseAddress+1,0,1);


        timeout=0;
        do{
            timeout++;
            GetPortVal (baseAddress+3,value,1);
            if((value[0]&0x80)==0x00) {
//                qDebug()<<"EOC"<<value[0];
                break;
            }
        }while(timeout<100);

        value[0]=0;value[1]=0;
        GetPortVal (baseAddress+2,value,2);
        //single Polar, range from 20
        float volt = ((qint16)((value[0]|(value[1]<<8))&0xfff)-2047.5f)/4096.f*20.;

        pre_detect_ave[detect_cnt] = -((volt+0.4)/4.5)*20;
        detect_cnt++;

//        qDebug()<<value[0]<<"<==>"<<value[1]<<"<==>"<<volt;
}

void MainWindow::on_pushButton_Senddata_clicked()
{
    flg = 0;
    QByteArray sendData;
    sendData.resize(8);
    sendData[0] = 0x09;
    sendData[1] = 0x03;
    sendData[2] = 0x00;
    sendData[3] = 0x01;
    sendData[4] = 0x00;
    sendData[5] = 0x04;
    sendData[6] = 0x14;
    sendData[7] = 0x81;
    My_Port1->write(sendData,8);
    My_Port1->waitForBytesWritten();

    //dis_total[dis_num]=My_Port1->readAll();   //**********************************
    //qDebug()<<"distance="<<dis_total[dis_num];
}

void MainWindow::sendData_3()
{
    flg = 3;
    QByteArray sendData;
    sendData.resize(8);
    sendData[0] = 0x09;
    sendData[1] = 0x03;
    sendData[2] = 0x00;
    sendData[3] = 0x01;
    sendData[4] = 0x00;
    sendData[5] = 0x04;
    sendData[6] = 0x14;
    sendData[7] = 0x81;
    My_Port1->write(sendData,8);
    My_Port1->waitForBytesWritten();
}



void MainWindow::on_pushButton_clicked()
{
    sendData_1();//位置标定
}

void MainWindow::inspect()
{
    on_pushButton_sample_clicked();
    sendData_3();
}

void MainWindow::review()
{
    QString filename=QFileDialog::getOpenFileName(
                this,//父窗口
                "open file dialog",//对话框标题
                "/",//默认的选中文件
                "txt files(*.txt)");//文件过滤

    //---打开文件并读取文件内容
    QFile file(filename);

    QTextStream textStream(&file);
    QString line_Str;
    QString A;
    QString B;

    double varA;
    double varB;
    QString sti_review;
    QString sti_test_review;
    QString b_review;
    QString time_review;
    //--打开文件成功
       if (file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           int rowCount_2 = 0;
           time_review = textStream.readLine();
           ui->label_10->setText(time_review);
           while (!textStream.atEnd())
           {
               A.clear();
               B.clear();
               line_Str = textStream.readLine();
//               qDebug()<<"line:"<<line_Str;
               if(line_Str.length()>30){    //不是刚度值
                   int pos=0;
                   //get A
                   for(pos=0;pos<line_Str.length();pos++){
                       if(line_Str[pos]=='\t'){
                           pos++;
                           for(;pos<line_Str.length();pos++){  //found '\t'
                              if(line_Str[pos]!=' '){
                                  A+=line_Str[pos];
                              }
                              else{     //found 'space'
                                  break;
                              }
                           }
                           break;   //escape
                       }
                   }
                   //get B
                   B=line_Str.mid(pos+1);
                   //A = line_Str.mid(20,7);
                   //B = line_Str.mid(28,9);
                   varA = A.toDouble();  //取出位移
                   varB = B.toDouble(); //取出压力
//                   qDebug()<<"varA="<<varA<<"   varB="<<varB<<"  A:"<<A<<"  B:"<<B;

                   ui->customPlot_review->graph(0)->addData(varA,varB);
                   ui->customPlot_review->graph(0)->setVisible(true);
                   ui->customPlot_review->rescaleAxes(true);
                   ui->customPlot_review->replot();

                   ui->tableWidget_2->setItem(rowCount_2,0,new QTableWidgetItem(QString::number(varA)));
                   ui->tableWidget_2->setItem(rowCount_2,1,new QTableWidgetItem(QString::number(varB)));

                   rowCount_2++;
               }
               else{    //刚度值
                   int pos = 0;
                   for(pos=0;pos<line_Str.length();pos++)
                   {
                       if(line_Str[pos] == ' ')                 //foune space
                       {
                           sti_test_review = line_Str.mid(0,pos-1);//sti_test
                           pos++;
                           for(;pos<line_Str.length();pos++)
                           {
                               if(line_Str[pos]!= "\t")        //found /t
                               {
                                   sti_review+=line_Str[pos];           //sti
                               }
                               else
                               {

                                    break;

                               }
                           }

                           b_review = line_Str.mid(pos+1);

                       }


                   }



//                   qDebug()<<"sti_review"<<sti_review;
                   ui->label_11->setText(sti_test_review);

                   }

               }

           double sti_review_dbl = sti_review.toDouble() * 1000;
           double sti_test_review_dbl = sti_test_review.toDouble() *1000;
           double b_review_dbl = b_review.toDouble();
          qDebug()<<"bb"<<sti_review_dbl<<" "<<b_review_dbl;

           double x[2] ={0,varA};           //曲线拟合
           double y[2];
           for(int i = 0;i<2;i++)
           {
//               qDebug()<<i;
               y[i] = (sti_test_review_dbl)*x[i]+(b_review_dbl);

               ui->customPlot_review->graph(1)->addData(x[i],y[i]);
               ui->customPlot_review->replot();

           }

       }
       else    //---打开文件失败
       {
           QMessageBox ::information(NULL, NULL, "打开文件失败");
       }

}

void MainWindow::instruction()
{
    B.show();
}

void MainWindow::about()
{

    A.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    A.row_list++;
    QString Tips;
    QString sti_s = QString::number(average);

    if(average>=down&&average<=up) Tips = "是";
    else Tips = "否";

    A.str_head="<html> \
            <body> \
            <h1>刚度试验测试 时间:"+QDate::currentDate().toString(Qt::ISODate)+"</h1> \
            <table border=\"1\" style=\"font-size:20px\"> \
            <tr> \
             <th>序号</th> \
             <th>刚度值</th> \
             <th>合格</th>\
             </tr>";

    A.p_str.append("<tr>\
                   <td>"+QString::number(A.row_list)+"</td>\
                   <td>"+sti_s+"</td>\
                   <td>"+Tips+"</td>\
                   </tr>"
                  );

    A.str_end = "</table>\
                <p>附：测量值范围："+QString::number(ui->doubleSpinBox_a->value())+"~"+QString::number(ui->doubleSpinBox_b->value())+"</p>\
                </body>\
                </html>";

    A.setHtml_func();
}


void MainWindow::on_pushButton_3_clicked()
{
    pre_flg =false;
    emit on_pushButton_sample_clicked();
    pre_flg =true;
    pre_zero = pre_detect;
    qDebug()<<"pre_zero"<<pre_zero;

}

void MainWindow::on_pushButton_4_clicked()
{
    timer3->start(500);


}

void MainWindow::on_pushButton_5_clicked()
{
    timer3->stop();

}

void MainWindow::correctsti()
{
    correct.show();
}

//void MainWindow::quitAll()
//{

//}

void MainWindow::on_pushButton_6_clicked()
{
    QString p_str =A.str_head + A.p_str + A.str_end; // "<html>                 <body>                 <h4>&nbsp;刚度试验测试 时间:2018-04-26</h4>                 <table border=\"1\" style="font-size:24px" style="font-size:24px">                 <tr>                  <th>实验序号</th>                  <th>刚度值</th>                  <th>合格</th>                 </tr><tr>                   <td>1</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>2</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>3</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>4</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>5</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>6</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>7</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>8</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>9</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>10</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>11</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>12</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>13</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>14</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>15</td>                   <td>0</td>                   <td></td>                   </tr><tr>                   <td>16</td>                   <td>-0.0947463</td>                   <td>否</td>                   </tr><tr>                   <td>17</td>                   <td>-0.0947463</td>                   <td>否</td>                   </tr></table>                <p>附：测量值范围：0~0</p>                </body>                </html>";
    QTextDocument *ab = new QTextDocument();
    ab->setHtml(p_str);
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec())
    {
        QTextDocument *doc(ab);//ui->textEdit->document();
        doc->print(&printer);
    }
}

void MainWindow::on_pushButton_auto_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::question(NULL,"提示","确定要开始自动实验?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
     if(rb ==QMessageBox::Yes )
     {
        SHIYANCISHU = ui->spinBox_auto->value();
        auto_flg = true;
        total = 0;
        average = 0;
        test_cnt = 0;
//        emit on_pushButton_clicked();
//        Sleep(2000);
        emit on_pushButton_start_clicked();
     }
}

void MainWindow::timer_auto_out()
{
     emit on_pushButton_clear_clicked();
    ui->radioButton_foward->setChecked(true);
    timer_auto->stop();
}

void MainWindow::timer_auto_out_2()
{
    if(flg_touched==true){
        emit on_pushButton_start_clicked();
        flg_touched = false;
        timer_auto_2->stop();
    }
}

void MainWindow::MessageFunc(int* _, QString str1,QString str2)
{
    if(auto_flg==true){

    }
    else{
        QMessageBox::about(NULL,str1,str2);
    }
}

void MainWindow::mengding_out()
{
//        qDebug()<<"stop_cnt_2:"<<stop_cnt_2;
        if(portVal==48)                                         //小
            {
                portVal=56;
            SetPortVal(0x284,portVal,1);
//            qDebug()<<portVal;
            }

         else
            {
                portVal=48;
                SetPortVal(0x284,portVal,1);
//                qDebug()<<portVal;
            }

         if(stop_cnt_2 > 40)                                          //检测力
         {
             emit on_pushButton_sample_clicked();
             stop_cnt_2= 0;
             if(pre_detect > 4.7)
             {
                 mengding->stop();//当大于5时,停止前进
                 houtui->start(1);//后退
                 QTimer::singleShot(5000,this,SLOT(jishi_out())); //计时倒退时间

             }
             else{

             }
         }

         stop_cnt_2++;

}

void MainWindow::houtui_out()
{
//    qDebug()<<"back!!!";
    if(portVal==40)
       {
           portVal=32;
       SetPortVal(0x284,portVal,1);

       }
       else
       {
           portVal=40;
           SetPortVal(0x284,portVal,1);
       }
}

void MainWindow::jishi_out()
{
    mengding_cnt++;
    qDebug()<<mengding_cnt;
    houtui->stop(); //停止后退
    if(mengding_cnt < ui->spinBox_mengding->value())//判断是否前进
    {
        mengding->start(2);
    }
    else
    {
        mengding_cnt = 0;
        qDebug()<<"its over";
    }
}

void MainWindow::on_pushButton_mengding_clicked()
{
    mengding_cnt = 0;
    stop_cnt = 0;
    qDebug()<<"start";
    mengding->start(2);//前进
}
