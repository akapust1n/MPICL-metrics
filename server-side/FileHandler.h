#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QString>

class FileHandler
{
public:
    FileHandler();
    void loadFile(QString _filename);
private:
    QString filename;
private:
    int findNumProcessors();
    int processors;
};

#endif // FILEHANDLER_H
