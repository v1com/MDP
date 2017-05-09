#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Scene.h"

class View: public QGraphicsView
{
public:
    View(Scene * scene, int i);

protected:
    virtual void dragEnterEvent ( QDragEnterEvent * event );
    virtual void dragLeaveEvent ( QDragLeaveEvent * event );
    virtual void dragMoveEvent ( QDragMoveEvent * event );
    virtual void dropEvent ( QDropEvent * event );

private:
    Scene * scene_;
    int i;
};

#endif
