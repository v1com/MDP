#ifndef IFBLOCK_H
#define IFBLOCK_H
#include "arrow.h"
#include "shape.h"

class IfBlock : public Shape
{
public:
    IfBlock(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;   
private:
    const int w = 70;
    const int h = 40;

    Arrow *left_arrow, *right_arrow;
};

#endif // IFBLOCK_H
