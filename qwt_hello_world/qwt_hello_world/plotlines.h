#ifndef PLOTLINES_H
#define PLOTLINES_H

#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>


class PlotLines : public QwtPlot
{
    Q_OBJECT
public:
    explicit PlotLines(QWidget *parent = 0);
    QwtPlotCanvas *canvas;
    QwtPlotGrid *grid ;
    QwtPlotCurve *curve1;
    QwtPlotCurve *curve2;
    QwtSymbol *symbol;
    QPolygonF points1, points2;//输入节点数据QPointF(x,y)

signals:

public slots:

};

#endif // PLOTLINES_H
