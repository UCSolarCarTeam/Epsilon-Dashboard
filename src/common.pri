INCLUDEPATH += .
QT+=core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += static c++11

QMAKE_CXXFLAGS += -Wno-expansion-to-defined
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

LIBS += -lSimpleAmqpClient -lrabbitmq
