#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QString>
#include <QStringList>

class FileHandler
{
public:
    FileHandler();
    void loadFile(QString _filename);
private:
    QString filename;
    int processors;

private:
    int findNumProcessors();
    void writeToDB(QString line);
    QString combineStringList(QStringList list, int position );
};

#endif // FILEHANDLER_H
