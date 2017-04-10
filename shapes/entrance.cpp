#include "entrance.h"
#include <QWidget>
#include <QPainter>

Entrance::Entrance(int x, int y)
{
    this->x = x;
    this->y = y;

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
    painter->drawEllipse(x,y,w,h);
}

QRectF Entrance::boundingRect() const
{
    return QRectF(x, y, w, h);
}
