#include "getdata.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <iostream>

GetData::GetData(QObject *parent) :
    QObject(parent),
    m_stats("START")
{
    download();
}

void GetData::download()
{
    replay = manager.get(QNetworkRequest(QUrl("https://corona.lmao.ninja/v2/countries/")));
    connect(replay, &QNetworkReply::finished, this, &GetData::processData);
    connect(replay, &QNetworkReply::downloadProgress, this, &GetData::progress);

    setStats("DOWNLOAD");
}

void GetData::processData()
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(QString(replay->readAll()).toUtf8());
    QJsonArray    jsonArray = jsonResponse.array();

    for(const QJsonValue &value : jsonArray)
    {
        QJsonObject obj = value.toObject();
        qDebug() << "country: " << obj.value("country").toString();
        setStats(obj.value("country").toString());
        break;
    }
    qDebug() << m_stats;
}

void GetData::progress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << bytesReceived <<  " " << bytesTotal;
}
