#ifndef BAR_H
#define BAR_H
#include "shape.h"

class Bar : public Shape
{
public:
    Bar(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void setWidth(int w);
private:
    int x, y, w;
    const int h = 5;

    std::vector<Bar> next;
};

#endif // BAR_H
