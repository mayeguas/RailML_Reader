#ifndef RTM4RAILML3_H
#define RTM4RAILML3_H

#include <QVector>
#include <QString>
#include <QList>
#include <QPair>
#include <QDomNode>

class RTM_LevelNetwork
{
public:
    //---
    // Constructor
    //---
    RTM_LevelNetwork() : id{}, descriptionLevel{}, networkResourceRef{} {}
    //---
    // Parse DomNode
    //---
    void parse_levelNetwork(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_descriptionLevel() {return descriptionLevel;}
    QList<QString> get_networkResourceRef() {return networkResourceRef;}
private:
    QString id;
    QString descriptionLevel;
    QList<QString> networkResourceRef;
};

class RTM_NetworkResources
{
public:
    //---
    // Constructor
    //---
    RTM_NetworkResources() : id{}, name{}, isValid{} {}
    //---
    // Parse DomNode
    //---
    void parse_networkResource(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QList<QPair<QString, QString>> get_name() {return name;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}
private:
    QString id;
    QList<QPair<QString, QString>> name;
    QList<QPair<QString, QString>> isValid;
};

class RTM_UnorderedColletion
{
public:
    //---
    // Constructor
    //---
    RTM_UnorderedColletion() : id{}, elementPart{} {}
    //---
    // Parse DomNode
    //---
    void parse_UnorderedColletion(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QList<QString> get_elementPart() {return elementPart;}
private:
    QString id;
    QList<QString> elementPart;
};

class RTM_OrderedColletion
{
public:
    //---
    // Constructor
    //---
    RTM_OrderedColletion() : id{}, sequence{}, elementPart{} {}
    //---
    // Parse DomNode
    //---
    void parse_OrderedColletion(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    int get_sequence() {return sequence;}
    QList<QString> get_elementPart() {return elementPart;}
private:
    QString id;
    int sequence;
    QList<QString> elementPart;
};

class RTM_LinearCoordinate
{
public:
    //---
    // Constructor
    //---
    RTM_LinearCoordinate() : positioningSystemRef{}, lateralDistance{}, measure{}, verticalDistance{}, lateralSide{}, verticalSide{} {}
    //---
    // Parse DomNode
    //---
    void parse_linearCoordinate(QDomNode);
    //---
    // Getters
    //---
    QString get_positioningSystemRef() {return positioningSystemRef;}
    double get_lateralDistance() {return lateralDistance;}
    double get_measure() {return measure;}
    double get_verticalDistance() {return verticalDistance;}
    double get_lateralSide() {return lateralSide;}
    double get_verticalSide() {return verticalSide;}
private:
    QString positioningSystemRef;
    double lateralDistance;
    double measure;
    double verticalDistance;
    double lateralSide;
    double verticalSide;
};

class RTM_GeometricCoordinate
{
public:
    //---
    // Constructor
    //---
    RTM_GeometricCoordinate() : positioningSystemRef{}, x{}, y{}, z{} {}
    //---
    // Parse DomNode
    //---
    void parse_geometricCoordinate(QDomNode);
    //---
    // Getters
    //---
    QString get_positioningSystemRef() {return positioningSystemRef;}
    double get_x() {return x;}
    double get_y() {return y;}
    double get_z() {return z;}
private:
    QString positioningSystemRef;
    double x;
    double y;
    double z;
};


class RTM_IntrinsicCoordinate
{
public:
    //---
    // Constructor
    //---
    RTM_IntrinsicCoordinate() : id{}, intrinsicCoord{}, linearCoordinates{}, geometricCoordinates{} {}
    //---
    // Parse DomNode
    //---
    void parse_intrinsicCoordinate(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_intrinsicCoord() {return intrinsicCoord;}
    QVector<RTM_LinearCoordinate> get_linearCoordinate() {return linearCoordinates;}
    QVector<RTM_GeometricCoordinate> get_geometricCoordinate() {return geometricCoordinates;}

private:
    QString id;
    QString intrinsicCoord;
    QVector<RTM_LinearCoordinate> linearCoordinates;
    QVector<RTM_GeometricCoordinate> geometricCoordinates;
};

class RTM_AssociatedPositioningSystem
{
public:
    //---
    // Constructor
    //---
    RTM_AssociatedPositioningSystem() : id{}, positioningSystemRef{}, intrinsicCoordinates{}, isValid{} {}
    //---
    // Parse DomNode
    //---
    void parse_associatedPositioningSystem(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_positioningSystemRef() {return positioningSystemRef;}
    QVector<RTM_IntrinsicCoordinate> get_intrinsicCoordinate() {return intrinsicCoordinates;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}

private:
    QString id;
    QString positioningSystemRef;
    QVector<RTM_IntrinsicCoordinate> intrinsicCoordinates;
    QList<QPair<QString, QString>> isValid;
};

#endif // RTM4RAILML3_H
