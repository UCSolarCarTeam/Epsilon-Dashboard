TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
    InfrastructureContainer.h \
    Settings/Settings.h \
    Settings/I_Settings.h \

SOURCES += \
    InfrastructureContainer.cpp \
    Settings/Settings.cpp \
