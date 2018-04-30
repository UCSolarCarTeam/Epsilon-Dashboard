#pragma once
#include "I_ControlUi.h"
namespace Ui
{
    class ControlUi;
}

class ControlUi : public I_ControlUi
{
    Q_OBJECT
public:
    explicit ControlUi();
    ~ControlUi();
    QLabel& aliveIndicator();
    QLabel& lightsIndicator();
    QLabel& highHeadlightsLabel();
    QLabel& lowHeadlightsLabel();
    QLabel& lowBeamLabel();
    QLabel& highBeamLabel();
    QLabel& leftSignalLabel();
    QLabel& rightSignalLabel();
    QLabel& leftSignalActiveLabel();
    QLabel& rightSignalActiveLabel();
    QLabel& hazardOnLabel();
    QLabel& interiorOnLabel();
    QLabel& pushToTalkOnLabel();
    QLabel& hornOnLabel();
    QLabel& nextSongLabel();
    QLabel& prevSongLabel();
    QLabel& playPauseLabel();
    QLabel& volumeUpLabel();
    QLabel& volumeDownLabel();
    QLabel& brakesOnLabel();
    QLabel& brakesOnActiveLabel();
    QLabel& forwardOnLabel();
    QLabel& reverseOnLabel();
    QLabel& auxOnLabel();
    QLabel& resetOnLabel();
    QProgressBar& accelerationProgressBar();
    QProgressBar& regenBrakingProgressBar();
private:
    Ui::ControlUi* ui_;
};
