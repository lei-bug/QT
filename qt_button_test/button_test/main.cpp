#include "widget.h"
#include <QApplication>
#include <subwidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w1;
    w1.setWindowTitle("this is No.1");
    w1.show();

//    subwidget w2;
//    w2.setWindowTitle("this is No.2");
//    w2.show();


    return a.exec();
}
