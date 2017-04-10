#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "shape.h"

class Entrance : public Shape
{
public:
    Entrance(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    int x, y;
    const int w = 15;
    const int h = 15;

    Entrance * next;
};

#endif // ENTRANCE_H
