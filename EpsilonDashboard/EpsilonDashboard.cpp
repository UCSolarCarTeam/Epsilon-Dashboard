#include <QCommandLineParser>

#include "../DataLayer/DataContainer.h"
#include "../CommunicationLayer/CommunicationContainer.h"
#include "../BusinessLayer/BusinessContainer.h"
#include "../PresenterLayer/PresenterContainer.h"
#include "../ViewLayer/ViewContainer.h"
#include "EpsilonDashboard.h"

EpsilonDashboard::EpsilonDashboard(int& argc, char** argv)
    : QApplication(argc, argv)
    , dataContainer_(new DataContainer())
    , communicationContainer_(new CommunicationContainer())
    , businessContainer_(new BusinessContainer(*communicationContainer_, *dataContainer_))
    , presenterContainer_(new PresenterContainer(*dataContainer_))
{
    QCommandLineParser parser;
    QCommandLineOption raceModeOption("r");
    QCommandLineOption debugModeOption("d");
    parser.addOption(raceModeOption);
    parser.addOption(debugModeOption);
    parser.process(*this);
    Mode mode = Mode::DISPLAY;

    if (parser.isSet(raceModeOption))
    {
        mode = Mode::RACE;
    }

    if (parser.isSet(debugModeOption))
    {
        mode = Mode::DEBUG;
    }

    viewContainer_.reset(new ViewContainer(*presenterContainer_, mode));
}

EpsilonDashboard::~EpsilonDashboard()
{
}
