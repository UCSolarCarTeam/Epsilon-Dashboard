#!/usr/bin/env bash
if [ "$(id -u)" != "0" ]; then
    echo "Permission Denied. Please run as root"
    exit 1
fi

echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list && sudo apt-get update && sudo apt-get install rabbitmq-server
sudo apt-get install cmake libboost-dev openssl libssl-dev libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev software-properties-common build-essential mesa-common-dev libgl1-mesa-dev
(
	cd /tmp/
	git clone https://github.com/UCSolarCarTeam/Development-Resources.git
	sudo ./Development-Resources/InstallScripts/googletest-setup.sh
	sudo ./Development-Resources/InstallScripts/rabbitmq-setup.sh
)

if [ ! -f build/config.ini ]; then
    cp src/config.ini.example build/config.ini
fi
