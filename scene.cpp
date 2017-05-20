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

Scene::Scene(int i) : i(i)
{
    setSceneRect(0, 0, 400, 400);

    if (i == 2) {
        //---------testing shapes-----------------------
        Entrance *item1 = new Entrance(202, 30);
        addItem(item1);

        Block *item2 = new Block(160, 70, 100, 50);
        addItem(item2);

        Arrow *arrow1 = new Arrow(QPoint(210, 45), item2, Arrow::DIRECTION_DOWN);
        addItem(arrow1);

        IfBlock *item3 = new IfBlock(170, 150);
        addItem(item3);
        item3->addArrows(this);

        Block *item4 = new Block(90, 220, 100, 50);
        addItem(item4);
        item4->addArrows(this);

        Bar *item5 = new Bar(50, 300);
        addItem(item5);
        item5->addArrows(this);

        //---------------------------------------------
    }
}

void Scene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drag enter";
}

void Scene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drag leave";
}

void Scene::dragMoveEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drag move";
}

void Scene::dropEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drop";

    QByteArray byteArray = event->mimeData()->data("Item");
    QByteArray *newArray = new QByteArray();
    newArray->append(byteArray.data());
    Shape *shape = *reinterpret_cast<Shape**>(byteArray.data());
    addItem(shape);
}
