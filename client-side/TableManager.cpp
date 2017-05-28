#include "TableManager.h"
#include <QTableWidgetItem>
#include <iostream>

TableManager::TableManager(QTableWidget* _widget)
    : widget(_widget)
{
//    rowPointers.resize(20); // :)
//    for(int i=0;i<20;i++)
//        rowPointers[i]=0;
}

void TableManager::appendItems(QVector<Item>& items)
{
    for (auto item : items) {
        QTableWidgetItem *m_item= new QTableWidgetItem(QString::number(item.time)+QString(" ev ")+QString::number(item.typeEvent));
        int size = rowPointers.size();
        int itemID=item.prid;
        if((rowPointers[itemID]+2)>widget->columnCount()){
            int cc=widget->columnCount();
             widget->setColumnCount(cc+1);
        }

        widget->setItem(itemID,rowPointers[itemID],m_item);
        rowPointers[itemID]+=1;

    }


}

void TableManager::setRowCount(int count, int maxCount)
{
    widget->clear();

    widget->setColumnCount(5);

    widget->setRowCount(count + 1);
    rowPointers.resize(maxCount); // :)
    for(int i=0;i<maxCount;i++)
        rowPointers[i]=0;

}

void TableManager::detailTypes(Info *info)
{

}
