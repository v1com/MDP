#include "block.h"
#include <QWidget>
#include <QPainter>

Block::Block(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    pixmap_w = w;
    pixmap_h = h;

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
    painter->drawText(-15, -15, 100, 50, 0, "testtest\ntesttesttest");
}

QRectF Block::boundingRect() const
{
    return QRectF(x, y, w, h);
}
