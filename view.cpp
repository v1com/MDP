#include "View.h"
#include <QtDebug>

View::View(Scene * scene, int i) :
    QGraphicsView(scene),
    scene_(scene),
    i(i)
{

}

void View::dragEnterEvent ( QDragEnterEvent * event )
{
    qDebug() << "view" << i << "drag enter";
    QGraphicsView::dragEnterEvent(event);
}

void View::dragLeaveEvent ( QDragLeaveEvent * event )
{
    qDebug() << "view" << i <<"drag leave";
    QGraphicsView::dragLeaveEvent(event);
}

void View::dragMoveEvent ( QDragMoveEvent * event )
{
    qDebug() << "view" << i << "drag move";
    QGraphicsView::dragMoveEvent(event);
}

void View::dropEvent ( QDropEvent * event )
{
    qDebug() << "view" << i << "drop";
    QGraphicsView::dropEvent(event);
}
