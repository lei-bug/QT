#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSize>
#include <QDebug>
#include "subwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QPushButton *button1;
    subwidget w2;

public slots:
    void MChange();
    void subChange();

};

#endif // WIDGET_H
