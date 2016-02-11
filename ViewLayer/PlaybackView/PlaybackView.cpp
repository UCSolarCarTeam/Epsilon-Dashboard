/**
 *  Gen 5 Dashboard
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Gen 5 Dashboard
 *
 *  The Gen 5 Dashboard is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Gen 5 Dashboard is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Gen 5 Dashboard.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QDateTime>
#include <QFileDialog>
#include <QTimer>

#include "../../PresenterLayer/PlaybackPresenter/PlaybackPresenter.h"
#include "../PlaybackUI/I_PlaybackUI.h"
#include "PlaybackView.h"

namespace
{
   const int SLIDER_UPDATE_FREQUENCY = 400;
}

PlaybackView::PlaybackView(PlaybackPresenter& playbackPresenter,
   I_PlaybackUI& ui)
: playbackPresenter_(playbackPresenter)
, ui_(ui)
, lastPosition_(0)
, sliderUpdateTimer_(new QTimer)
{
   connect(&ui_.openButton(), SIGNAL(clicked()), this, SLOT(handleOpenFile()));
   connect(&ui_.exitButton(), SIGNAL(clicked()), this, SLOT(handleCloseButton()));
   connect(&playbackPresenter_, SIGNAL(positionRangeUpdated(int, int)),
      this, SLOT(handleSliderRangesUpdated(int, int)));
   connect(&playbackPresenter_, SIGNAL(dateUpdated(const QDateTime&)),
      this, SLOT(handleDateUpdated(const QDateTime&)));

   sliderUpdateTimer_->setSingleShot(false);
   sliderUpdateTimer_->setInterval(SLIDER_UPDATE_FREQUENCY);
   sliderUpdateTimer_->start();

   connect(sliderUpdateTimer_.data(), SIGNAL(timeout()),
      this, SLOT(handleTimeout()));
}

PlaybackView::~PlaybackView()
{
}

void PlaybackView::handleOpenFile()
{
   QString fileName = QFileDialog::getOpenFileName();
   playbackPresenter_.loadFile(fileName);
}

void PlaybackView::handleCloseButton()
{
   ui_.hide();
}

void PlaybackView::handleSliderRangesUpdated(int min, int max)
{
   ui_.playbackPositionSlider().setMinimum(min);
   ui_.playbackPositionSlider().setMaximum(max);
   ui_.playbackPositionSlider().setSliderPosition(0);
}

void PlaybackView::handleDateUpdated(const QDateTime& date)
{
   ui_.playbackTimeLabel().setText(date.toString("Thh:mm:ss:zzz"));
}

void PlaybackView::handleTimeout()
{
   if (lastPosition_ != ui_.playbackPositionSlider().sliderPosition())
   {
      lastPosition_ = ui_.playbackPositionSlider().sliderPosition();
      playbackPresenter_.loadPosition(lastPosition_);
   }
}
