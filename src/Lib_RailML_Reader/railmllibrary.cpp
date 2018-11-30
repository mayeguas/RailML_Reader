#include "railmllibrary.h"
#include "railml.h"

class CommonImpl : public ICommon
{
public:
    CommonImpl(QDomNode);
    QList<QString> getGeometricPositioningSystemIds();
    QList<QString> getLinearPositioningSystemIds();
    QList<QString> getScreenPositioningSystemIds();

    QString getGeometricPositioningSystemCrsDef_byId(QString);

    QString getLinearPositioningSystemReferencingMethod_byId(QString);
    QString getLinearPositioningSystemStartMeasure_byId(QString);
    QString getLinearPositioningSystemEndMeasure_byId(QString);
    QString getLinearPositioningSystemUnits_byId(QString);

    QString getScreenPositioningSystemPxX_byId(QString);
    QString getScreenPositioningSystemPxY_byId(QString);
    QString getScreenPositioningSystemPxZ_byId(QString);

private:
    RailML * railml;
};

CommonImpl::CommonImpl(QDomNode node_railml)
{
    railml = new RailML();
    railml->parse_railML(node_railml);
}

QList<QString> CommonImpl::getGeometricPositioningSystemIds()
{
    QList<QString> geoPosSysIds;
    foreach(GeometricPositioningSystem geoPosSys, railml->get_common().get_positioning().get_geometricPositioningSystems())
    {
        geoPosSysIds.append(geoPosSys.get_id());
    }

    return geoPosSysIds;
}

QList<QString> CommonImpl::getLinearPositioningSystemIds()
{
    QList<QString> linPosSysIds;
    foreach(LinearPositioningSystem linPosSys, railml->get_common().get_positioning().get_linearPositioningSystems())
    {
        linPosSysIds.append(linPosSys.get_id());
    }

    return linPosSysIds;
}

QList<QString> CommonImpl::getScreenPositioningSystemIds()
{
    QList<QString> screenPosSysIds;
    foreach(ScreenPositioningSystem screenPosSys, railml->get_common().get_positioning().get_screenPositioningSystems())
    {
        screenPosSysIds.append(screenPosSys.get_id());
    }

    return screenPosSysIds;
}

QString CommonImpl::getGeometricPositioningSystemCrsDef_byId(QString geoPosSysId)
{
    if (railml->get_common().get_positioning().get_geometricPositioningSystems().contains(geoPosSysId) == true)
    {
        return railml->get_common().get_positioning().get_geometricPositioningSystems()[geoPosSysId].get_crsDefinition();
    }
    return QString("id ").append(geoPosSysId).append(" not in railml file");

}

QString CommonImpl::getLinearPositioningSystemReferencingMethod_byId(QString linPosSysId)
{
    if (railml->get_common().get_positioning().get_linearPositioningSystems().contains(linPosSysId) == true)
    {
        return railml->get_common().get_positioning().get_linearPositioningSystems()[linPosSysId].get_linearReferencingMethod();
    }
    return QString("id ").append(linPosSysId).append(" not in railml file");
}

QString CommonImpl::getLinearPositioningSystemStartMeasure_byId(QString linPosSysId)
{
    if (railml->get_common().get_positioning().get_linearPositioningSystems().contains(linPosSysId) == true)
    {
        return QString::number(railml->get_common().get_positioning().get_linearPositioningSystems()[linPosSysId].get_startMeasure());
    }
    return QString("id ").append(linPosSysId).append(" not in railml file");
}

QString CommonImpl::getLinearPositioningSystemEndMeasure_byId(QString linPosSysId)
{
    if (railml->get_common().get_positioning().get_linearPositioningSystems().contains(linPosSysId) == true)
    {
        return QString::number(railml->get_common().get_positioning().get_linearPositioningSystems()[linPosSysId].get_endMeasure());
    }
    return QString("id ").append(linPosSysId).append(" not in railml file");
}

QString CommonImpl::getLinearPositioningSystemUnits_byId(QString linPosSysId)
{
    if (railml->get_common().get_positioning().get_linearPositioningSystems().contains(linPosSysId) == true)
    {
        return railml->get_common().get_positioning().get_linearPositioningSystems()[linPosSysId].get_units();
    }
    return QString("id ").append(linPosSysId).append(" not in railml file");
}

QString CommonImpl::getScreenPositioningSystemPxX_byId(QString screenPosSysId)
{
    if (railml->get_common().get_positioning().get_screenPositioningSystems().contains(screenPosSysId) == true)
    {
        return QString::number(railml->get_common().get_positioning().get_screenPositioningSystems()[screenPosSysId].get_pxX());
    }

    return QString("id ").append(screenPosSysId).append(" not in railml file");
}

QString CommonImpl::getScreenPositioningSystemPxY_byId(QString screenPosSysId)
{
    if (railml->get_common().get_positioning().get_screenPositioningSystems().contains(screenPosSysId) == true)
    {
        return QString::number(railml->get_common().get_positioning().get_screenPositioningSystems()[screenPosSysId].get_pxY());
    }

    return QString("id ").append(screenPosSysId).append(" not in railml file");
}

QString CommonImpl::getScreenPositioningSystemPxZ_byId(QString screenPosSysId)
{
    if (railml->get_common().get_positioning().get_screenPositioningSystems().contains(screenPosSysId) == true)
    {
        return QString::number(railml->get_common().get_positioning().get_screenPositioningSystems()[screenPosSysId].get_pxZ());
    }

    return QString("id ").append(screenPosSysId).append(" not in railml file");
}

ICommon * Get_Common(QDomNode node_railML)
{
    ICommon * p = new CommonImpl(node_railML);

    return p;
}
