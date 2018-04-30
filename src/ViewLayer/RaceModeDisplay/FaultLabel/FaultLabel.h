#pragma once

#include <QString>
#include <QLabel>

class FaultLabel : public QLabel
{
public:
    FaultLabel();
    FaultLabel(QString name, QString color, int priority, bool isActive);
    FaultLabel(const FaultLabel& faultLabel);

    ~FaultLabel();

    QString name() const;
    QString color() const;
    int priority() const;
    bool isActive() const;

    void setIsActive(bool value);

private:

    //QString name_;
    QString color_;
    int priority_;
    bool isActive_;
};
