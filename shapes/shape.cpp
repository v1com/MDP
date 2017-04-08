#include "shape.h"
#include <QtWidgets>

Shape::Shape()
{

}

QRectF Shape::boundingRect() const
{
    return QRectF(-15.5, -15.5, 34, 34);
}

//void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    Q_UNUSED(option);
//    Q_UNUSED(widget);
//    painter->setPen(Qt::NoPen);
//    painter->setPen(QPen(Qt::black, 1));
//    painter->setBrush(* new QBrush(Qt::gray));

//  /*Simple block
//    painter->drawRect(-15,-15,100,50);
//    painter->drawText(-15,-15,100,50,0,"testtest\ntesttesttest");*/

//  /*If block (romb)
//    painter->drawPolygon(points, 4);*/

//  /*Exit
//    painter->drawEllipse(-15,-15,50,50);
//    painter->setBrush(* new QBrush(Qt::black));
//    painter->drawEllipse(-5,-5,30,30);*/

//  /*Entrance
//    painter->setBrush(* new QBrush(Qt::black));
//    painter->drawEllipse(-15,-15,50,50);*/

//  /*ParallelBlocks
//    painter->setBrush(* new QBrush(Qt::black));
//    painter->drawRect(-55,-55,150,5);*/

//}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ClosedHandCursor);
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }

    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);

    mime->setColorData(QRectF(-15.5, -15.5, 34, 34));
    mime->setText("Data");

    QPixmap pixmap(30, 30);
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.translate(15, 15);
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, 0, 0);
    painter.end();

    pixmap.setMask(pixmap.createHeuristicMask());

    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(15, 20));

    drag->exec();
    setCursor(Qt::OpenHandCursor);
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}
