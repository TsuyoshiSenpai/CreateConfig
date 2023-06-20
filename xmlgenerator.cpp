#include "xmlgenerator.h"

XMLGenerator::XMLGenerator(QString pathToFile, const QVector<Group> &groups)
{
    fillDocument(groups);
    createXMLDocument(pathToFile);
}

void XMLGenerator::createXMLDocument(QString pathToFile)
{
    QFile file(pathToFile);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << document.toString();
        file.close();
    }
}

void XMLGenerator::fillDocument(const QVector<Group> &groups)
{
    rootElement = document.createElement("config");
    document.appendChild(rootElement);

    for (const auto &group : groups)
    {
        QDomElement groupElement = document.createElement("group");
        rootElement.appendChild(groupElement);

        QDomElement groupNameElement = document.createElement("name");
        groupNameElement.appendChild(document.createTextNode(group.name));
        groupElement.appendChild(groupNameElement);

        QDomElement groupSizeElement = document.createElement("number");
        if(group.size.isNull())
            groupSizeElement.appendChild(document.createTextNode("0"));
        else
            groupSizeElement.appendChild(document.createTextNode(group.size));
        groupElement.appendChild(groupSizeElement);

        QDomElement elementsElement = document.createElement("elements");
        groupElement.appendChild(elementsElement);

        for (const auto &v : group.variables)
        {
            QDomElement variableElement = document.createElement("variable");
            elementsElement.appendChild(variableElement);

            QDomElement variableNameElement = document.createElement("name");
            int lastElement = v.count - 1;
            if(group.size.isNull())
            {
                if(v.count == 0)
                    variableNameElement.appendChild(document.createTextNode(group.name + "." + v.name));
                else
                    variableNameElement.appendChild(document.createTextNode(group.name + "." + v.name + "[" + QString::number(lastElement) + "]"));
            }
            else
            {
                if(v.count == 0)
                    variableNameElement.appendChild(document.createTextNode(group.name + "[%1]." + v.name));
                else
                    variableNameElement.appendChild(document.createTextNode(group.name + "[%1]." + v.name + "[" + QString::number(lastElement) + "]"));
            }
            variableElement.appendChild(variableNameElement);

            QDomElement variableConfigurableElement = document.createElement("configurable");
            variableConfigurableElement.appendChild(document.createTextNode(QString::number(v.configurable)));
            variableElement.appendChild(variableConfigurableElement);
        }

        if(group.groups.isEmpty())
            continue;
        else
        {
            for (const auto &nestedGroup : group.groups) {
                QDomElement nestedGroupElement = document.createElement("group");
                groupElement.appendChild(nestedGroupElement);

                QDomElement nestedGroupNameElement = document.createElement("name");
                nestedGroupNameElement.appendChild(document.createTextNode(nestedGroup.name));
                nestedGroupElement.appendChild(nestedGroupNameElement);

                QDomElement nestedGroupSizeElement = document.createElement("number");
                if(nestedGroup.size.isNull())
                    nestedGroupSizeElement.appendChild(document.createTextNode("0"));
                else
                    nestedGroupSizeElement.appendChild(document.createTextNode(nestedGroup.size));
                nestedGroupElement.appendChild(nestedGroupSizeElement);

                QDomElement nestedGroupElementsElement = document.createElement("elements");
                nestedGroupElement.appendChild(nestedGroupElementsElement);

                for (const auto &v : nestedGroup.variables)
                {
                    QDomElement nestedGroupVariableElement = document.createElement("variable");
                    nestedGroupElementsElement.appendChild(nestedGroupVariableElement);

                    QDomElement variableNameElement = document.createElement("name");
                    int lastElement = v.count - 1;
                    if(group.size.isNull())
                    {
                        if(nestedGroup.size.isNull())
                        {
                            if(v.count == 0)
                                variableNameElement.appendChild(document.createTextNode(group.name + "." + nestedGroup.name + "." + v.name));
                            else
                                variableNameElement.appendChild(document.createTextNode(group.name + "." + nestedGroup.name + "." + v.name + "[" + QString::number(lastElement) + "]"));
                        }
                        else
                        {
                            if(v.count == 0)
                                variableNameElement.appendChild(document.createTextNode(group.name + "." + nestedGroup.name + "[%2]." + v.name));
                            else
                                variableNameElement.appendChild(document.createTextNode(group.name + "." + nestedGroup.name + "[%2]." + v.name + "[" + QString::number(lastElement) + "]"));
                        }
                    }
                    else
                    {
                        if(nestedGroup.size.isNull())
                        {
                            if(v.count == 0)
                                variableNameElement.appendChild(document.createTextNode(group.name + "[%1]." + nestedGroup.name + "." + v.name));
                            else
                                variableNameElement.appendChild(document.createTextNode(group.name + "[%1]." + nestedGroup.name + "." + v.name + "[" + QString::number(lastElement) + "]"));
                        }
                        else
                        {
                            if(v.count == 0)
                                variableNameElement.appendChild(document.createTextNode(group.name + "[%1]." + nestedGroup.name + "[%2]." + v.name));
                            else
                                variableNameElement.appendChild(document.createTextNode(group.name + "[%1]." + nestedGroup.name + "[%2]." + v.name + "[" + QString::number(lastElement) + "]"));
                        }
                    }
                    nestedGroupVariableElement.appendChild(variableNameElement);

                    QDomElement variableConfigurableElement = document.createElement("configurable");
                    variableConfigurableElement.appendChild(document.createTextNode(QString::number(v.configurable)));
                    nestedGroupVariableElement.appendChild(variableConfigurableElement);
                }
            }
        }
    }
}
