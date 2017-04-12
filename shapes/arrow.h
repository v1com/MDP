#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsItem>
#include <QPointF>
#include "shape.h"

class Arrow : public QGraphicsItem {
public:
    Arrow(Shape *from, Shape *to);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QPointF from;
    QPointF to;
};

#endif // ARROW_H
