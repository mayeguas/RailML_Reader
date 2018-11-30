#include <QCoreApplication>
#include <QDebug>

#include "../../include/functions.h"
#include "../Lib_RailML_Reader/railmllibrary.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString railMLFile;
    // FileName as first argument
    if(a.arguments().size() != 2)
    {
        qDebug() << "No filename as parameter given.";
        return -1;
    }
    else railMLFile = a.arguments().at(1);

    QDomDocument dom_railml;
    QDomNode node_railml;

    f_loadXMLFile(railMLFile,"railML", dom_railml, node_railml);

    ICommon * p = Get_Common(node_railml);

    QString version_string {};
    int version_int {};
    QString error_string = f_checkAttributeAndAssign <QString> (version_string, node_railml, "version");
    QString error_int = f_checkAttributeAndAssign <int> (version_int, node_railml, "version");

    qDebug() << version_string << version_int;

    QList<QString> geoPosSysIds = p->getGeometricPositioningSystemIds();

    foreach(QString geoPosSysId, geoPosSysIds)
    {
        qDebug() << geoPosSysId << p->getGeometricPositioningSystemCrsDef_byId(geoPosSysId);
    }



    return a.exec();
}
