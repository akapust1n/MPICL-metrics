#include "MainWindow.h"
#include "ui_Graphics.h"
#include "ui_MainWindow.h"
#include "ui_SelectFile.h"
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPixmap>
#include <QStringList>
#include <QUrl>
#include <QUrlQuery>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , uiGR(new Ui::Graphics)
    , uiSF(new Ui::SelectFile)
    , info(new Info)
{
    ui->setupUi(this);
    networkManager = (new NetworkManager(info));
    dataFilter = new DataFilter(info);

    ui->passwordForm->setEchoMode(QLineEdit::Password);
    QPixmap pixmap("/home/alexey/16/PICL-metrics/client-side/loginIcon.png");
    ui->labeImg->resize(pixmap.width(), pixmap.height());
    ui->labeImg->setPixmap(pixmap);
    // connect(manager, SIGNAL(finished(QNetworkReply*)),
    //   this, SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete tableManager;
    delete ui;
    delete uiSF;
    delete uiGR;
    delete networkManager;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->loginForm->text();
    QString password = ui->passwordForm->text();
    connect(networkManager, SIGNAL(loginFinishedOut()), this, SLOT(loginFinished()));
    networkManager->login(username, password);

    //    if (username == "test" && password == "test") {
    //        QMessageBox::information(this, "Login", "Username and password is correct");
    //        //hide();

    //    } else {
    //        QMessageBox::warning(this, "Login", "Username and password is not correct");
    //    }
}

void MainWindow::loadFileListFinished()
{
    QStringList fileList = info->fileList;
    uiSF->listFiles->clear();
    uiSF->listFiles->addItems(fileList);
}

void MainWindow::loadNumProcessorsFinished()
{

    std::cout << "NUM PROC " << info->numProcessors << std::endl;
    uiGR->numProc->setText(QString::number(info->numProcessors));
    uiGR->maxProcEdit->setValidator(new QIntValidator(0, info->numProcessors, this));
    connect(networkManager, SIGNAL(loadTimeBordersFinishedOut()), this, SLOT(loadTimeBordersFinished()));
    networkManager->loadTimeBorders(info->filename);
}

void MainWindow::loadTimeBordersFinished()
{
    uiGR->minTimeValue->setText(QString::number(info->minMax.first));
    uiGR->maxTimeValue->setText(QString::number(info->minMax.second));

    QDoubleValidator* validator = new QDoubleValidator(0, info->minMax.second, 10, this);
    QLocale locale(QLocale::English);

    validator->setLocale(locale);
    uiGR->startTimeEdit->setValidator(validator);
    uiGR->endTimeEdit->setValidator(validator);
}

void MainWindow::loginFinished()
{
    if (info->token.isEmpty()) {
        QMessageBox::information(this, "Login", "Username or password is wrong");
        //        //hide();
    } else {
        uiSF->setupUi(this);
        // QMessageBox::information(this, "Login", "Username and password is corrent");
    }
}

void MainWindow::on_loadFileListButton_clicked()
{
    networkManager->loadFileList();
    connect(networkManager, SIGNAL(loadFileListFinishedOut()), this, SLOT(loadFileListFinished()));
}

void MainWindow::on_chooseFileButton_clicked()
{
    if (!uiSF->listFiles->selectedItems().isEmpty()) {
        QString filename = uiSF->listFiles->currentItem()->text();
        info->filename = filename;

        uiGR->setupUi(this);
        connect(networkManager, SIGNAL(loadNumProcessorsFinishedOut()), this, SLOT(loadNumProcessorsFinished()));
        networkManager->loadNumProcessors(filename);

        tableManager = new TableManager(uiGR->timeline);

    } else {
        QMessageBox::information(this, "Error", "File unselected!");
    }
}

void MainWindow::on_loadDataButton_clicked()
{
    int numProcessors = uiGR->numProc->text().toInt();
    std::pair<double, double> minMax = std::make_pair(uiGR->startTimeEdit->text().toDouble(), uiGR->endTimeEdit->text().toDouble());
    if (!dataFilter->checkMinMaxTime(minMax.first, minMax.second)) {
        QMessageBox::information(this, "Error", "Incorrect data!");
        return;
    }
    tableManager->setRowCount(info->numProcessors);
    networkManager->loadData(info->filename, tableManager);

    //networkManager->loadNumProcessors(info->filename);
}
