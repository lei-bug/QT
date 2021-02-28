#include "widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(500,500);
    button1 = new QPushButton(this);
    button1->setIcon(QIcon(":/button/images/lastPage.png"));
    button1->setIconSize(QSize(80,50));
    button1->move(50,200);

    connect (button1,SIGNAL(released()),this,SLOT(MChange()) );
    connect(&w2,SIGNAL(mysignal()),this,SLOT(subChange()));


}

Widget::~Widget()
{

}

void Widget::MChange(){
        qDebug() << "this is Mchange()"<< endl;
         this->hide();
         w2.setWindowTitle("this is No.2");
         w2.show();

    }
void Widget::subChange(){
        qDebug() << "this is subchange()"<< endl;
         this->show();
         w2.hide();

    }
