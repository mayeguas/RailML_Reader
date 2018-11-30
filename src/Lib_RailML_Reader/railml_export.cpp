#include "railml.h"
#include "infrastructure.h"

struct _NetElement {
    QString get_id();
};

static RailML * railML;

void f_parse_railml_file(QDomNode node_railml)
{
    railML = new RailML();
    railML->parse_railML(node_railml);
}

QString _NetElement::get_id()
{
    return railML->get_infrastructure().get_topology().get_netElements()[0].get_id();
}







