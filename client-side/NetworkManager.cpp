#include "NetworkManager.h"
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QProgressBar>
#include <QUrlQuery>
#include <iostream>

NetworkManager::NetworkManager(Info* _info)
    : info(_info)
{
    manager = new QNetworkAccessManager(this);
}

NetworkManager::~NetworkManager()
{
    delete manager;
    delete reply;
}

void NetworkManager::login(QString name, QString password)
{
    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/authenticate");

    QUrlQuery query;

    query.addQueryItem("name", "Nick Cerminara");
    query.addQueryItem("password", "password");
    // query.addQueryItem("name", username);
    // query.addQueryItem("password", password);

    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loginFinished()));
}

void NetworkManager::loadFileList()
{
    QUrlQuery query;
    query.addQueryItem("name", "Nick Cerminara");

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getFileList");

    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadFileListFinished()));
}

void NetworkManager::loadNumProcessors(QString filename)
{
    QUrlQuery query;
    query.addQueryItem("filename", filename);

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getNumProcessors");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadNumProcessorsFinished()));
}

void NetworkManager::loadNumRecords(QString filename)
{
    QUrlQuery query;
    query.addQueryItem("filename", filename);
    query.addQueryItem("timeMin", QString::number(info->minMax.first));
    query.addQueryItem("timeMax", QString::number(info->minMax.second));

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getNumRecords");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), this, SLOT(loadNumRecordsFinished()));
    loop.exec();

}

void NetworkManager::loadTimeBorders(QString filename)
{
    QUrlQuery query;

    query.addQueryItem("filename", filename);
    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getTimeBorders");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadTimeBordersFinished()));
}

void NetworkManager::loadData(QString filename, TableManager* _tableManager, QProgressBar* _progressBar)
{
    tableManager = _tableManager;
    offset = 0;
    progressBar = _progressBar;
    progressCount = 5;
    loadNumRecords(filename);
}

void NetworkManager::loadData()
{
    QUrlQuery query;
    query.addQueryItem("filename", info->filename);
    query.addQueryItem("limit", QString::number(limit));
    query.addQueryItem("offset", QString::number(offset));
    query.addQueryItem("timeMin", QString::number(info->minMax.first));
    query.addQueryItem("timeMax", QString::number(info->minMax.second));

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getFile");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadDataSliceFinished()));
}

void NetworkManager::continueLoadData()
{
    QUrlQuery query;
    query.addQueryItem("filename", info->filename);
    query.addQueryItem("limit", QString::number(limit));
    query.addQueryItem("offset", QString::number(offset));
    query.addQueryItem("timeMin", QString::number(info->minMax.first));
    query.addQueryItem("timeMax", QString::number(info->minMax.second));

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getFile");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadDataSliceFinished()));
}

void NetworkManager::detailData( QProgressBar *_progressBar)
{
    progressBar=_progressBar;
   // progressBar->setValue(0);
    progressCount = 0;
    int rowCount = tableManager->rowCount();
    int columnCount = tableManager->columnCount();
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < columnCount - 1; j++) {
            progressCount++;
             progressBar->setValue(progressCount*1.0/(rowCount*(columnCount-1))*100);
            int code = tableManager->getCellEventCode(i, j);
            if (!code)
                continue;
            QUrlQuery query;
            query.addQueryItem("code", QString::number(code));

            QNetworkRequest request;
            QUrl url("http://localhost:8080/api/getCodeInfo");
            url.setQuery(query.query());
            request.setUrl(url);
            reply = manager->get(request);
            QEventLoop loop;
            connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
            loop.exec();
            loadDetailCodeFinished(i, j);

           // std::cout << "AFTER DETAIL" << std::endl;
        }
}

void NetworkManager::loginFinished()
{
    info->token = requestHandler.getToken(reply->readAll());
    emit loginFinishedOut();
}

void NetworkManager::loadFileListFinished()
{
    info->fileList = requestHandler.getFileList(reply->readAll());
    emit loadFileListFinishedOut();
}

void NetworkManager::loadNumProcessorsFinished()
{
    info->numProcessors = requestHandler.getNumProcessors(reply->readAll());
    emit loadNumProcessorsFinishedOut();
}

void NetworkManager::loadDataSliceFinished()
{
    auto items = requestHandler.getItems(reply->readAll());
    offset += offsetStep;
    tableManager->appendItems(items,info);
    if (items.size()) {
        progressCount += 5; //должно быть после дата лоада, но не суть
       // std::cout << progressCount * 1.0 / info->numRecords * 100 << std::endl;
        progressBar->setValue(static_cast<int>(progressCount * 1.0 / info->numRecords * 100));
        loadData();
    }
}

void NetworkManager::loadTimeBordersFinished()
{
    info->minMax = requestHandler.getBordes(reply->readAll());
    emit loadTimeBordersFinishedOut();
}

void NetworkManager::loadNumRecordsFinished()
{
    info->numRecords = requestHandler.getNumRecords(reply->readAll());

    emit loadNumRecordsFinishedOut();
    continueLoadData();
}

void NetworkManager::loadDetailCodeFinished(int row, int column)
{
    currentEvent = requestHandler.getEvent(reply->readAll());
    tableManager->appendCellInfo(row,column,currentEvent);
}
