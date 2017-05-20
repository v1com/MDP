#include "exit.h"
#include <QWidget>
#include <QPainter>

Exit::Exit(int x, int y)
{
    this->x = x;
    this->y = y;

    type = 2;

    width = height = outer_d;
    //Offset in order to the figures are not cut off
    pixmap_w = outer_d + 2;
    pixmap_h = outer_d + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    setToolTip("Exit");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Exit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));

    painter->setBrush(* new QBrush(Qt::gray));
    painter->drawEllipse(x, y, outer_d,outer_d);

    painter->setBrush(* new QBrush(Qt::black));
    painter->drawEllipse(x + 5, y + 5, inner_d, inner_d);
}

void Exit::addArrows(QGraphicsScene *scene){}

QRectF Exit::boundingRect() const
{
    return QRectF(x, y, outer_d, outer_d);
}

QPoint Exit::getArrowOut()
{
    return QPoint(x + width / 2, y + height);
}

QPoint Exit::getArrowIn()
{
    return QPoint(x + width / 2, y);
}

