TEMPLATE = app
LIBS += -L../../build/.lib -lViewLayer -lCommunicationLayer -lBusinessLayer -lDataLayer -lPresenterLayer

! include(../common.pri){
    error("Could not find common.pri file!")
}
PRE_TARGETDEPS += \
 ../../build/.lib/*

TARGET = EpsilonDashboard

DESTDIR = ../../build

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
    ../Resources/LowHeadlightIndicator.png
