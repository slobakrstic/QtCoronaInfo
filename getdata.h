#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class GetData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString stats READ getStats WRITE setStats NOTIFY statsChanged)
public:
    explicit GetData(QObject *parent = nullptr);
    void download();
    QString getStats() const { return m_stats; }
    void setStats(QString stats) { m_stats.append(stats); emit statsChanged(); }

public slots:
    void processData();
    void progress(qint64 bytesReceived, qint64 bytesTotal);
signals:
    void statsChanged();


private:
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QNetworkReply *replay;
    QString m_stats;

};
