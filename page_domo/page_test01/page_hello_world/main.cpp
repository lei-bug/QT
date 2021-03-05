#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile qss(":/qss/a.qss");//资源文件，相对路径
//判断文件是否存在
if (!qss.exists()){
    qDebug() << "file doesn't exist"<< endl;
}
if (qss.open(QIODevice::ReadOnly)){
     qDebug() << "open succeed"<< endl;
}
a.setStyleSheet(qss.readAll());
qDebug() << "hello world"<< endl;
qss.close();

    return a.exec();
}
