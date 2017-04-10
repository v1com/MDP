#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>

class Shape : public QGraphicsItem
{
public:
    Shape();

    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;

protected:
    int pixmap_w, pixmap_h;
    int translate_x, translate_y;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPE_H
