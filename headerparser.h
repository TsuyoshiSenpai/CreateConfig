#ifndef HEADERPARSER_H
#define HEADERPARSER_H

#include "model.h"
#include "xmlgenerator.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStack>

class HeaderParser // Этот класс получает из system.h параметры, передаваемые в модель
{
public:
    explicit HeaderParser(const QString &pathToHeader, const QString &pathToXML);
    void showParsingElements(const QVector<Group> &groups);
    static QVector<Group> getInfo(const QString &str);
    void readContent(const QString pathToFile);
    QString content;
private:
    static QRegularExpression mainRegExp;
};

#endif // HEADERPARSER_H
