#pragma once
#include <QWidget>
#include <QLabel>
#include <QProgressBar>

class I_ControlUi: public QWidget
{
public:
    virtual ~I_ControlUi() {}
    virtual QWidget& aliveIndicator() = 0;
    virtual QLabel& highHeadlightsLabel() = 0;
    virtual QLabel& lowHeadlightsLabel() = 0;
    virtual QLabel& leftSignalLabel() = 0;
    virtual QLabel& rightSignalLabel() = 0;
    virtual QLabel& hazardOnLabel() = 0;
    virtual QLabel& interiorOnLabel() = 0;
    virtual QLabel& pushToTalkOnLabel() = 0;
    virtual QLabel& hornOnLabel() = 0;
    virtual QLabel& nextSongLabel() = 0;
    virtual QLabel& prevSongLabel() = 0;
    virtual QLabel& playPauseLabel() = 0;
    virtual QLabel& volumeUpLabel() = 0;
    virtual QLabel& volumeDownLabel() = 0;
    virtual QLabel& brakesOnLabel() = 0;
    virtual QLabel& forwardOnLabel() = 0;
    virtual QLabel& reverseOnLabel() = 0;
    virtual QLabel& auxOnLabel() = 0;
    virtual QLabel& resetOnLabel() = 0;
    virtual QProgressBar& accelerationProgressBar() = 0;
    virtual QProgressBar& regenBrakingProgressBar() = 0;
};
