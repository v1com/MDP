#ifndef Block_H
#define Block_H
#include "shape.h"

class Block : public Shape
{
public:
    Block();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // Block_H
