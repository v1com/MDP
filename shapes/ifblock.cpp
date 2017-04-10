#include "ifblock.h"
#include <QWidget>
#include <QPainter>

IfBlock::IfBlock(int x, int y)
{
    //left point
    this->x = x;
    this->y = y;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - (y - h / 2) + 1;

    setToolTip("If block");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void IfBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::gray));

    QPointF points[4] = {
        QPointF(x, y),
        QPointF(x + w / 2, y + h / 2),
        QPointF(x + w, y),
        QPointF(x + w / 2, y - h / 2),
    };
    painter->drawPolygon(points, 4);
}

QRectF IfBlock::boundingRect() const
{
    return QRectF(x, y - h / 2, w, h);
}
