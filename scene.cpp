#include "Scene.h"

#include <QtDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QWidget>
#include <QMimeData>

#include "shapes/block.h"
#include "shapes/ifblock.h"
#include "shapes/entrance.h"
#include "shapes/exit.h"
#include "shapes/bar.h"
#include "shapes/arrow.h"
#include "shapes/shape.h"

Scene::Scene(int i, Scene *tmpScene) : i(i)
{
    setSceneRect(0, 0, 400, 400);

    if (i == 2) {
         setSceneRect(0, 0, 200, 400);
        //---------testing shapes-----------------------
        int defaultX = 50;
        Bar *defaultBar = new Bar(tmpScene, defaultX, 50);
        defaultBar->isDefault = true;
        addItem(defaultBar);

        Block *defaultBlock = new Block(tmpScene, defaultX, 120, 100, 50);
        defaultBlock->isDefault = true;
        addItem(defaultBlock);

        Entrance *defaultEntrance = new Entrance(tmpScene, defaultX, 200);
        defaultEntrance->isDefault = true;
        addItem(defaultEntrance);

        Exit *defaultExit = new Exit(tmpScene, defaultX, 250);
        defaultExit->isDefault = true;
        addItem(defaultExit);

        IfBlock *defaultIfBlock = new IfBlock(tmpScene, defaultX, 320);
        defaultIfBlock->isDefault = true;
        addItem(defaultIfBlock);

        //---------------------------------------------
    }
}

//void Scene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
//{
//   // qDebug() << "scene" << i << "drag enter";
//}

//void Scene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
//{
//   // qDebug() << "scene" << i << "drag leave";
//}

//void Scene::dragMoveEvent ( QGraphicsSceneDragDropEvent * event )
//{
//   // qDebug() << "scene" << i << "drag move";
//}

//void Scene::dropEvent (QGraphicsSceneDragDropEvent *event)
//{
//    qDebug() << "scene" << i << "drop";

//    if(i == 2) {
//        return;
//    } else {
//        QByteArray byteArray = event->mimeData()->data("Item");
//        QByteArray *newArray = new QByteArray();
//        newArray->append(byteArray.data());
//        Shape *shape = *reinterpret_cast<Shape**>(byteArray.data());
//        shape->setX(event->scenePos().x() - shape->getCoords().x());
//        shape->setY(event->scenePos().y() - shape->getCoords().y());
//        update();
//    }
//}
