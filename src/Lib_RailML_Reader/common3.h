#ifndef COMMON3_H
#define COMMON3_H

#include <QVector>
#include <QString>
#include <QList>
#include <QPair>
#include <QDate>
#include <QDomNode>
#include <QHash>

class GeometricPositioningSystem
{
public:
    //---
    // Constructor
    //---
    GeometricPositioningSystem() : id{}, crsDefinition{}, name{}, isValid{} {}
    //---
    // Parse DomNode
    //---
    void parse_geometricPositioningSystem(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_crsDefinition() {return crsDefinition;}
    QList<QPair<QString, QString>> get_name() {return name;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}

    bool operator==(GeometricPositioningSystem);

private:
    QString id;
    QString crsDefinition;
    QList<QPair<QString, QString>> name;
    QList<QPair<QString, QString>> isValid;
};

class Anchor
{
public:
    //---
    // Constructor
    //---
    Anchor() : id{}, anchorName{}, measure{}, measureToNext{} {}
    //---
    // Parse DomNode
    //---
    void parse_anchor(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_anchorName() {return anchorName;}
    double get_measure() {return measure;}
    double get_measureToNext() {return measureToNext;}

private:
    QString id;
    QString anchorName;
    double measure;
    double measureToNext;
};

class LinearPositioningSystem
{
public:
    //---
    // Constructor
    //---
    LinearPositioningSystem() : id{}, linearReferencingMethod{}, units{}, name{}, isValid{}, anchor{} {}
    //---
    // Parse DomNode
    //---
    void parse_linearPositioningSystem(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    QString get_units() {return units;}
    QString get_linearReferencingMethod() {return linearReferencingMethod;}
    double get_startMeasure() {return startMeasure;}
    double get_endMeasure() {return endMeasure;}
    QList<QPair<QString, QString>> get_name() {return name;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}
    QList<Anchor> get_anchor() {return anchor;}

    bool operator==(LinearPositioningSystem);

private:
    QString id;
    QString linearReferencingMethod;
    double startMeasure;
    double endMeasure;
    QString units;
    QList<QPair<QString, QString>> name;
    QList<QPair<QString, QString>> isValid;
    QList<Anchor> anchor;
};

class ScreenPositioningSystem
{
public:
    //---
    // Constructor
    //---
    ScreenPositioningSystem() : id{}, pxX{}, pxY{}, pxZ{} {}
    //---
    // Parse DomNode
    //---
    void parse_screenPositioningSystem(QDomNode);
    //---
    // Getters
    //---
    QString get_id() {return id;}
    int get_pxX() {return pxX;}
    int get_pxY() {return pxY;}
    int get_pxZ() {return pxZ;}
    QList<QPair<QString, QString>> get_name() {return name;}
    QList<QPair<QString, QString>> get_isValid() {return isValid;}

    bool operator==(ScreenPositioningSystem);

private:
    QString id;
    int pxX;
    int pxY;
    int pxZ;
    QList<QPair<QString, QString>> name;
    QList<QPair<QString, QString>> isValid;
};

class Positioning
{
public:
    //---
    // Constructor
    //---
    Positioning() : geometricPositioningSystems{}, linearPositioningSystems{}, screenPositioningSystems{} {}
    //---
    // Parse DomNode
    //---
    void parse_positioning(QDomNode);
    //---
    // Getters
    //---
    QHash<QString, GeometricPositioningSystem> get_geometricPositioningSystems() {return geometricPositioningSystems;}
    QHash<QString, LinearPositioningSystem> get_linearPositioningSystems() {return linearPositioningSystems;}
    QHash<QString, ScreenPositioningSystem> get_screenPositioningSystems() {return screenPositioningSystems;}

private:

    QHash<QString, GeometricPositioningSystem> geometricPositioningSystems;
    QHash<QString, LinearPositioningSystem> linearPositioningSystems;
    QHash<QString, ScreenPositioningSystem> screenPositioningSystems;
};

class Common3
{
public:
    //---
    // Constructor
    //---
    Common3() : positioning{} {}
    //---
    // Parse DomNode
    //---
    void parse_common(QDomNode);
    //---
    // Getters
    //---
    Positioning get_positioning() {return positioning;}
private:
    Positioning positioning;
};

#endif // COMMON3_H
