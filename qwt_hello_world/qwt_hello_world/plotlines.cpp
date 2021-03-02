#include "plotlines.h"

PlotLines::PlotLines(QWidget *parent) :
    QwtPlot(parent)
{

    //---------设置画布---------//
        canvas=new QwtPlotCanvas();
        canvas->setPalette(Qt::gray);//调试板
//        canvas->setBorderRadius(0);//边界半径
        setCanvas( canvas );//启用画布
//        plotLayout()->setAlignCanvasToScale(true);//画布与表一体


        //-----------设置x，y坐标和范围--------------//
        setAxisTitle( QwtPlot::yLeft, "ylabel" );//左y轴名
        setAxisTitle( QwtPlot::xBottom, "xlabel" );
        setAxisScale(QwtPlot::yLeft,0.0,10.0);//y轴左,0到10
        setAxisScale(QwtPlot::xBottom,0.0,10.0);//


        //----------------设置栅格线-------------------//
        grid = new QwtPlotGrid;
        grid->enableX( true );//垂直线开启,设置网格线
        grid->enableY( true );//水平线开启
        grid->setMajorPen( Qt::black, 0, Qt::DotLine );//网格画笔风格
        grid->attach( this );//设置依附的图表


        //-----------------开始画图----------------------//
        curve1=new QwtPlotCurve("curve");
       // curve->setTitle( "信道"+QString( "%1 " ).arg( i+1));
        curve1->setPen(Qt::blue,2);//设置曲线颜色 粗细
        curve1->setRenderHint(QwtPlotItem::RenderAntialiased,true);//线条光滑化

        curve2=new QwtPlotCurve("curve");
       // curve->setTitle( "信道"+QString( "%1 " ).arg( i+1));
        curve2->setPen(Qt::yellow,2);//设置曲线颜色 粗细
        curve2->setRenderHint(QwtPlotItem::RenderAntialiased,true);//线条光滑化


        symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 4, 4) );//设置样本点的颜色、大小
        curve1->setSymbol( symbol );//添加样本点形状
        curve2->setSymbol( symbol );

        //---------------  描点-----------------//
//        QPolygonF points1, points2;//输入节点数据QPointF(x,y)
        points1<<QPointF(1,1)<<QPointF(2,2)<<QPointF(3,3)<<QPointF(4,4)<<QPointF(5,5)<<QPointF(6,6)<<QPointF(7,7);
        points2<<QPointF(6,2)<<QPointF(2,3)<<QPointF(3,4)<<QPointF(4,5)<<QPointF(5,6)<<QPointF(6,7)<<QPointF(7,8);
        curve1->setSamples(points1);//初始化数据(容器)
        curve2->setSamples(points2);
        curve1->attach( this );
        curve2->attach(this);
        curve1->setLegendAttribute(curve1->LegendShowLine);//显示图例的标志，这里显示线的颜色。
        curve2->setLegendAttribute(curve2->LegendShowLine);


}

