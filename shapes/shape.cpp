#include "shape.h"
#include <QtWidgets>

Shape::Shape()
{

}

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

    QPixmap pixmap(pixmap_w, pixmap_h);
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.translate(15, 15); // ANYA THERE ARE NEED CHANGES
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, 0, 0);
    painter.end();

    pixmap.setMask(pixmap.createHeuristicMask());

    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(15, 20));

    drag->exec();
    setCursor(Qt::OpenHandCursor);

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
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}
