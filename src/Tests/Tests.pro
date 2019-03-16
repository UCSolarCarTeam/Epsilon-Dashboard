TEMPLATE = app
QT += testlib
CONFIG += testcase

LIBS += -L../../build/.lib -lBusinessLayer -lgmock -lViewLayer -lCommunicationLayer -lInfrastructureLayer -lDataLayer -lPresenterLayer

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CommunicationLayer/JsonReceiver/JsonReceiverTest.cpp \
    testmain.cpp


!win32 {
    QMAKE_CXXFLAGS +=
}

DESTDIR = ../../build/tests/

copyfiles.commands = cp testconfig.ini $${DESTDIR}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

HEADERS += \
    CommunicationLayer/mockcommdevicemanager.h \
    BusinessLayer/DataPopulators/mockauxbmspopulator.h \
    BusinessLayer/DataPopulators/mockbatteryfaultspopulator.h \
    BusinessLayer/DataPopulators/mockbatterypopulator.h \
    BusinessLayer/DataPopulators/mockdrivercontrolspopulator.h \
    BusinessLayer/DataPopulators/mockkeymotorpopulator.h \
    BusinessLayer/DataPopulators/mocklightspopulator.h \
    BusinessLayer/DataPopulators/mockmpptpopulator.h \
    BusinessLayer/DataPopulators/mockmotordetailspopulator.h \
    BusinessLayer/DataPopulators/mockmotorfaultspopulator.h \
    BusinessLayer/CommunicationsMonitoringService/mock_communicationsmonitoringservice.h

