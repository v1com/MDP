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
        //---------testing shapes-----------------------
        Entrance *item1 = new Entrance(202, 30);
        addItem(item1);

        Block *item2 = new Block(tmpScene, 160, 70, 100, 50);
        addItem(item2);

        Arrow *arrow1 = new Arrow(item1, item2);
        addItem(arrow1);

        IfBlock *item3 = new IfBlock(170, 150);
        addItem(item3);

        Arrow *arrow2 = new Arrow(item2, item3);
        addItem(arrow2);

        Block *item4 = new Block(tmpScene, 90, 220, 100, 50);
        addItem(item4);

        Bar *item5 = new Bar(250, 300);
        addItem(item5);

        Arrow *arrow3 = new Arrow(item3, item4);
        addItem(arrow3);

        Arrow *arrow4 = new Arrow(item3, item5);
        addItem(arrow4);

        Block *item6 = new Block(tmpScene, 250, 350, 100, 50);
        addItem(item6);

        Arrow *arrow5 = new Arrow(item5, item6);
        addItem(arrow5);

        Block *item7 = new Block(tmpScene, 360, 350, 100, 50);
        addItem(item7);

        Arrow *arrow6 = new Arrow(item5, item7);
        addItem(arrow6);

        Block *item8 = new Block(tmpScene, 470, 350, 100, 50);
        addItem(item8);

        Arrow *arrow7 = new Arrow(item5, item8);
        addItem(arrow7);

        Bar *item9 = new Bar(250, 450);
        addItem(item9);

        Arrow *arrow8 = new Arrow(item6, item9);
        addItem(arrow8);

        Arrow *arrow9 = new Arrow(item7, item9);
        addItem(arrow9);

        Arrow *arrow10 = new Arrow(item8, item9);
        addItem(arrow10);


        //---------------------------------------------
    }
}

void Scene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
{
   // qDebug() << "scene" << i << "drag enter";
}

void Scene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
{
   // qDebug() << "scene" << i << "drag leave";
}

void Scene::dragMoveEvent ( QGraphicsSceneDragDropEvent * event )
{
   // qDebug() << "scene" << i << "drag move";
}

void Scene::dropEvent (QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "scene" << i << "drop";

    if(i == 2) {
        return;
    } else {
        QByteArray byteArray = event->mimeData()->data("Item");
        QByteArray *newArray = new QByteArray();
        newArray->append(byteArray.data());
        Shape *shape = *reinterpret_cast<Shape**>(byteArray.data());
        shape->setX(event->scenePos().x() - shape->getCoords().x());
        shape->setY(event->scenePos().y() - shape->getCoords().y());
        update();
    }
}
