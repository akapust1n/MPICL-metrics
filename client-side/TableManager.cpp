#include "TableManager.h"
#include <QTableWidgetItem>
#include <iostream>
#include <Info.h>
#include <QVector>

TableManager::TableManager(QTableWidget* _widget)
    : widget(_widget)
{
    //    rowPointers.resize(20); // :)
    //    for(int i=0;i<20;i++)
    //        rowPointers[i]=0;
}

void TableManager::appendItems(QVector<Item>& items,Info *info)
{
    for (auto item : items) {

        QString itemData = QString::number(item.time) + QString(" ev ") + QString::number(item.typeEvent) + QString("\n");
        if (item.destination != -1){
            itemData += QString(" dest: ") + QString::number(item.destination);
            info->threads[item.destination]++;
        }
        QTableWidgetItem* m_item = new QTableWidgetItem(itemData);
        int itemID = item.prid;
        if ((rowPointers[itemID] + 2) > widget->columnCount()) {
            int cc = widget->columnCount();
            widget->setColumnCount(cc + 1);
        }

        widget->setItem(itemID, rowPointers[itemID], m_item);
        rowPointers[itemID] += 1;
    }
}

void TableManager::setRowCount(int count, int maxCount)
{
    widget->clear();

    widget->setColumnCount(5);

    widget->setRowCount(count + 1);
    rowPointers.resize(maxCount); // :)
    for (int i = 0; i < maxCount; i++)
        rowPointers[i] = 0;
}

void TableManager::detailTypes(Info* info)
{
}

int TableManager::columnCount() const
{
    return widget->columnCount();
}

int TableManager::rowCount() const
{
    return widget->rowCount();
}

int TableManager::getCellEventCode(int row, int column)
{
    QString cellText = widget->item(row, column) ? widget->item(row, column)->text() : "";
    if (cellText.isEmpty())
        return 0;
    int code = cellText.split(" ")[2].toInt();
    return code;
}

void TableManager::appendCellInfo(int row, int column, eventStruct event)
{
    QString currentText = widget->item(row, column)->text();
    QString newText = QString("\n") + QString("name: ") + event.name + QString("\n");
    newText += QString("category: ") + event.category + QString("\n");
    if(event.category=="send events")
        widget->item(row,column)->setBackground(Qt::red);
    if(event.category=="receive events")
        widget->item(row,column)->setBackground(Qt::green);
    newText += QString("description: ") + event.description;
    QString result = currentText + newText;
    widget->item(row, column)->setText(result);
}

void TableManager::analyzeEvents(Info *info)
{
    std::vector<int> temp=info->threads;
    int _rowCount = rowCount();
    int _columnCount = columnCount();
    for (int i = 0; i < _rowCount; i++)
        for (int j = 0; j < _columnCount - 1; j++) {
            if(widget->item(i,j)){
            if(widget->item(i,j)->background()==Qt::green)
            temp[i]--;
            if(temp[i]<0 and widget->item(i,j)->background()==Qt::red)
                widget->item(i,j)->setBackground(Qt::lightGray);
            }
           // std::cout << "AFTER DETAIL" << std::endl;
        }

}
