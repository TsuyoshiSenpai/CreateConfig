#include "headerparser.h"

QRegularExpression HeaderParser::mainRegExp = QRegularExpression("(?<structStart> *struct)|(?<type>float |void \\*|double |unsigned( int | long long | long | char )|signed( int | long long | long | char | short ))(?<name>\\w+)(\\[(?<count>\\d+)\\]){0,1}|flags: (?<flags>\\d{1,4})|( *\\} (?<structEnd>\\w+))\\[*(?<size>\\d*)\\]*;");

HeaderParser::HeaderParser(const QString &pathToHeader, const QString &pathToXML)
{
    readContent(pathToHeader);
    const QVector<Group> groups = getInfo(content);
    //showParsingElements(groups); // нужно для отладки
    XMLGenerator generator(pathToXML, groups);
}

QVector<Group> HeaderParser::getInfo(const QString &str)
{
    Group parent;

    auto matchStruct = mainRegExp.globalMatch(str);

    Group *current = &parent;

    QStack<Group*> parents;

    QString currentVariableFlag;
    QString currentVariableName;
    QString currentVariableCount;
    QString currentGroupName;

    while (matchStruct.hasNext()) {
        auto match = matchStruct.next();

        if (match.captured(QStringLiteral("structEnd")).count() > 0) {
            currentGroupName = match.captured(QStringLiteral("structEnd"));
            current->name = currentGroupName;
            if (match.captured(QStringLiteral("size")).count() > 0) {
                auto size = match.captured(QStringLiteral("size"));
                current->size = size;
            }
            current = parents.pop();
        }

        if(match.captured(QStringLiteral("count")).count() > 0) {
            currentVariableCount = match.captured(QStringLiteral("count"));
        }

        if (match.captured(QStringLiteral("flags")).count() > 0) {
            if(match.captured(QStringLiteral("flags")) == "19") {
                currentVariableFlag = "1";
                current->variables.append(Variable{currentVariableName, currentVariableFlag.toInt(), currentVariableCount.toInt()});
                currentVariableCount = "0";
            } else {
                currentVariableFlag = "0";
                current->variables.append(Variable{currentVariableName, currentVariableFlag.toInt(), currentVariableCount.toInt()});
                currentVariableCount = "0";
            }
        }

        if (match.captured("structStart").count() > 0) {
            parents.push(current);
            current->groups.append(Group{});
            current = &current->groups.last();
        }

        if (match.captured(QStringLiteral("name")).count() > 0) {
            currentVariableName = match.captured(QStringLiteral("name"));
        }
    }

    return parent.groups;
}

void HeaderParser::showParsingElements(const QVector<Group> &groups)
{
    for (const auto &group : groups) {
        qDebug() << "Structure name:" << group.name;
        qDebug() << "Structure size:" << group.size;
        for (const auto &v : group.variables) {
            qDebug() << "Variable:" << group.name << "." << v.name;
            qDebug() << "Flag" << v.name << "=" << v.configurable;
            qDebug() << "Count" << v.name << "=" << v.count;
        }

        showParsingElements(group.groups);
    }
}


void HeaderParser::readContent(const QString pathToFile)
{
    QFile file(pathToFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Open file error!";
    QTextStream in(&file);
    content = in.readAll();
    file.close();
}
