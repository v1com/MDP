#ifndef BAR_H
#define BAR_H
#include "shape.h"
#include "arrow.h"

class Bar : public Shape
{
    Q_OBJECT
public:
    Bar(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    QPoint getArrowOut();
    QPoint getArrowIn();

public slots:
    void setWidth(QAction *action);
private:
    int w;
    const int h = 5;

    std::list <Arrow *> arrows;
};

#endif // BAR_H
