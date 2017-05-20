#include "block.h"
#include <QWidget>
#include <QPainter>

Block::Block(Scene *tmpScene, int x, int y, int w, int h)
{
    myScene = tmpScene;
    this->x = x;
    this->y = y;
    this->w = width = w;
    this->h = height = h;

    type = 0;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    arrow = new Arrow(QPoint(x + w / 2, y + h), QPoint(x + w / 2, y + h + 30));

    setToolTip("Simple block");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::gray));
    painter->drawRect(x, y, w, h);
    painter->drawText(x, y, w, h, 0, "testtest\ntesttesttest");
}

void Block::addArrows(QGraphicsScene *scene){
    scene->addItem(arrow);
}

QRectF Block::boundingRect() const
{
    return QRectF(x, y, w, h);
}

void Block::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    myScene->addItem(new Block(myScene, 200, 200, w, h));
}

QPoint Block::getArrowOut()
{
    return QPoint(x + w / 2, y + h);
}

QPoint Block::getArrowIn()
{
    return QPoint(x + w / 2, y);
}
