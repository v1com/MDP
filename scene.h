#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include<QPointF>

class Item;

class Item: public QGraphicsEllipseItem
{
public:
    Item(int x,int y);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


class Scene: public QGraphicsScene
{
public:
    Scene(int i);

protected:
    virtual void dragEnterEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void dragLeaveEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void dragMoveEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void dropEvent ( QGraphicsSceneDragDropEvent * event );

    int i;
};

#endif
