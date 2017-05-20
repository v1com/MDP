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

    Arrow *arrow1 = new Arrow(item1, item2);
    scene->addItem(arrow1);

    IfBlock *ifblock1 = new IfBlock(160, 220);
    scene->addItem(ifblock1);

    Arrow *arrow2 = new Arrow(item2, ifblock1);
    scene->addItem(arrow2);

    Block *block2 = new Block(100, 300, 100, 50);
    scene->addItem(block2);

    Arrow *arrow3 = new Arrow(ifblock1, block2);
    scene->addItem(arrow3);

    Block *block3 = new Block(300, 300, 100, 50);
    scene->addItem(block3);

    Arrow *arrow4 = new Arrow(ifblock1, block3);
    scene->addItem(arrow4);

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
