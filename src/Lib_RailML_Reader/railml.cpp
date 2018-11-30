#include "railml.h"

#include <QDebug>

void RailML::parse_railML(QDomNode node_railML)
{
    version = node_railML.attributes().namedItem("version").nodeValue();

    QDomNodeList childNodes = node_railML.childNodes();

    for (int i = 0; i<childNodes.size(); i++)
    {
        QDomNode childNode = childNodes.at(i);

        if (childNode.nodeName().compare("common") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            common.parse_common(childNode);
        }
        else if(childNode.nodeName().compare("infrastructure") == 0)
        {
            qDebug() << QString("Reading <%1> element").arg(childNode.nodeName());
            infrastructure.parse_infrastructure(childNode);
        }
    }
}
