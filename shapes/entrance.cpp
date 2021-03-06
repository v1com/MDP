#include "entrance.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Entrance::Entrance(Scene *tmpScene, int x, int y)
{
    myScene = tmpScene;
    this->myX = x;
    this->myY = y;

    width = w;
    height = h;

    type = 1;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = -x + 1;
    translate_y = -y + 1;

    setToolTip("Entrance");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}


void Entrance::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));
    painter->drawEllipse(myX, myY, w, h);
}

void Entrance::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isDefault) {
        qDebug() << "Block::mouseDoubleClickEvent";
        QMimeData * mimeData = new QMimeData;

        Shape * item = this;
        QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Shape*));
        mimeData->setData("Item",byteArray);

        // start the event
        QDrag * drag = new QDrag(event->widget());
        drag->setMimeData(mimeData);
        drag->exec();
    } else {
        myScene->addItem(new Entrance(myScene, 200, 200));
    }
}

void Entrance::addArrows(QGraphicsScene *scene){
    scene->addItem(arrow);
}

QRectF Entrance::boundingRect() const
{
    return QRectF(myX, myY, w, h);
}

QPoint Entrance::getArrowOut()
{
    return QPoint(myX + w / 2, myY + h);
}

QPoint Entrance::getArrowIn()
{
    return QPoint(myX + w / 2, myY);
}

