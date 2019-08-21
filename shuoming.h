#ifndef SHUOMING_H
#define SHUOMING_H

#include <QWidget>

namespace Ui {
class shuoming;
}

class shuoming : public QWidget
{
    Q_OBJECT

public:
    explicit shuoming(QWidget *parent = 0);
    ~shuoming();

private:
    Ui::shuoming *ui;
};

#endif // SHUOMING_H
