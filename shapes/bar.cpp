#include "bar.h"
#include <QWidget>
#include <QPainter>

Bar::Bar(int x, int y)
{
    this->x = x;
    this->y = y;
    this->w = 150;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    setToolTip("Bar");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));
    painter->drawRect(x, y, w, h);
}

QRectF Bar::boundingRect() const
{
    return QRectF(x, y, w, h);
}

void Bar::setWidth(int w)
{
    this->w = w;
}
