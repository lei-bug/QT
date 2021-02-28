#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSize>
#include <QDebug>

class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = 0);

    QPushButton *button2;


signals:
    void mysignal();

public slots:
     void send_mysignal();

};

#endif // SUBWIDGET_H
