#ifndef Block_H
#define Block_H
#include "shape.h"
#include "arrow.h"

class Block : public Shape
{
public:
    Block(int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;
private:
    int h, w;

    Arrow *arrow;
};

#endif // Block_H
