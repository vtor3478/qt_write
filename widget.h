#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QLine>
#include <QVector>
#include <QMouseEvent>

extern QVector<QPoint> trace_a;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    QTimer runTimer,drawTimer;
    QVector<QPoint> trace3;
    QLine now_line;
    int draw_en;
    int strokes;
    int run_time;

private:
};
#endif // WIDGET_H
