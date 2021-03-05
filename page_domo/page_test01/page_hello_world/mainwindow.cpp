#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowFlags(Qt::FramelessWindowHint);
     ui->qwtPlot_power->setAxisScale(QwtPlot::yLeft, -40.0, 10.0);
     ui->qwtPlot_power->enableAxis(ui->qwtPlot_power->xBottom,false);
     ui->qwtPlot_power->setAxisTitle(QwtPlot::yLeft, "signal strength");

     ui->qwtPlot_byte->setAxisScale(QwtPlot::yLeft, 0.0, 10.0);
     ui->qwtPlot_byte->enableAxis(ui->qwtPlot_byte->xBottom,false);
     ui->qwtPlot_byte->setAxisTitle(QwtPlot::yLeft, "Byte(KB/s)");

     curvepower = new QwtPlotCurve("Power");
     curvebyte = new QwtPlotCurve("Byte");
     double time[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,10.0};
     memset(val,0,sizeof(val));
     memset(val_power,0,sizeof(val_power));

     settimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDataChart(){
        double time[10] = {0.0,1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        for (int i = 0; i < 9; i++) {
            val[i] = val[i+1];
        }
        for (int i = 0; i < 9; i++) {
            val_power[i] = val_power[i+1];
        }
        init_val();
        curvebyte->setSamples(time, val, 10);
        curvebyte->attach(ui->qwtPlot_byte);
        ui->qwtPlot_byte->replot();

        curvepower->setSamples(time, val_power, 10);
        curvepower->attach(ui->qwtPlot_power);
        ui->qwtPlot_power->replot();

     }

void MainWindow::settimer(){
         triggerTimer(1000);
     }

void MainWindow::triggerTimer(int ms){
          updateDataChart();
          timer = new QTimer(this);
          //新建定时器
          connect(timer,SIGNAL(timeout()),this,SLOT(updateDataChart()));
          //关联定时器计满信号和相应的槽函数
          timer->start(ms);
          //定时器开始计时，其中1000表示1000ms即1秒

     }

void MainWindow::init_val(){
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    int n_val = qrand()%10;
    val[9] = n_val;
    n_val = qrand()%50;
    val_power[9] = 10-n_val;


 }

void MainWindow::readqss(){

  }
