#include "NetworkManager.h"
#include <QNetworkAccessManager>
#include <QUrlQuery>

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

void NetworkManager::loadData(QString filename, TableManager* _tableManager)
{
    tableManager = _tableManager;
    offset = 0;
    QUrlQuery query;
    query.addQueryItem("filename", filename);
    query.addQueryItem("limit", QString::number(limit));
    query.addQueryItem("offset", QString::number(offset));

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getFile");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadDataSliceFinished()));
}

void NetworkManager::loadData()
{
    QUrlQuery query;
    query.addQueryItem("filename", info->filename);
    query.addQueryItem("limit", QString::number(limit));
    query.addQueryItem("offset", QString::number(offset));

    QNetworkRequest request;
    QUrl url("http://localhost:8080/api/getFile");
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply, SIGNAL(finished()),
        this, SLOT(loadDataSliceFinished()));
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
    tableManager->appendItems(items);
    if (items.size()) {

        loadData();
    }
}

void NetworkManager::loadTimeBordersFinished()
{
    info->minMax= requestHandler.getBordes(reply->readAll());
    emit loadTimeBordersFinishedOut();

}
