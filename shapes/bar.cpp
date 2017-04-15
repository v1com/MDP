#include "bar.h"
#include <QWidget>
#include <QtWidgets>
#include <QPainter>

Bar::Bar(int x, int y)
{
    this->x = x;
    this->y = y;
    w = 150;

    width = w;
    height = h;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    arrows.push_back(new Arrow(QPoint(x + 20, y + h), QPoint(x + 20, y + h + 30)));
    arrows.push_back(new Arrow(QPoint(x + 130, y + h), QPoint(x + 130, y + h + 30)));

    setToolTip("Bar");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));
    painter->drawRect(x, y, w, h);
}

void Bar::addArrows(QGraphicsScene *scene){
    foreach (Arrow *arrow, arrows) {
        scene->addItem(arrow);
    }
}

QRectF Bar::boundingRect() const
{
    return QRectF(x, y, w, h);
}

void Bar::setWidth(QAction *action)
{
    auto myScene = scene();
    if (action->text() == "Add arrow") {
        w += 110;
        Arrow *last = arrows.back();
        arrows.push_back(new Arrow(QPoint(last->getFrom().x() + 110, y + h),
                                   QPoint(last->getFrom().x() + 110, y + h + 30)));

        myScene->addItem(arrows.back());
    }
    else if (action->text() == "Delete arrow") {
        if (arrows.size() > 2) {
            w -= 110;

            myScene->removeItem(arrows.back());
            arrows.pop_back();
        }
    }

    pixmap_w = w + 2;
    pixmap_h = h + 2;

    myScene->update();
}

void Bar::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu *menu = new QMenu;
    menu->addAction("Add arrow");
    menu->addAction("Delete arrow");
    menu->popup(event->screenPos());

    QObject::connect(menu, SIGNAL(triggered(QAction *)),
                     this, SLOT(setWidth(QAction *)));
}
