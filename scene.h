#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include<QPointF>

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
