#pragma once

#include <QLabel>
#include <QObject>

#include "../../../../DataLayer/MpptData/Mppt.h"
#include "../../../../PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "../MPPTUi/I_MpptUi.h"

class I_MpptUi;
class MpptPresenter;

class MpptView : public QObject
{
    Q_OBJECT
public:
    MpptView(MpptPresenter& mpptPresenter,
             I_MpptUi& ui);
    ~MpptView();

private:
    void connectMppt(MpptPresenter&);

    MpptPresenter& mpptPresenter_;

    double mpptZeroPower_;
    double mpptOnePower_;
    double mpptTwoPower_;

    I_MpptUi& ui_;

private slots:
    void mpptReceived(int, Mppt);
};
