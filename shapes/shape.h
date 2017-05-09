#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>
#include <QGraphicsView>

class Shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Shape();

    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
    virtual void addArrows(QGraphicsScene *scene) = 0;
    int getWidth();
    int getHeight();
    QPoint getCoords();
    Shape* clone();

protected:
    int x, y, width, height;
    int pixmap_w, pixmap_h;
    int translate_x, translate_y;
    //number of vertex
    int n_vertex;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPE_H
