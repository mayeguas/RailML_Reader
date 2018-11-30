#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include <QVector>
#include <QString>
#include <QList>
#include <QPair>
#include <QDomNode>

#include  "common3.h"
#include "rtm4railml3.h"

class NetElement
{
public:
    //---
    // Constructor
    //---
    NetElement() : id{}, length{}, name{}, isValid{}, relation{}, elementCollectionUnordered{}, elementCollectionOrdered{}, associatedPositioningSystem{} {}
    //---
    // Parse DomNode
    //---
    void parse_netElement(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id; }
    double get_length() {return length; }
    QList<QPair<QString, QString>> get_name() {return name;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}
    QList<QString> get_relation() { return relation; }
    QVector<RTM_UnorderedColletion> get_elementCollectionUnordered() {return elementCollectionUnordered;}
    QVector<RTM_OrderedColletion> get_elementCollectionOrdered() {return elementCollectionOrdered;}
    QVector<RTM_AssociatedPositioningSystem> get_associatedPositioningSystem() {return associatedPositioningSystem;}

    //---
    // Setters
    //---
    void set_id(QString sId) {id = sId;}

private:
    QString id;
    double length;
    QList<QPair<QString, QString>> name;
    QList<QPair<QString, QString>> isValid;
    QList<QString> relation;
    QVector<RTM_UnorderedColletion> elementCollectionUnordered;
    QVector<RTM_OrderedColletion> elementCollectionOrdered;
    QVector<RTM_AssociatedPositioningSystem> associatedPositioningSystem;
};

class NetRelation
{
public:
    //---
    // Constructor
    //---
    NetRelation() : id{}, navegability{}, positionOnA{}, positionOnB{}, name{}, isValid{}, elementA{}, elementB{} {}
    //---
    // Parse DomNode
    //---
    void parse_netRelation(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_navegability() {return navegability;}
    QString get_positionOnA() {return positionOnA;}
    QString get_positionOnB() {return positionOnB;}
    QList<QPair<QString, QString>> get_name() {return name;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}
    QString get_elementA() {return elementA;}
    QString get_elementB() {return elementB;}
private:
    QString id;
    QString navegability;
    QString positionOnA;
    QString positionOnB;
    QList<QPair<QString, QString>> name;
    QList<QPair<QString, QString>> isValid;
    QString elementA;
    QString elementB;
};


class Network
{
public:
    //---
    // Constructor
    //---
    Network() : id{}, name{}, level{}, networkResource{} {}
    //---
    // Parse DomNode
    //---
    void parse_network(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QList<QPair<QString, QString>> get_name() {return name;}
    QVector<RTM_LevelNetwork> get_level() {return level;}
    QVector<RTM_NetworkResources> get_networkResource() {return networkResource;}

private:
    QString id;
    QList<QPair<QString, QString>> name;
    QVector<RTM_LevelNetwork> level;
    QVector<RTM_NetworkResources> networkResource;
};

class Topology
{
public:
    //---
    // Constructor
    //---
    Topology() : netElements{}, netRelations{}, networks{} {}
    //---
    // Parse DomNode
    //---
    void parse_topology(QDomNode);
    //---
    // Getters
    //---
    QVector<NetElement> get_netElements() {return netElements; }
    QVector<NetRelation> get_netRelations() {return netRelations; }
    QVector<Network> get_networks() {return networks; }
private:
    QVector<NetElement> netElements;
    QVector<NetRelation> netRelations;
    QVector<Network> networks;
};

class Infrastructure
{
public:
    //---
    // Constructor
    //---
    Infrastructure() : id{}, topology{} {}
    //---
    // Parse DomNode
    //---
    void parse_infrastructure(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    Topology get_topology() {return topology;}
private:
    QString id;
    Topology topology;
    //FunctionalInfrastructure functionalInfrastructure;
    //InfrastructureVisualization infrastructureVisualization;
};

#endif // INFRASTRUCTURE_H
