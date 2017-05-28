#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H
#include <Info.h>
#include <Item.h>
#include <QTableWidget>
#include <QVector>

class TableManager {
public:
    TableManager(QTableWidget* _widget);
    void appendItems(QVector<Item>& items);
    void setRowCount(int count, int maxCount);
    void detailTypes(Info* info);
    QTableWidgetItem* getItem(int row, int column);
    int columnCount() const;
    int rowCount() const;
    int getCellEventCode(int row, int column);


private:
    QTableWidget* widget;
    QVector<int> rowPointers;
};

#endif // TABLEMANAGER_H
