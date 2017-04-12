#ifndef DIAGRAM_H
#define DIAGRAM_H
#include <iostream>
#include "shapes/shape.h"

class Diagram {
public:
    Diagram ();
    void addElement (Shape *element);
    void deleteElement (Shape *element);

private:
     std::vector <std::list <Shape>> vertexes;
};

#endif // DIAGRAM_H
