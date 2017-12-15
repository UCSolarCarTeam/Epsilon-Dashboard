#pragma once

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

class I_JsonReceiver : public QObject
{
    Q_OBJECT
public:
    virtual ~I_JsonReceiver() {}

public slots:
    virtual void handleIncomingData(const QByteArray&) = 0;

signals:
    void dataReceived(const QJsonObject& data);
    void invalidDataReceived();
};
