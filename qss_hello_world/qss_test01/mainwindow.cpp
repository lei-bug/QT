#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet(QString("QPushButton{color:rgb(255,0,0)}" ));

//    QFile qss("/home/qtcode/gui_test/qss_hello_world/qss_test01/StyleSheet.qss");//绝对路径
//    QFile qss("StyleSheet.qss");
        QFile qss(":/qss/StyleSheet.qss");//资源文件，相对路径

    //判断文件是否存在
    if (!qss.exists()){
        qDebug() << "file doesn't exist"<< endl;
    }

    if (qss.open(QIODevice::ReadOnly)){
         qDebug() << "open succeed"<< endl;
    }

    ui->pushButton_3->setStyleSheet(qss.readAll());
    qDebug() << qss.readAll() << endl;
    qDebug() << "hello world"<< endl;
    qss.close();

}


MainWindow::~MainWindow()
{
    delete ui;
}
