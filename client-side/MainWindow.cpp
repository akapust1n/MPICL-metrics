#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ui_SelectFile.h"
#include "ui_Graphics.h"
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPixmap>
#include <QUrl>
#include <QUrlQuery>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , uiGR(new Ui::Graphics)
    , uiSF(new Ui::SelectFile)

{
    ui->setupUi(this);
    ui->passwordForm->setEchoMode(QLineEdit::Password);
    QPixmap pixmap("/home/alexey/16/PICL-metrics/client-side/loginIcon.png");
    ui->labeImg->resize(pixmap.width(), pixmap.height());
    ui->labeImg->setPixmap(pixmap);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->loginForm->text();
    QString password = ui->passwordForm->text();

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/authenticate");

    QUrlQuery query;

     query.addQueryItem("name", "Nick Cerminara");
    query.addQueryItem("password", "password");
   // query.addQueryItem("name", username);
   // query.addQueryItem("password", password);

    url.setQuery(query.query());
    request.setUrl(url);
    manager->get(request);

    //    if (username == "test" && password == "test") {
    //        QMessageBox::information(this, "Login", "Username and password is correct");
    //        //hide();

    //    } else {
    //        QMessageBox::warning(this, "Login", "Username and password is not correct");
    //    }
}

void MainWindow::replyFinished(QNetworkReply* reply)
{
    info.token = requestHandler.getToken(reply->readAll());
    if (info.token.isEmpty()) {
        QMessageBox::information(this, "Login", "Username or password is wrong");
        //        //hide();
    } else {
        uiGR->setupUi(this);
        QMessageBox::information(this, "Login", "Username and password is corrent");
    }
}

void MainWindow::on_loadButton_clicked()
{
    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getNumProcessors");


}
