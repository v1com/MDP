#include "ifblock.h"
#include <QWidget>
#include <QPainter>

IfBlock::IfBlock(int x, int y)
{
    //left point
    this->x = x;
    this->y = y;

    pixmap_w = 100;
    pixmap_h = 50;

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
        QPointF(x,y),
        QPointF(x + 50, y + 25),
        QPointF(x + 100, y),
        QPointF(x + 50, y - 25),
    };
    painter->drawPolygon(points, 4);
}

QRectF IfBlock::boundingRect() const
{
    return QRectF(x, y - 25, 100, 50);
}
