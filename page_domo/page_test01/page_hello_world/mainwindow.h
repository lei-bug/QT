#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwt_plot_curve.h>
#include <QDebug>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QwtPlotCurve *curvepower;
    QwtPlotCurve *curvebyte;
    double time[10] ;
    double val[10] ;
    double val_power[10];
    void settimer();
    void triggerTimer(int ms);
    void init_val();
    QTimer *timer;
    void readqss();

private slots:
    void updateDataChart();

};

#endif // MAINWINDOW_H
