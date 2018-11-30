#include "infrastructure.h"
#include <QDebug>
/**
 * @brief NetElement::parse_netElement
 * @param node_netElement
 */
void NetElement::parse_netElement(QDomNode node_netElement)
{
    id = node_netElement.attributes().namedItem("id").nodeValue();
    length = node_netElement.attributes().namedItem("lenght").nodeValue().toDouble();

    QDomNodeList childNodes = node_netElement.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(QPair<QString, QString>(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }
        else if(childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(QPair<QString, QString>(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
        else if(childNode.nodeName().compare("elementCollectionUnordered") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_UnorderedColletion unorderedCollection;
            unorderedCollection.parse_UnorderedColletion(childNode);
            elementCollectionUnordered.append(unorderedCollection);
        }
        else if(childNode.nodeName().compare("elementCollectionOrdered") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_OrderedColletion orderedCollection;
            orderedCollection.parse_OrderedColletion(childNode);
            elementCollectionOrdered.append(orderedCollection);
        }
        else if(childNode.nodeName().compare("associatedPositioningSystem") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_AssociatedPositioningSystem positioningSystem;
            positioningSystem.parse_associatedPositioningSystem(childNode);
            associatedPositioningSystem.append(positioningSystem);
        }

    }
}

/**
 * @brief NetRelation::parse_netRelation
 * @param node_netRelation
 */
void NetRelation::parse_netRelation(QDomNode node_netRelation)
{
    id = node_netRelation.attributes().namedItem("id").nodeValue();
    navegability = node_netRelation.attributes().namedItem("navegability").nodeValue();
    positionOnA = node_netRelation.attributes().namedItem("positionOnA").nodeValue();
    positionOnB = node_netRelation.attributes().namedItem("positionOnB").nodeValue();

    QDomNodeList childNodes = node_netRelation.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(QPair<QString, QString>(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }
        else if(childNode.nodeName().compare("isValid") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            isValid.append(QPair<QString, QString>(childNode.attributes().namedItem("from").nodeValue(), childNode.attributes().namedItem("to").nodeValue()));
        }
        else if(childNode.nodeName().compare("elementA") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            elementA = childNode.attributes().namedItem("ref").nodeValue();
        }
        else if(childNode.nodeName().compare("elementB") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            elementB = childNode.attributes().namedItem("ref").nodeValue();
        }
    }
}

/**
 * @brief Network::parse_network
 * @param node_network
 */
void Network::parse_network(QDomNode node_network)
{
    id = node_network.attributes().namedItem("id").nodeValue();

    QDomNodeList childNodes = node_network.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("name") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            name.append(QPair<QString, QString>(childNode.attributes().namedItem("name").nodeValue(), childNode.attributes().namedItem("language").nodeValue()));
        }
        else if(childNode.nodeName().compare("level"))
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_LevelNetwork levelNetwork;
            levelNetwork.parse_levelNetwork(childNode);
            level.append(levelNetwork);

        }
        else if(childNode.nodeName().compare("networkResource"))
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            RTM_NetworkResources networkResources;
            networkResources.parse_networkResource(childNode);
            networkResource.append(networkResources);
        }
    }
}

/**
 * @brief Topology::parse_topology
 * @param node_topology
 */
void Topology::parse_topology(QDomNode node_topology)
{
    QDomNodeList childNodes = node_topology.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("netElements") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());

            QDomNodeList sub_childNodes = childNode.childNodes();

            for (int j = 0; j<sub_childNodes.size(); j++)
            {
                QDomNode child = sub_childNodes.at(j);

                if (child.nodeName().compare("netElement") == 0)
                {
                    qDebug() << QString("Reading <%1> element").arg(child.nodeName());
                    NetElement netElement = NetElement();
                    netElement.parse_netElement(child);
                    netElements.append(netElement);
                }
            }
        }

        else if(childNode.nodeName().compare("netRelations") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());

            QDomNodeList sub_childNodes = childNode.childNodes();

            for (int j = 0; j<sub_childNodes.size(); j++)
            {
                QDomNode child = sub_childNodes.at(j);

                if (child.nodeName().compare("netRelation") == 0)
                {
                    qDebug() << QString("Reading <%1> element").arg(child.nodeName());
                    NetRelation netRelation = NetRelation();
                    netRelation.parse_netRelation(child);
                    netRelations.append(netRelation);
                }
            }

        }
        else if(childNode.nodeName().compare("networks") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());

            QDomNodeList sub_childNodes = childNode.childNodes();

            for (int j = 0; j<sub_childNodes.size(); j++)
            {
                QDomNode child = sub_childNodes.at(j);

                if (child.nodeName().compare("network") == 0)
                {
                    qDebug() << QString("Reading <%1> element").arg(child.nodeName());
                    Network network = Network();
                    network.parse_network(child);
                    networks.append(network);
                }
            }
        }
    }
}

void Infrastructure::parse_infrastructure(QDomNode node_infrastructure)
{
    id = node_infrastructure.attributes().namedItem("id").nodeValue();

    QDomNodeList childNodes = node_infrastructure.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("topology") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            topology.parse_topology(childNode);
        }

    }
}
