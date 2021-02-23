#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建菜单
    QMenuBar *menubar = menuBar();//menuBar()是MainWindow的成员函数，它返回一个MenuBar
    QMenu *file = menubar->addMenu("&File");
    QMenu *help = menubar->addMenu("&Help");

//要添加菜单的内容，就要使用QAction对象了。
//QAction是一个动作，它不但可以添加到菜单，还可以添加到工具栏。
//大多数类的构造函数都接受一个parent参数，表示它的父控件。如果为0表示没有父控件，是一个顶级的控件
    QAction *openAction = new QAction(QIcon(":/Action/Image/file.jpg"),"&Open", this);
    file->addAction(openAction);
    QAction *saveAction = new QAction(QIcon(":/Action/Image/save.jpg"),"&Save", this);
    file->addAction(saveAction);

    QAction *aboutAction = new QAction("&about",this);
    help -> addAction(aboutAction);

//创建工具栏
    QToolBar *toolBar = addToolBar("Toolbar");
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(aboutAction);

//添加编辑区域
    textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    connect(openAction, SIGNAL(triggered()), this, SLOT(openfile()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(savefile()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openfile(){
    qDebug() << "openfile";
    QString path = QFileDialog::getOpenFileName(
                this,   //父窗口
                tr("Open File"),    //对话框名字
                ".",    //默认目录 . 表示当前目录
                tr("Text Files(*.txt);;ini File(*.ini)") //过滤器 只打开txt类型 或 ini 使用;;分隔
                );

if (!path.isEmpty())
    {
            //qDebug() << path;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return; //打开失败
        }
    QTextStream in(&file);
    textedit->setText(in.readAll());
    file.close();
    }

}

void MainWindow::savefile(){
    qDebug() << "savefile";
    QString path = QFileDialog::getSaveFileName(
                   this,   //父窗口
                   tr("Open File"),    //对话框名字
                   ".",    //默认目录
                   tr("Text Files(*.txt);;ini File(*.ini)") //过滤器 只打开txt类型 或 ini 使用;;分隔
                   );
       if (!path.isEmpty())
       {
           QFile file(path);
           if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
               return; //打开失败

           QTextStream out(&file);
           out << textedit->toPlainText();

           file.close();
       }

}



