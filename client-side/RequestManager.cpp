#include "RequestHadler.h"
#include <iostream>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>

RequestHadler::RequestHadler()
{

}

QString RequestHadler::getToken(QByteArray array)
{
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QString response = itemObject["token"].toString();

    return  response;

}
