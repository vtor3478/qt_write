#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    runTimer.setInterval(10);
    runTimer.start();

    //trace3 = trace_a;
    trace4 = trace_a;
    connect(&runTimer,&QTimer::timeout,[=](){
        update();
    });
    drawTimer.setInterval(10);
    drawTimer.start();
    connect(&drawTimer,&QTimer::timeout,[=](){
        strokes++;
        painter_trace.push_back(QLine(QPoint(1,1), QPoint(1,1)));
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
        pos = event->pos();
        qDebug() << pos.x() << "," << pos.y() << ",";
        //trace3.push_back(pos);
    }
    else
    {
        //trace3.clear();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint pos;
        pos = event->pos();
        qDebug() << pos.x() << "," << pos.y() << ",";
        //trace3.push_back(pos);
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
        qDebug() << pos.x() << "," << pos.y() << ",";
        //trace3.push_back(pos);
        pos = QPoint(0,0);
        qDebug() << pos.x() << "," << pos.y() << ",";
        //trace3.push_back(pos);
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int i = 3;
    static int len = 0;
    // 或，判断是否结束，
    while((trace4[i-3] || trace4[i-2]) || (trace4[i-1] || trace4[i-0]))
    {
        if ((trace4[i-3] || trace4[i-2]) && (trace4[i-1] || trace4[i-0]))
        {
            if (i < strokes)
            {
                painter.drawLine(trace4[i-3],trace4[i-2],trace4[i-1],trace4[i-0]);
            }
        }
        else {
            len = i;
        }
        i += 2;
    }
    if (strokes > len)
    {
        strokes = 0;
    }
}
