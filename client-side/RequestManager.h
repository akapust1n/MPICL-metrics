#ifndef REQUESTHADLER_H
#define REQUESTHADLER_H
#include <Item.h>
#include <QByteArray>
#include <QString>
#include <QVector>
#include <QStringList>
#include <QJsonArray>
#include <utility>
#include <Info.h>

class RequestManager {
public:
    RequestManager();
    QString getToken(QByteArray array);
    QVector<Item> getItems(QByteArray array);
    QStringList getFileList(QByteArray array);
    int getNumProcessors(QByteArray array);
    int getNumRecords(QByteArray array);
    std::pair<double,double> getBordes(QByteArray array);
    eventStruct getEvent(QByteArray array);
private:
    Item fromQJsonArray(QJsonArray array, int index);

};

#endif // REQUESTHADLER_H
