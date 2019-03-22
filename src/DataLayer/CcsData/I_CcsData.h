#pragma once

#include <QObject>

class I_CcsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_CcsData() {}

    virtual bool ccsAlive() const = 0;

    virtual void setCcsAlive(bool ccsAlive) = 0;

signals:
    void ccsAliveReceived(bool);
};
