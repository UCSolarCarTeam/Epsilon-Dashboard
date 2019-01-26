#pragma once

#include "../DataLayer/CcsData/I_CcsData.h"
#include <QObject>

class I_CcsData;

class CcsPopulator : public QObject
{
    Q_OBJECT
public:
    CcsPopulator(I_CcsData& ccsData);
    virtual ~CcsPopulator(){}

public slots:
    void populateData(const QJsonObject&);

private:
    I_CcsData& ccsData_;
};
