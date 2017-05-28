#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include "Info.h"
#include "TableManager.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <RequestManager.h>
#include "DataFilter.h"
#include <QProgressBar>

class NetworkManager : public QObject {
    Q_OBJECT

public:
    NetworkManager(Info* _info);
    ~NetworkManager();
    void login(QString name, QString password);
    void loadFileList();
    void loadNumProcessors(QString filename);
    void loadNumRecords(QString filename);

    void loadTimeBorders(QString filename);
    void loadData(QString filename, TableManager* _tableManager, QProgressBar *_progressBar);
    void loadData();
    void continueLoadData();
    void detailData();

public slots:
signals:
    void loginFinishedOut();
    void loadFileListFinishedOut();
    void loadTimeBordersFinishedOut();
    void loadNumProcessorsFinishedOut();
    void loadNumRecordsFinishedOut();

private slots:
    void loginFinished();
    void loadFileListFinished();
    void loadNumProcessorsFinished();
    void loadDataSliceFinished();
    void loadTimeBordersFinished();
    void loadNumRecordsFinished();

private:
    void loadDetailCodeFinished(int row, int column);

private:
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    RequestManager requestHandler;
    Info* info;
    TableManager* tableManager;
    QProgressBar *progressBar;
    int progressCount;
    int offset = 0;
    int limit = 5;
    int offsetStep = 5;
    eventStruct currentEvent;
};

#endif // NETWORKMANAGER_H
