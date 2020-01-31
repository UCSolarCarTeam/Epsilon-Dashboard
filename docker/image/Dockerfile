FROM multiarch/ubuntu-core:armhf-bionic

MAINTAINER Liam Conway "contact@liamconway.me"
ENV DIR_IN /input
ENV DIR_OUT /output
ENV DIR_BUILD /build

# Update system packages
RUN apt-get update

# Install Solar Car dependencies
RUN apt-get install -y sudo wget git build-essential
RUN git clone --progress --verbose https://github.com/UCSolarCarTeam/Development-Resources.git && \
    ./Development-Resources/InstallScripts/googletest-setup.sh && \
    ./Development-Resources/InstallScripts/rabbitmq-setup.sh && \
    rm -rf ./Development-Resources

RUN apt-get install -y qt5-default qtdeclarative5-dev libqt5serialport5-dev

WORKDIR ${DIR_BUILD}
COPY make.sh .
RUN chmod 755 make.sh

CMD ["sh", "-c", "./make.sh"] 
