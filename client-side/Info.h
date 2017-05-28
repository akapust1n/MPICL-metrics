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
    QString token;
    int numProcessors;
    QString filename;
    QStringList fileList;
    std::pair<double, double> minMax;
    std::vector<int> threads;
    int numRecords;

};

#endif // INFO_H
