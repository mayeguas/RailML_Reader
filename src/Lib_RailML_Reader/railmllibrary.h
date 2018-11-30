#ifndef RAILMLLIBRARY_H
#define RAILMLLIBRARY_H

#include <QString>
#include <QList>
#include <QDomNode>

class ICommon
{
public:
    virtual QList<QString> getGeometricPositioningSystemIds() = 0;
    virtual QList<QString> getLinearPositioningSystemIds() = 0;
    virtual QList<QString> getScreenPositioningSystemIds() = 0;

    virtual QString getGeometricPositioningSystemCrsDef_byId(QString) = 0;

    virtual QString getLinearPositioningSystemReferencingMethod_byId(QString) = 0;
    virtual QString getLinearPositioningSystemStartMeasure_byId(QString) = 0;
    virtual QString getLinearPositioningSystemEndMeasure_byId(QString) = 0;
    virtual QString getLinearPositioningSystemUnits_byId(QString) = 0;

    virtual QString getScreenPositioningSystemPxX_byId(QString) = 0;
    virtual QString getScreenPositioningSystemPxY_byId(QString) = 0;
    virtual QString getScreenPositioningSystemPxZ_byId(QString) = 0;
};


class ITopology
{
public:
    virtual QList<QString> getNetElementIds() = 0;
    virtual QList<QString> getNetRelationIds() = 0;
    virtual QList<QString> getNetworkIds() = 0;

    virtual QString getNetElementLength_byId(QString) = 0;
    virtual QList<QPair<QString, QString>> getNetElementIntrinsicCoordinateAndKps_byId(QString) = 0;

};

ICommon * Get_Common(QDomNode);

#endif // RAILMLLIBRARY_H
