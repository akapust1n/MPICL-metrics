#include "FileHandler.h"
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <iostream>

FileHandler::FileHandler()
{
}

void FileHandler::loadFile(QString _filename)
{
    filename = _filename;
    auto temp = findNumProcessors();
    std::cout<<"NUM"<<temp<<std::endl;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList spisok = line.split(" ");
        }
        file.close();
    }
}

int FileHandler::findNumProcessors()
{
    QFile file(filename);
    int m_processors = 0;

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList spisok = line.split(" ");
            if (spisok[3].toInt() > m_processors)
                m_processors = spisok[3].toInt();
        }
        file.close();
    }
    return m_processors;
}
