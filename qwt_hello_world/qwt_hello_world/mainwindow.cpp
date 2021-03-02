#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    line1 = new PlotLines;
    line1->setParent(this);
    line1->setTitle("LIne 1");
    line1->setGeometry(0,20,400,200);//setGeometry(int x, int y, int w, int h)

    line2 = new PlotLines;
    line2->setParent(this);
    line2->setTitle("LIne 2");
    line2->setGeometry(0,250,400,200);//setGeometry(int x, int y, int w, int h)




//    line2.setParent(this);
//    line2.setTitle("LIne 2");
}

MainWindow::~MainWindow()
{
    delete ui;
}
