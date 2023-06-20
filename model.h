#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QVector>

struct Variable{
    QString name;
    int configurable;
    int count;
};
struct Group{
    QString name;
    QString size;
    QVector<Variable> variables;
    QVector<Group> groups;
};

#endif // MODEL_H
