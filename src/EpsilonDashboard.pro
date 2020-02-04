TEMPLATE = subdirs 

CONFIG += ordered static

message(University of Calgary Solar Car Team Epsilon Dashboard)

SUBDIRS = \
    ViewLayer \
    PresenterLayer \ 
    BusinessLayer \ 
    InfrastructureLayer \
    CommunicationLayer \
    DataLayer \
    EpsilonDashboard \
    Tests \

DISTFILES += \
    .travis.yml \
    config.ini

system(cd $$OUT_PWD; conan install .. --build=outdated -s compiler.libcxx="libstdc++11")
