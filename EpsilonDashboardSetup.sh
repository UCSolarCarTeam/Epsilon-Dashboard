#!/usr/bin/env bash
if [ "$(id -u)" != "0" ]; then
    echo "Permission Denied. Please run as root"
    exit 1
fi

echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list && sudo apt-get update && sudo apt-get install rabbitmq-server
apt-get install cmake openssl libssl-dev libblkid-dev e2fslibs-dev libaudit-dev software-properties-common build-essential mesa-common-dev libgl1-mesa-dev python3-pip
pip3 install --user conan
conan remote add conan-dbely https://api.bintray.com/conan/dbely/conan
