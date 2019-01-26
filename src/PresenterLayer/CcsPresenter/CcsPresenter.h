#pragma once

#include <QObject>
class I_CcsData;

class CcsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit CcsPresenter(const I_CcsData& ccsData);

private:
    void relayCcsData();

    const I_CcsData& ccsData_;

signals:
    void ccsAliveRecieved(bool);
};
