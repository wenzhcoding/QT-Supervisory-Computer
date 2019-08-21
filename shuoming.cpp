#include "shuoming.h"
#include "ui_shuoming.h"

shuoming::shuoming(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shuoming)
{
    ui->setupUi(this);
    this->setWindowTitle("使用说明");
}

shuoming::~shuoming()
{
    delete ui;
}
