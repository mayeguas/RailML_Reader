#include "common3.h"
#include <QDebug>

/**
 * @brief GeometricPositioningSystem::parse_geometricPositioningSystem
 * @param node_geometricPositioningSystem
 */
void GeometricPositioningSystem::parse_geometricPositioningSystem(QDomNode node_geometricPositioningSystem)
{
    id = node_geometricPositioningSystem.attributes().namedItem("id").nodeValue();
    crsDefinition = node_geometricPositioningSystem.attributes().namedItem("crsDefinition").nodeValue();

    QDomNodeList childNodes = node_geometricPositioningSystem.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(qMakePair(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }
        else if (childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            isValid.append(qMakePair(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
    }
}


/**
 * @brief GeometricPositioningSystem::operator ==
 * @param geoPosSys
 * @return
 */
bool GeometricPositioningSystem::operator==(GeometricPositioningSystem geoPosSys)
{
    if (id == geoPosSys.get_id()) return true;
    else return false;
}

/**
 * @brief LinearPositioningSystem::parse_linearPositioningSystem
 * @param node_linearPositioningSystem
 */
void LinearPositioningSystem::parse_linearPositioningSystem(QDomNode node_linearPositioningSystem)
{
    id = node_linearPositioningSystem.attributes().namedItem("id").nodeValue();
    units = node_linearPositioningSystem.attributes().namedItem("units").nodeValue();
    startMeasure = node_linearPositioningSystem.attributes().namedItem("startMeasure").nodeValue().toDouble();
    endMeasure = node_linearPositioningSystem.attributes().namedItem("endMeasure").nodeValue().toDouble();
    linearReferencingMethod = node_linearPositioningSystem.attributes().namedItem("linearReferencingMethod").nodeValue();

    QDomNodeList childNodes = node_linearPositioningSystem.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(qMakePair(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }
        else if (childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            isValid.append(qMakePair(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
        else if (childNode.nodeName().compare("anchor") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            Anchor qAnchor = Anchor();
            qAnchor.parse_anchor(childNode);
            anchor.append(qAnchor);
        }
    }
}

/**
 * @brief LinearPositioningSystem::operator ==
 * @param linPosSys
 * @return
 */
bool LinearPositioningSystem::operator==(LinearPositioningSystem linPosSys)
{
    if (id == linPosSys.get_id()) return true;
    else return false;
}

/**
 * @brief Anchor::parse_anchor
 * @param node_anchor
 */
void Anchor::parse_anchor(QDomNode node_anchor)
{
    id = node_anchor.attributes().namedItem("id").nodeValue();
    anchorName = node_anchor.attributes().namedItem("anchorName").nodeValue();
    measure = node_anchor.attributes().namedItem("measure").nodeValue().toDouble();
    measureToNext = node_anchor.attributes().namedItem("measureToNext").nodeValue().toDouble();
}

/**
 * @brief ScreenPositioningSystem::parse_screenPositioningSystem
 * @param node_screenPositioningSystem
 */
void ScreenPositioningSystem::parse_screenPositioningSystem(QDomNode node_screenPositioningSystem)
{
    id = node_screenPositioningSystem.attributes().namedItem("id").nodeValue();
    pxX = node_screenPositioningSystem.attributes().namedItem("pxX").nodeValue().toInt();
    pxY = node_screenPositioningSystem.attributes().namedItem("pxY").nodeValue().toInt();
    pxZ = node_screenPositioningSystem.attributes().namedItem("pxZ").nodeValue().toInt();

    QDomNodeList childNodes = node_screenPositioningSystem.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(qMakePair(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }
        else if (childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            isValid.append(qMakePair(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
    }
}

/**
 * @brief ScreenPositioningSystem::operator ==
 * @param screenPosSys
 * @return
 */
bool ScreenPositioningSystem::operator==(ScreenPositioningSystem screenPosSys)
{
    if (id == screenPosSys.get_id()) return true;
    else return false;
}

/**
 * @brief Positioning::parse_positioning
 * @param node_positioning
 */
void Positioning::parse_positioning(QDomNode node_positioning)
{
    QDomNodeList childNodes = node_positioning.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("geometricPositioningSystems") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());

            QDomNodeList sub_childNodes = childNode.childNodes();

            for (int j = 0; j<sub_childNodes.size(); j++)
            {
                QDomNode sub_childNode = sub_childNodes.at(j);

                if (sub_childNode.nodeName().compare("geometricPositioningSystem") == 0)
                {
                    qDebug() << QString("Reading <%1> element").arg(sub_childNode.nodeName());

                    GeometricPositioningSystem geometricPositioningSystem = GeometricPositioningSystem();
                    geometricPositioningSystem.parse_geometricPositioningSystem(sub_childNode);
                    geometricPositioningSystems.insert(geometricPositioningSystem.get_id(), geometricPositioningSystem);
                }
            }
        }
        else if (childNode.nodeName().compare("linearPositioningSystems") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());

            QDomNodeList sub_childNodes = childNode.childNodes();

            for (int j = 0; j<sub_childNodes.size(); j++)
            {
                QDomNode sub_childNode = sub_childNodes.at(j);

                if (sub_childNode.nodeName().compare("linearPositioningSystem") == 0)
                {
                    qDebug() << QString("Reading <%1> element").arg(sub_childNode.nodeName());

                    LinearPositioningSystem linearPositioningSystem = LinearPositioningSystem();
                    linearPositioningSystem.parse_linearPositioningSystem(sub_childNode);
                    linearPositioningSystems.insert(linearPositioningSystem.get_id(), linearPositioningSystem);
                }
            }
        }

        else if (childNode.nodeName().compare("screenPositioningSystems") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());

            QDomNodeList sub_childNodes = childNode.childNodes();

            for (int j = 0; j<sub_childNodes.size(); j++)
            {
                QDomNode sub_childNode = sub_childNodes.at(j);

                if (sub_childNode.nodeName().compare("screenPositioningSystem") == 0)
                {
                    qDebug() << QString("Reading <%1> element").arg(sub_childNode.nodeName());

                    ScreenPositioningSystem screenPositioningSystem = ScreenPositioningSystem();
                    screenPositioningSystem.parse_screenPositioningSystem(sub_childNode);
                    screenPositioningSystems.insert(screenPositioningSystem.get_id(), screenPositioningSystem);
                }
            }

        }
    }

}

/**
 * @brief Common3::parse_common
 * @param node_common
 */
void Common3::parse_common(QDomNode node_common)
{
    QDomNodeList childNodes = node_common.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("positioning") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            positioning.parse_positioning(childNode);
        }
    }
}
