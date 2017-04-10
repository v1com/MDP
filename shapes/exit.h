#ifndef EXIT_H
#define EXIT_H
#include "shape.h"

class Exit : public Shape
{
public:
    Exit(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    int x, y;
    const int inner_w = 15;
    const int inner_h = 15;
    const int outer_w = 25;
    const int outer_h = 25;
};

#endif // EXIT_H
