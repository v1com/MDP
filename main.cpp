#include "mainwindow.h"
#include <QApplication>
#include <shape.h>
#include <QtWidgets>

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
    }

protected:
    void resizeEvent(QResizeEvent *) override
    {
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QGraphicsScene scene(-200, -200, 400, 400);

    Shape *item = new Shape();
    scene.addItem(item);

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(255, 255, 255));
    view.setWindowTitle("MDP");
    view.show();

    return app.exec();
}
