#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include<QPointF>

class Scene: public QGraphicsScene
{
public:
    Scene(int i, Scene *ttt);

    int i;
    Scene *leftScene;

protected:
//    void dragEnterEvent (QGraphicsSceneDragDropEvent * event);
//    void dragLeaveEvent (QGraphicsSceneDragDropEvent * event);
//    void dragMoveEvent (QGraphicsSceneDragDropEvent * event);
//    void dropEvent (QGraphicsSceneDragDropEvent * event);
};

#endif
