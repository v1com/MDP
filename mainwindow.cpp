#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes\block.h"
#include <QSplitter>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow) {
    
    //ui->setupUi(this);
    //QGraphicsScene scene(-200, -200, 400, 400);

    QGraphicsScene *scene = new QGraphicsScene(-200, -200, 400, 400);
    Block *item = new Block();
    scene->addItem(item);

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
