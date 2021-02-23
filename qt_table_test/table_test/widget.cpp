#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QTableView *parent) :
    QTableView(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setItem(0, 0, new QStandardItem("Mr.zhang"));
    model->setItem(0, 1, new QStandardItem("3"));
    model->setItem(0, 2, new QStandardItem("man"));
    model->setItem(1, 0, new QStandardItem("score"));
    this->setModel(model);//

    /*设置列字段名*/
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal, "name");
    model->setHeaderData(1,Qt::Horizontal, "age");
    model->setHeaderData(2,Qt::Horizontal, "sex");

    /*设置行字段名*/
    model->setRowCount(3);
    model->setHeaderData(0,Qt::Vertical, "num1");
    model->setHeaderData(1,Qt::Vertical, "num2");
    model->setHeaderData(2,Qt::Vertical, "num3");

   // model->removeRow(0);//移除第0行数据
   // model->removeColumn(0);//移除第0列数据

    //插入一行数据
    QList<QStandardItem*> list;
    list << new QStandardItem("Mr.wang") << new QStandardItem("22") << new QStandardItem("man");
    model->insertRow(0, list); //在第0行插入一条记录

    //清除所有数据及表头
    //model->clear();

    //插入一行数据
    QList<QStandardItem*> list1;
    list1 << new QStandardItem("Mr.liu") << new QStandardItem("20") << new QStandardItem("man");
     model->appendRow( list1);
}

Widget::~Widget()
{
    delete ui;
}
