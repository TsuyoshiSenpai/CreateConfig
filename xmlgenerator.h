#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H

#include "model.h"

#include <QObject>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QtXml/QDomDocument>

class XMLGenerator
{
public:
    explicit XMLGenerator(QString pathToFile, const QVector<Group> &groups);
    void createXMLDocument(QString pathToFile);
    void fillDocument(const QVector<Group> &groups);
    QDomElement rootElement;
    QDomDocument document;
};

#endif // XMLGENERATOR_H
