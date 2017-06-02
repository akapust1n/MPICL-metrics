#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <RequestManager.h>
#include <Info.h>
#include <TableManager.h>
#include <utility>
#include <NetworkManager.h>
#include "DataFilter.h"

namespace Ui {
class MainWindow;
class SelectFile;
class Graphics;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void loadFileListFinished();
    void loadNumProcessorsFinished();
    void loadTimeBordersFinished();
    void loginFinished();

    void on_loadFileListButton_clicked();

    void on_chooseFileButton_clicked();

    void on_loadDataButton_clicked();

    void on_detailButton_clicked();
    void showEventText(int row,int column);

private:
    void loadData();
private:
    Ui::MainWindow *ui;
    Ui::SelectFile *uiSF;
    Ui::Graphics *uiGR;
    TableManager *tableManager;
    Info *info;
    NetworkManager *networkManager;
    DataFilter *dataFilter;

    int statusRequest=0;
    int offset = 0;

};

#endif // MAINWINDOW_H
