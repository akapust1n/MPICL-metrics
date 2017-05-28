#include "RequestManager.h"
#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

RequestManager::RequestManager()
{
}

QString RequestManager::getToken(QByteArray array)
{
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QString response = itemObject["token"].toString();

    return response;
}

QVector<Item> RequestManager::getItems(QByteArray array)
{
    QVector<Item> result;
    // std::cout << "PROCS " << array.toStdString() << std::endl;
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    for (int i = 0; i < resultArray.size(); i++) {
        result.append(fromQJsonArray(resultArray, i));
    }
    return result;
}

QStringList RequestManager::getFileList(QByteArray array)
{
    QStringList result;
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray fileArray = itemObject["message"].toArray();
    for (auto temp : fileArray) {
      //  std::cout << temp.toString().toStdString() << std::endl;
        result.append(temp.toString());
    }
    return result;
}

int RequestManager::getNumProcessors(QByteArray array)
{
 //   std::cout << "PROCS " << array.toStdString() << std::endl;
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    QJsonObject temp1 = resultArray.at(0).toObject();
    int result = temp1["max(prid)"].toInt();

    return result;
}

int RequestManager::getNumRecords(QByteArray array)
{
   // std::cout << "RECORDS " << array.toStdString() << std::endl;
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    QJsonObject temp1 = resultArray.at(0).toObject();
    int result = temp1["COUNT(*)"].toInt();

    return result;
}

std::pair<double, double> RequestManager::getBordes(QByteArray array)
{
    //std::cout << "PROCS " << array.toStdString() << std::endl;
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    QJsonObject temp1 = resultArray.at(0).toObject();
    std::pair<double, double> result = std::make_pair(temp1["MIN(time)"].toDouble(), temp1["MAX(time)"].toDouble());

    return result;
}

eventStruct RequestManager::getEvent(QByteArray array)
{
   // std::cout << "event " << array.toStdString() << std::endl;
    eventStruct result;
    QJsonDocument document = QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    QJsonObject temp1 = resultArray.at(0).toObject();
    result.name = temp1["name"].toString();
    result.description = temp1["description"].toString();
    result.category = temp1["category"].toString();
    return result;

}

Item RequestManager::fromQJsonArray(QJsonArray array, int index)
{
    Item item;
    QJsonObject object = array.at(index).toObject();
    item.pid = object["pid"].toInt();
    item.prid = object["prid"].toInt();
    item.time = object["time"].toDouble();
    item.typeEvent = object["typeEvent"].toInt();
    item.typeRecord = object["typeRecord"].toInt();
    item.destination=object["data"].toString().toInt();
    std::cout<<"DATA"<<item.destination<<std::endl;
    //if(item.destination>1000) item.destination = -1; // :)
   //  std::cout<<"DATA"<<object["data"].toString().toStdString()<<std::endl;
    return item;
}
