#include "TableManager.h"
#include <QTableWidgetItem>

TableManager::TableManager(QTableWidget* _widget)
    : widget(_widget)
{
}

void TableManager::appendItems(QVector<Item>& items)
{
    for (auto item : items) {
        QTableWidgetItem *m_item= new QTableWidgetItem(QString::number(item.time)+QString(" ev ")+QString::number(item.typeEvent));
        widget->setItem(item.prid,rowPointers[item.prid],m_item);
        rowPointers[item.prid]++;
         if(rowPointers[item.prid]>widget->columnCount()){
              widget->setColumnCount(widget->columnCount() +1);
         }


    }
}

void TableManager::setRowCount(int count)
{
    widget->setColumnCount(5);
    widget->setRowCount(count + 1);
    rowPointers.clear();
    rowPointers.resize(count + 1);
    for (auto &t : rowPointers)
        t = 0;
}
