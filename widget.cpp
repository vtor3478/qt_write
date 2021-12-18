#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    runTimer.setInterval(10);
    runTimer.start();

    trace3 = trace_a;
    connect(&runTimer,&QTimer::timeout,[=](){
        update();
//        if (run_time > 120)
//            run_time = 0;
    });
    drawTimer.setInterval(10);
    drawTimer.start();
    connect(&drawTimer,&QTimer::timeout,[=](){
        strokes++;
    });
}

Widget::~Widget()
{
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint pos;
        pos = QPoint(-1,-1);
        qDebug() << pos << ",";
        trace3.push_back(pos);
        pos = event->pos();
        qDebug() << pos << ",";
        trace3.push_back(pos);
    }
    else
    {
        trace3.clear();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint pos;
        pos = event->pos();
        qDebug() << pos << ",";
        trace3.push_back(pos);
    }
    else {

    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint pos;
        pos = event->pos();
        qDebug() << pos << ",";
        trace3.push_back(pos);
        pos = QPoint(-1,-1);
        qDebug() << pos << ",";
        trace3.push_back(pos);
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (int i = 1; i < trace3.length()-1;i++)
    {
        if (trace3[i-1] != QPoint(-1,-1) && trace3[i] != QPoint(-1,-1))
        {
            if (i < strokes)
            {
                painter.drawLine(trace3[i-1],trace3[i]);
            }
        }
    }
    if (strokes > trace3.length())
    {
        strokes = 0;
    }
}
