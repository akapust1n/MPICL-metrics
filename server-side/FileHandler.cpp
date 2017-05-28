#include "FileHandler.h"
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <string>
#include <zdb/zdb.h>
#include <zdb/PreparedStatement.h>

#include <zdb/Connection.h>


extern ConnectionPool_T pool;

FileHandler::FileHandler()
{
}

void FileHandler::loadFile(QString _filename)
{
    filename = _filename;
    int numline = 1;
    auto temp = findNumProcessors();
    // std::cout << "NUM" << temp << std::endl;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            writeToDB(line);
            // std::cout<<numline++;
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

void FileHandler::writeToDB(QString line)
{
    QStringList spisok = line.split(" ");
    Connection_T con = ConnectionPool_getConnection(pool);

    PreparedStatement_T p = Connection_prepareStatement(con, "INSERT INTO Tracks (filename,  typeRecord , typeEvent,time,prid, pid,numData,data ) VALUES (?, ?, ?,?,?, ?, ?,?) ");

    const std::string _filename = filename.toStdString();
    // std::cout<<spisok[0].toInt()<<" "<<spisok[1].toInt()<<" "<<spisok[2].toInt()<<" "<<spisok[3].toInt()<<std::endl;

    PreparedStatement_setString(p, 1, _filename.c_str());
    PreparedStatement_setInt(p, 2, spisok[0].toInt());
    PreparedStatement_setInt(p, 3, spisok[1].toInt());
    PreparedStatement_setDouble(p, 4, spisok[2].toDouble());
    PreparedStatement_setInt(p, 5, spisok[3].toInt());
    PreparedStatement_setInt(p, 6, spisok[4].toInt());
    PreparedStatement_setInt(p, 7, spisok[5].toInt());

    QString data = " ";
    if (spisok.size() == 10) { //only destination

        data += spisok[9];
    } else {
        data = QString::number(-1);
    }
    auto temp = data.toStdString().c_str();

    PreparedStatement_setString(p, 8, temp);
    TRY
    {
        PreparedStatement_execute(p);
    }
    CATCH(SQLException)
    {
        std::cerr << "INSERT ERROR";
        std::cout << Connection_getLastError(con) << std::endl;
    }
    END_TRY;
    Connection_close(con);
}

QString FileHandler::combineStringList(QStringList list, int position)
{
    QString result;
    for (int i = position; i < list.size(); i++) {
        result += list[i];
    }
    return result;
}
