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
    void  setRowCount(int count,int maxCount)  ;
private:
    QTableWidget *widget;
    QVector<int> rowPointers;

};

#endif // TABLEMANAGER_H
