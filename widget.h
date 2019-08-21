#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    double sti_makeup;

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    void get_sti();
    double sti_std;
    double sti_real;
    QFile *qfile;
    QTextStream *out_sti;

};

#endif // WIDGET_H
