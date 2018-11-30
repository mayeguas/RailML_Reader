#include "rtm4railml3.h"
#include <QDebug>
void RTM_UnorderedColletion::parse_UnorderedColletion(QDomNode node_unorderedColletion)
{
    id = node_unorderedColletion.attributes().namedItem("id").nodeValue();

    QDomNodeList childNodes = node_unorderedColletion.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("elementPart") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            elementPart.append(childNode.attributes().namedItem("ref").nodeValue());
        }
    }
}

void RTM_OrderedColletion::parse_OrderedColletion(QDomNode node_orderedColletion)
{
    id = node_orderedColletion.attributes().namedItem("id").nodeValue();
    sequence = node_orderedColletion.attributes().namedItem("sequence").nodeValue().toInt();

    QDomNodeList childNodes = node_orderedColletion.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("elementPart") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            elementPart.append(childNode.attributes().namedItem("ref").nodeValue());
        }
    }
}

void RTM_LinearCoordinate::parse_linearCoordinate(QDomNode node_linearCoordinate)
{
    positioningSystemRef = node_linearCoordinate.attributes().namedItem("positioningSystemRef").nodeValue();
    lateralDistance = node_linearCoordinate.attributes().namedItem("lateralDistance").nodeValue().toDouble();
    measure = node_linearCoordinate.attributes().namedItem("measure").nodeValue().toDouble();
    verticalDistance = node_linearCoordinate.attributes().namedItem("verticalDistance").nodeValue().toDouble();
    lateralSide = node_linearCoordinate.attributes().namedItem("lateralSide").nodeValue().toDouble();
    verticalSide = node_linearCoordinate.attributes().namedItem("verticalSide").nodeValue().toDouble();

}

void RTM_GeometricCoordinate::parse_geometricCoordinate(QDomNode node_geometricCoordinate)
{
    positioningSystemRef = node_geometricCoordinate.attributes().namedItem("positioningSystemRef").nodeValue();
    x = node_geometricCoordinate.attributes().namedItem("x").nodeValue().toDouble();
    y = node_geometricCoordinate.attributes().namedItem("y").nodeValue().toDouble();
    z = node_geometricCoordinate.attributes().namedItem("z").nodeValue().toDouble();

}

void RTM_IntrinsicCoordinate::parse_intrinsicCoordinate(QDomNode node_intrinsicCoordinate)
{
    id = node_intrinsicCoordinate.attributes().namedItem("id").nodeValue();
    intrinsicCoord = node_intrinsicCoordinate.attributes().namedItem("intrinsicCoord").nodeValue();

    QDomNodeList childNodes = node_intrinsicCoordinate.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("linearCoordinate") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_LinearCoordinate linearCoordinate = RTM_LinearCoordinate();
            linearCoordinate.parse_linearCoordinate(childNode);
            linearCoordinates.append(linearCoordinate);
        }
        else if (childNode.nodeName().compare("geometricCoordinate") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_GeometricCoordinate geometricCoordinate = RTM_GeometricCoordinate();
            geometricCoordinate.parse_geometricCoordinate(childNode);
            geometricCoordinates.append(geometricCoordinate);
        }
    }

}

void RTM_AssociatedPositioningSystem::parse_associatedPositioningSystem(QDomNode node_associatedPositioningSystem)
{
    id = node_associatedPositioningSystem.attributes().namedItem("id").nodeValue();
    positioningSystemRef = node_associatedPositioningSystem.attributes().namedItem("positioningSystemRef").nodeValue();

    QDomNodeList childNodes = node_associatedPositioningSystem.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("intrinsicCoordinate") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_IntrinsicCoordinate intrinsicCoordinate = RTM_IntrinsicCoordinate();
            intrinsicCoordinate.parse_intrinsicCoordinate(childNode);
            intrinsicCoordinates.append(intrinsicCoordinate);
        }
        else if (childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            isValid.append(qMakePair(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
    }

}

void RTM_LevelNetwork::parse_levelNetwork(QDomNode node_levelNetwork)
{
    id = node_levelNetwork.attributes().namedItem("id").nodeValue();
    descriptionLevel = node_levelNetwork.attributes().namedItem("positioningSystemRef").nodeValue();

    QDomNodeList childNodes = node_levelNetwork.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("networkResource") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            networkResourceRef.append(childNode.attributes().namedItem("ref").nodeValue());
        }

    }
}

void RTM_NetworkResources::parse_networkResource(QDomNode node_networkResource)
{
    id = node_networkResource.attributes().namedItem("id").nodeValue();

    QDomNodeList childNodes = node_networkResource.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            isValid.append(qMakePair(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
        else if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(qMakePair(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }

    }
}
