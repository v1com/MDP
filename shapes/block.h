#ifndef Block_H
#define Block_H
#include "shape.h"

class Block : public Shape
{
public:
    Block(int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    int x, y, h, w;

    Block * next;
};

#endif // Block_H
