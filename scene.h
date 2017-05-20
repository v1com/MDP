#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include<QPointF>

class Scene: public QGraphicsScene
{
public:
    Scene(int i, Scene *ttt);

    Scene *leftScene;

protected:
    void dragEnterEvent (QGraphicsSceneDragDropEvent * event);
    void dragLeaveEvent (QGraphicsSceneDragDropEvent * event);
    void dragMoveEvent (QGraphicsSceneDragDropEvent * event);
    void dropEvent (QGraphicsSceneDragDropEvent * event);

    int i;
};

#endif
