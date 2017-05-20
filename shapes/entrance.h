#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "shape.h"
#include "arrow.h"

class Entrance : public Shape
{
public:
    Entrance(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;
    QPoint getArrowOut();
    QPoint getArrowIn();
private:
    const int w = 15;
    const int h = 15;

    Arrow *arrow;
};

#endif // ENTRANCE_H
