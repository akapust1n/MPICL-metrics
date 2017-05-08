#include "RequestManager.h"
#include <iostream>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>

RequestManager::RequestManager()
{

}

QString RequestManager::getToken(QByteArray array)
{
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QString response = itemObject["token"].toString();

    return  response;
    
}

QVector<Item> RequestManager::getItems(QByteArray array)
{
    
}

QStringList RequestManager::getFileList(QByteArray array)
{
    QStringList result;
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray fileArray = itemObject["message"].toArray();
    for(auto temp:fileArray){
      std::cout<<temp.toString().toStdString()<<std::endl;
      result.append(temp.toString());
    }
    return  result;

}
