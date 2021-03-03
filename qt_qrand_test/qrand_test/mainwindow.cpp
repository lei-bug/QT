#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QDebug>
#include <QTimer>
#include<QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //关联定时器计满信号和相应的槽函数
    timer->start(1000);
    //定时器开始计时，其中1000表示1000ms即1秒

 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpDate()
{

    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    int n = qrand()%10;
    qDebug() << n << endl;
}

