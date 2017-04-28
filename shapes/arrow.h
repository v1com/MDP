#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsItem>
#include <QPoint>
#include "shape.h"

class Arrow : public QGraphicsItem {
public:
    const static int DIRECTION_UP = 1, DIRECTION_DOWN = 2, DIRECTION_LEFT = 3, DIRECTION_RIGHT = 4;

    Arrow(QPoint from_point, QPoint to_point);
    Arrow(QPoint from_point, Shape *to_shape, const int direction);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getFrom();
private:
    QPoint from;
    QPoint to;

    std::list <QLine> lines;
    // points for arrowhead's triangle
    QPoint points[3];
};

#endif // ARROW_H
