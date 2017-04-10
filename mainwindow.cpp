#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes/block.h"
#include "shapes/ifblock.h"
#include "shapes/entrance.h"
#include "shapes/exit.h"
#include "shapes/bar.h"
#include <QSplitter>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow) {
    
    //ui->setupUi(this);
    //QGraphicsScene scene(-200, -200, 400, 400);

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 400, 400);

    //---------testing shapes-----------------------
    IfBlock *item = new IfBlock(30, 30);
    scene->addItem(item);

    IfBlock *item2 = new IfBlock(130, 130);
    scene->addItem(item2);

    Block *item3 = new Block(130, 300, 100, 50);
    scene->addItem(item3);

    Entrance *item4 = new Entrance(50, 300);
    scene->addItem(item4);

    Exit *item5 = new Exit(50, 100);
    scene->addItem(item5);

    Bar *item6 = new Bar(0, 70);
    scene->addItem(item6);
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
