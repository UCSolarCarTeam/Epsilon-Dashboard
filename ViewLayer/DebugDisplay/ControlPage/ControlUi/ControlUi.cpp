#include "ControlUi.h"
#include "ui_ControlUi.h"

ControlUi::ControlUi() :
    ui_(new Ui::ControlUi)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background;
    background.setBrush(QPalette::Background, bkgnd);
    this->setPalette(background);
}

ControlUi::~ControlUi()
{
    delete ui_;
}

QWidget& ControlUi::aliveIndicator()
{
    return *ui_->aliveIndicator;
}

QLabel& ControlUi::highHeadlightsLabel()
{
    return *ui_->highHeadlightsLabel;
}

QLabel& ControlUi::lowHeadlightsLabel()
{
    return *ui_->lowHeadlightsLabel;
}

QLabel& ControlUi::leftSignalLabel()
{
    return *ui_->leftSignalLabel;
}

QLabel& ControlUi::rightSignalLabel()
{
    return *ui_->rightSignalLabel;
}

QLabel& ControlUi::hazardOnLabel()
{
    return *ui_->hazardOnLabel;
}

QLabel& ControlUi::interiorOnLabel()
{
    return *ui_->interiorOnLabel;
}

QLabel& ControlUi::pushToTalkOnLabel()
{
    return *ui_->pushToTalkOnLabel;
}

QLabel& ControlUi::hornOnLabel()
{
    return *ui_->hornOnLabel;
}


QLabel& ControlUi::nextSongLabel()
{
    return *ui_->nextSongLabel;
}

QLabel& ControlUi::prevSongLabel()
{
    return *ui_->prevSongLabel;
}

QLabel& ControlUi::playPauseLabel()
{
    return *ui_->playPauseLabel;
}

QLabel& ControlUi::volumeUpLabel()
{
    return *ui_->volumeUpLabel;
}

QLabel& ControlUi::volumeDownLabel()
{
    return *ui_->volumeDownLabel;
}

QLabel& ControlUi::brakesOnLabel()
{
    return *ui_->brakesOnLabel;
}

QLabel& ControlUi::forwardOnLabel()
{
    return *ui_->forwardOnLabel;
}

QLabel& ControlUi::reverseOnLabel()
{
    return *ui_->reverseOnLabel;
}

QLabel& ControlUi::auxOnLabel()
{
    return *ui_->auxOnLabel;
}

QLabel& ControlUi::resetOnLabel()
{
    return *ui_->resetOnLabel;
}

QProgressBar& ControlUi::accelerationProgressBar()
{
    return *ui_->accelerationProgressBar;
}

QProgressBar& ControlUi::regenBrakingProgressBar()
{
    return *ui_->regenBrakingProgressBar;
}
