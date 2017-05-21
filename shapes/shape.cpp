#include "arrow.h"
#include "shape.h"
#include <QtWidgets>
#include <QDrag>

Shape::Shape()
{
    isDefault = false;
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

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
     qDebug() << "Shape::mousePressEvent";

    if(event->button() == Qt::RightButton)
    {
        qDebug() << "Shape::RightButton";
        QMimeData * mimeData = new QMimeData;

        Shape * item = this;
        QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Shape*));
        mimeData->setData("Item",byteArray);

        // start the event
        QDrag * drag = new QDrag(event->widget());
        drag->setMimeData(mimeData);
        drag->exec();
    } else {
        qDebug() << "Shape::LeftButton";
    }

}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Shape::mouseMoveEvent";
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

   // drag->exec();
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Shape::mouseReleaseEvent";
    setCursor(Qt::OpenHandCursor);

    if(isDefault) {
        return;
    } else {
        this->setX(event->scenePos().x() - this->getCoords().x());
        this->setY(event->scenePos().y() - this->getCoords().y());
    }
}

//void Shape::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
//{
//    qDebug() << "Shape::dragEnterEvent ";
//}

//void Shape::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
//{
//    qDebug() << "Shape::dragLeaveEvent";
//}

//void Shape::dragMoveEvent(QGraphicsSceneDragDropEvent * event )
//{
//    qDebug() << "Shape::dragMoveEvent";
//}

void Shape::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    //Add arrow
    qDebug() << "shape drop event";

    QByteArray byteArray = event->mimeData()->data("Item");
    QByteArray *newArray = new QByteArray();
    newArray->append(byteArray.data());
    Shape *shape = *reinterpret_cast<Shape**>(byteArray.data());

    Arrow *arrow = new Arrow(shape, this);
    this->scene()->addItem(arrow);
    this->scene()->update();
}
