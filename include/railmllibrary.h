#ifndef RAILMLLIBRARY_H
#define RAILMLLIBRARY_H

#include <QDomNode>

class RailML;
class Topology;

class IRailmlLibrary
{
public:
    virtual RailML getRailml(QDomNode) = 0;
    virtual Topology getTopology() = 0;
};

IRailmlLibrary * Get_RailmlLibrary();

#endif // RAILMLLIBRARY_H
