#ifndef DAYIN_H
#define DAYIN_H

#include <QWidget>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>

namespace Ui {
class dayin;
}

class dayin : public QWidget
{
    Q_OBJECT

public:
    explicit dayin(QWidget *parent = 0);
    ~dayin();
    QString p_str;
    QString str_head;
    QString str_end;
    int row_list = 0;
    void setHtml_func();
//    static QTextDocument *a ;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dayin *ui;
    void printHtml(QTextDocument *html);



};

#endif // DAYIN_H
