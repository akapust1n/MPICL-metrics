#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include "Info.h"
#include "TableManager.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <RequestManager.h>
#include "DataFilter.h"

class NetworkManager : public QObject {
    Q_OBJECT

public:
    NetworkManager(Info* _info);
    ~NetworkManager();
    void login(QString name, QString password);
    void loadFileList();
    void loadNumProcessors(QString filename);
    void loadTimeBorders(QString filename);
    void loadData(QString filename, TableManager* _tableManager);
    void loadData();

public slots:
signals:
    void loginFinishedOut();
    void loadFileListFinishedOut();
    void loadTimeBordersFinishedOut();
    void loadNumProcessorsFinishedOut();

private slots:
    void loginFinished();
    void loadFileListFinished();
    void loadNumProcessorsFinished();
    void loadDataSliceFinished();
    void loadTimeBordersFinished();

private:
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    RequestManager requestHandler;
    Info* info;
    TableManager* tableManager;
    int offset = 0;
    int limit = 5;
    int offsetStep = 5;
};

#endif // NETWORKMANAGER_H
