#ifndef WIDGET_H
#define WIDGET_H

#include <QTableView>
#include <QStandardItemModel>
#include<QList>

namespace Ui {
class Widget;
}

class Widget : public QTableView
{
    Q_OBJECT

public:
    explicit Widget(QTableView *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
