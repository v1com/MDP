#include "ifblock.h"
#include <QWidget>
#include <QPainter>

IfBlock::IfBlock(int x, int y)
{
    this->x = x;
    this->y = y;

    width = w;
    height = h;

    type = 4;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    left_arrow = new Arrow(QPoint(x, y + h / 2), QPoint(x - 100, y + h + 30));
    right_arrow = new Arrow(QPoint(x + w, y + h / 2), QPoint(x + w + 100, y + h + 30));

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

    QPoint points[4] = {
        QPoint(x, y + h / 2),
        QPoint(x + w / 2, y + h),
        QPoint(x + w, y + h / 2),
        QPoint(x + w / 2, y),
    };
    painter->drawPolygon(points, 4);
}

void IfBlock::addArrows(QGraphicsScene *scene) {
    scene->addItem(left_arrow);
    scene->addItem(right_arrow);
}

QRectF IfBlock::boundingRect() const
{
    return QRectF(x, y, w, h);
}

QPoint IfBlock::getArrowOut()
{
    if (is_first_arrow){
        is_first_arrow = false;
        return QPoint(x, y + h / 2);
    }
    else {
        return QPoint(x + w, y + h / 2);
    }
}

QPoint IfBlock::getArrowIn()
{
    return QPoint(x + w / 2, y);
}

