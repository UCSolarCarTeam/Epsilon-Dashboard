#include <QCommandLineParser>

#include "../DataLayer/DataContainer.h"
#include "../CommunicationLayer/CommunicationContainer.h"
#include "../BusinessLayer/BusinessContainer.h"
#include "../PresenterLayer/PresenterContainer.h"
#include "../ViewLayer/ViewContainer.h"
#include "../InfrastructureLayer/InfrastructureContainer.h"
#include "EpsilonDashboard.h"

#include <QString>

namespace
{
    const char* RACE_QUEUE = "raceQueue";
    const char* DISPLAY_QUEUE = "displayQueue";
    const char* DEBUG_QUEUE = "debugQueue";
}

EpsilonDashboard::EpsilonDashboard(int& argc, char** argv)
    : QApplication(argc, argv)
    , infrastructureContainer_(new InfrastructureContainer())
    , dataContainer_(new DataContainer())
    , businessContainer_(new BusinessContainer(*dataContainer_))
    , presenterContainer_(new PresenterContainer(*dataContainer_))
{
    QCommandLineParser parser;
    QCommandLineOption raceModeOption("r");
    QCommandLineOption debugModeOption("d");
    QCommandLineOption windowedMode("w");
    parser.addOption(raceModeOption);
    parser.addOption(debugModeOption);
    parser.addOption(windowedMode);

    parser.process(*this);
    Mode mode = Mode::DISPLAY;

    if (parser.isSet(raceModeOption))
    {
        mode = Mode::RACE;
        infrastructureContainer_->setQueueName(RACE_QUEUE);

        if(parser.isSet(windowedMode))
        {
            //launch it in windowed mode
        }
    }
    else if (parser.isSet(debugModeOption))
    {
        mode = Mode::DEBUG;
        infrastructureContainer_->setQueueName(DEBUG_QUEUE);

        if(parser.isSet(windowedMode))
        {
            //launch it in windowed mode
        }

    }
    else
    {
        infrastructureContainer_->setQueueName(DISPLAY_QUEUE);

        if(parser.isSet(windowedMode))
        {
            //launch it in windowed mode
        }
    }

    viewContainer_.reset(new ViewContainer(*presenterContainer_, mode));
    communicationContainer_.reset(new CommunicationContainer(*businessContainer_, *infrastructureContainer_));
}

EpsilonDashboard::~EpsilonDashboard()
{
}
