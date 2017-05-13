#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <RequestManager.h>
#include <Info.h>

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
    void loginFinished();
    void loadFileFinished();
    void loadNumProcessorsFinished();
    void loadDataSlice();

    
    void on_loadFileListButton_clicked();

    void on_chooseFileButton_clicked();

    void on_loadDataButton_clicked();

private:
    void loadData();
private:
    Ui::MainWindow *ui;
    Ui::SelectFile *uiSF;
    Ui::Graphics *uiGR;
    QNetworkAccessManager *manager;
    RequestManager requestHandler;
    Info info;
    QNetworkReply *reply;
    int statusRequest=0;
    int offset = 0;

};

#endif // MAINWINDOW_H
