#ifndef INFO_H
#define INFO_H
#include <QString>
#include <QStringList>

class Info
{
public:
    Info();
    QString token;
    int numProcessors;
    QString filename;
    QStringList fileList;
};

#endif // INFO_H
