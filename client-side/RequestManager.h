#ifndef REQUESTHADLER_H
#define REQUESTHADLER_H
#include <Item.h>
#include <QByteArray>
#include <QString>
#include <QVector>
#include <QStringList>

class RequestManager {
public:
    RequestManager();
    QString getToken(QByteArray array);
    QVector<Item> getItems(QByteArray array);
    QStringList getFileList(QByteArray array);

};

#endif // REQUESTHADLER_H
