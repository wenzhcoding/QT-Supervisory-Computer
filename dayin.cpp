#include "dayin.h"
#include "ui_dayin.h"
#include <QMessageBox>
#include <QTime>
#include <QDate>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
 static QTextDocument *a = new QTextDocument();

dayin::dayin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dayin)
{
    ui->setupUi(this);
    this->setWindowTitle("打印浏览");

    ui->textEdit->setTextInteractionFlags(0);

        str_head="<html> \
                <body> \
                <h1>刚度试验测试 时间:"+QDate::currentDate().toString(Qt::ISODate)+"</h1> \
                <table border=\"1\" style=\"font-size:20px\"> \
                <tr> \
                 <th>序号</th> \
                 <th>刚度值</th> \
                 <th>合格</th>\
                 </tr>";

    p_str.clear();

    str_end = "</table>\
                <p>附：测量值范围：</p>\
                </body>\
                </html>";

    setHtml_func();

}

dayin::~dayin()
{
    delete ui;

}

void dayin::printHtml(QTextDocument *html)
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec())
    {
        QTextDocument *doc(html);//ui->textEdit->document();
        doc->print(&printer);
    }
}

void dayin::on_pushButton_clicked()
{
     a->setHtml(str_head+p_str+str_end);
     a->setHtml(p_str);
     printHtml(a);
}

void dayin::setHtml_func()
{
     ui->textEdit->document()->setHtml(str_head+p_str+str_end);//显示打印内容
}

void dayin::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::question(NULL,"提示","确定要清空列表?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
     if(rb ==QMessageBox::Yes )
     {
         row_list = 0;
         p_str.clear();
         setHtml_func();
     }
}
