#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}



Widget::~Widget()
{
    delete ui;
}

void Widget::get_sti()
{
     sti_std = ui->doubleSpinBox->value();
     sti_real = ui->doubleSpinBox_2->value();
     sti_makeup = (sti_std * sti_real)/(sti_std - sti_real);
}

void Widget::on_pushButton_2_clicked()
{    
    qfile = new QFile("C:/Users/Administrator/Desktop/Em2018.1.19/Em2018.1.16/Em2018.1.14/Em/sti_makeup");

    if(!qfile->open(QFile::WriteOnly|QFile::Text))
   {
        QMessageBox::warning(this,"warning","cannot open",QMessageBox::Yes);
        this->close();
    }


   out_sti = new QTextStream(qfile);

   (*out_sti)<<sti_makeup;
   out_sti->flush();

}

void Widget::on_pushButton_clicked()
{
    get_sti();
    qDebug()<<"sti_makeup:"<<sti_makeup;
    ui->doubleSpinBox_1->setValue(sti_makeup);
}
