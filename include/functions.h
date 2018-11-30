#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QDomDocument>

extern QString f_loadXMLFile(QString XMLFilePath, QString rootElement, QDomDocument &domXML, QDomNode &rootNode);

template <class T>
extern QString f_checkAttributeAndAssign(T &attribute, QDomNode node, QString attributeName)
{

}

#endif // FUNCTIONS_H
