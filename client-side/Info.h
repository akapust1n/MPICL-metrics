#ifndef INFO_H
#define INFO_H
#include <QString>
#include <QStringList>
#include <utility>

class Info
{
public:
    Info();
    QString token;
    int numProcessors;
    QString filename;
    QStringList fileList;
    std::pair<double, double> minMax;
};

#endif // INFO_H
