#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <RequestHadler.h>
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
    void replyFinished(QNetworkReply*reply);

private:
    Ui::MainWindow *ui;
    Ui::SelectFile *uiSF;
    Ui::Graphics *uiGR;
    QNetworkAccessManager *manager;
    RequestHadler requestHandler;
    Info info;

};

#endif // MAINWINDOW_H
