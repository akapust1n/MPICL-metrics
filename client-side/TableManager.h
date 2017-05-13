#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H
#include <QTableWidget>
#include <QVector>
#include <Item.h>

class TableManager
{
public:
    TableManager(QTableWidget *_widget);
    void appendItems(QVector<Item> &items);
private:
    QTableWidget *widget;

};

#endif // TABLEMANAGER_H
