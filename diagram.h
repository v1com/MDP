#ifndef DIAGRAM_H
#define DIAGRAM_H
#include <iostream>
#include "scene.h"
#include "shapes/arrow.h"
using namespace std;

template <class T>
class Diagram
{
public:
    int nVertexes;
    Diagram ();
    ~Diagram();
    void show(Scene *s);
    void addLink(T *firstEl, T *secondEl);
    void addElement (T *element);


private:
     vector <list <T*>> vertexes;
};
template <class T>
Diagram<T>::Diagram(){
    nVertexes = 0;
}
template <class T>
void Diagram<T>::show(Scene *s){
    int size = vertexes.size();
    list <T*> mylist;
    list <T*> tempList;
    list<T*>::iterator it;
    list<T*>::iterator temp;

    for(int i = 0; i != size; i++){
        mylist = vertexes[i];
        it = mylist.begin();
        s->addItem(*it);
    }

    for(int i = 0; i != size; i++){
        mylist = vertexes[i];
        temp = mylist.begin();
        for(it = mylist.begin(); it != mylist.end(); ++it){
            if (temp!=it){
                s->addItem(new Arrow(*temp,*it));
            }
        }
    }
}



template <class T>
Diagram<T>::~Diagram(){

    list <T*> mylist;
    list<T*>::iterator it;

    int size = vertexes.size();
    for(int i = 0; i != size; i++){
        mylist = vertexes[i];
        it = mylist.begin();
        while (it != mylist.end()){
           it = mylist.erase(it);
        }
    }
}

template <class T>
void Diagram<T>::addElement(T *element)
{
     list <T*> l1;
     l1.push_back(element);
     vertexes.push_back(l1);
}
template <class T>
void Diagram<T>::addLink(T *firstEl, T *secondEl)
{
    list <T*> tempList;
    tempList.push_back(firstEl);
    list <T*>::iterator temp = tempList.begin();
    int size = vertexes.size();
    for(int i = 0; i != size; i++){
        T *searchEl = vertexes[i].front();
        if (searchEl == firstEl){
            vertexes[i].push_back(secondEl);
        }
    }
}


#endif // DIAGRAM_H
