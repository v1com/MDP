#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes/block.h"
#include "shapes/ifblock.h"
#include "shapes/entrance.h"
#include "shapes/exit.h"
#include "shapes/bar.h"
#include "shapes/arrow.h"
#include <QSplitter>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow) {
    
    //ui->setupUi(this);
    //QGraphicsScene scene(-200, -200, 400, 400);

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 400, 400);

    //---------testing shapes-----------------------
    Entrance *item1 = new Entrance(202, 30);
    scene->addItem(item1);

    Block *item2 = new Block(160, 70, 100, 50);
    scene->addItem(item2);

    Arrow *arrow1 = new Arrow(QPoint(210, 45), item2, Arrow::DIRECTION_DOWN);
    scene->addItem(arrow1);

    IfBlock *item3 = new IfBlock(170, 150);
    scene->addItem(item3);
    item3->addArrows(scene);

    Block *item4 = new Block(90, 220, 100, 50);
    scene->addItem(item4);
    item4->addArrows(scene);

    Bar *item5 = new Bar(50, 300);
    scene->addItem(item5);
    item5->addArrows(scene);

    //---------------------------------------------

    QSplitter *h1Splitter = new QSplitter;
    QSplitter *h2Splitter = new QSplitter;

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Horizontal);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);

    QGraphicsView *view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setBackgroundBrush(QColor(255, 255, 255));
    view->setWindowTitle("MDP");

    QGraphicsView *view2 = new QGraphicsView(scene);

    h1Splitter->addWidget(view);
    h2Splitter->addWidget(view2);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(vSplitter);
    setLayout(layout);

}

MainWindow::~MainWindow() {
    delete ui;
}
