#include "block.h"
#include <QWidget>
#include <QPainter>

Block::Block()
{
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
    painter->drawRect(-15,-15,100,50);
    painter->drawText(-15,-15,100,50,0,"testtest\ntesttesttest");
}
