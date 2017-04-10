#ifndef IFBLOCK_H
#define IFBLOCK_H

#include "shape.h"

class IfBlock : public Shape
{
public:
    IfBlock(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    //Left point of romb
    int x, y;
    const int w = 70;
    const int h = 40;

    IfBlock * true_branch;
    IfBlock * false_branch;
};

#endif // IFBLOCK_H
