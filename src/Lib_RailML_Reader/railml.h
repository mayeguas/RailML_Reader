#ifndef RAILML_H
#define RAILML_H

#include "common3.h"
#include "infrastructure.h"

class RailML
{
public:
    //---
    // Constructor
    //---
    RailML() : common{}, infrastructure{} {}
    //---
    // Parse DomNode
    //---
    void parse_railML(QDomNode);
    //---
    // Getters
    //---
    QString get_version() {return version;}
    Common3 get_common() {return common;}
    Infrastructure get_infrastructure() {return infrastructure;}
private:
    QString version;
    Common3 common;
    Infrastructure infrastructure;
};

#endif // RAILML_H
