TEMPLATE = app
LIBS += \
    -L../ViewLayer/.lib -lViewLayer \
    -L../CommunicationLayer/.lib -lCommunicationLayer \
    -L../BusinessLayer/.lib -lBusinessLayer \
    -L../DataLayer/.lib -lDataLayer \
    -L../PresenterLayer/.lib -lPresenterLayer \
    -L../InfrastructureLayer/.lib -lInfrastructureLayer

! include(../common.pri){
    error("Could not find common.pri file!")
}

CONFIG += conan_basic_setup
! include($$OUT_PWD/../conanbuildinfo.pri) {
    error("Could not find conanbuildinfo.pri file!")
}

LIBS += -ldl

PRE_TARGETDEPS += \
    ../ViewLayer/.lib/* \
    ../CommunicationLayer/.lib/* \
    ../BusinessLayer/.lib/* \
    ../DataLayer/.lib/* \
    ../PresenterLayer/.lib/* \
    ../InfrastructureLayer/.lib/*

TARGET = EpsilonDashboard

DESTDIR = ../bin

SOURCES += \
    main.cpp \
    EpsilonDashboard.cpp

HEADERS += \
    EpsilonDashboard.h

RESOURCES += \
    ../ViewLayer/uiresources.qrc

DISTFILES += \
    ../Resources/Background1.png \
    ../Resources/MainTitleBar.png \
    ../Resources/MenuButton.png \
    ../Resources/Solar Car Team Logo.png \
    ../Resources/Solar Car Team Symbol.png \
    ../Resources/SubTitleBar.png \
    ../Resources/Solar Car Team Icon.ico \
    ../Resources/Solar Car Team Logo.png \
    ../Resources/Solar Car Team Symbol.png \
    ../Resources/Solar Car Team Icon.ico \
    ../Resources/BrowseButton.png \
    ../Resources/HighHeadlightIndicator.png \
    ../Resources/LowHeadlightIndicator.png \
    ../Resources/SolarCarTeam.png

copyconfigfile.commands = cp $$PWD/../config.ini.example ../bin/config.ini
QMAKE_EXTRA_TARGETS += copyconfigfile
POST_TARGETDEPS += copyconfigfile