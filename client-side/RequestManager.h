#ifndef REQUESTHADLER_H
#define REQUESTHADLER_H
#include <QString>
#include <QByteArray>
#include <QVector>
#include <Item.h>

class RequestManager
{
public:
    RequestManager();
    QString getToken(QByteArray array);
   QVector<Item> getItems(QByteArray array);
};

#endif // REQUESTHADLER_H
