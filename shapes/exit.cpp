#include "exit.h"
#include <QWidget>
#include <QPainter>

Exit::Exit(int x, int y)
{
    this->x = x;
    this->y = y;

    //Offset in order to the figures are not cut off
    pixmap_w = outer_w + 2;
    pixmap_h = outer_h + 2;

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
    painter->drawEllipse(x, y, outer_w,outer_h);

    painter->setBrush(* new QBrush(Qt::black));
    painter->drawEllipse(x + 5, y + 5, inner_w, inner_h);
}

QRectF Exit::boundingRect() const
{
    return QRectF(x, y, outer_w, outer_h);
}
