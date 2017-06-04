#ifndef INFO_H
#define INFO_H
#include <QString>
#include <QStringList>
#include <utility>
#include <vector>

class Info
{
public:
    Info();
    QString name;
    QString token;
    int numProcessors;
    QString filename;
    QStringList fileList;
    std::pair<double, double> minMax;
    std::vector<int> threads;
    int numRecords;

};
struct eventStruct{
    QString name;
    QString description;
    QString category;
};

#endif // INFO_H
