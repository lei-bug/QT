#include "subwidget.h"

subwidget::subwidget(QWidget *parent) :
    QWidget(parent)
{
    this->resize(500,500);
    button2 = new QPushButton(this);
    button2->setIcon(QIcon(":/button/images/return.png"));
    button2->setIconSize(QSize(80,50));
    button2->move(350,200);

    connect (button2,SIGNAL(released()),this,SLOT(send_mysignal()));
}

void subwidget::send_mysignal(){
    emit mysignal();
}

