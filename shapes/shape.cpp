#include "shape.h"
#include <QtWidgets>

Shape::Shape()
{

}

int Shape::getWidth()
{
    return width;
}

int Shape::getHeight()
{
    return height;
}

QPoint Shape::getCoords() {
    return QPoint(x, y);
}

int Shape::getType()
{
    return type;
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
    painter.translate(translate_x, translate_y); // ANYA THERE ARE NEED CHANGES
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
