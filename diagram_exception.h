#ifndef DIAGRAM_EXCEPTION_H
#define DIAGRAM_EXCEPTION_H

#include <iostream>
namespace da {
class InvalidDiagramException: public std::exception
{
public:
    InvalidDiagramException() {}

public:
    const char *what() const throw()
    {
        return "structure of diagram is invalid";
    }
};

class UnexpectedBlockException: public std::exception
{
public:
    UnexpectedBlockException() {}

public:
    const char *what() const throw()
    {
        return "connection between parts of diagram is incorrect";
    }
};
}


#endif // DIAGRAM_EXCEPTION_H
