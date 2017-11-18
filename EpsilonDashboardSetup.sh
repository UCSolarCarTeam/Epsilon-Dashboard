#!/usr/bin/env bash

echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list && sudo apt-get update && sudo apt-get install rabbitmq-server
sudo apt-get install cmake libboost-dev openssl libssl-dev libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev software-properties-common build-essential mesa-common-dev libgl1-mesa-dev

cd /tmp/
if ls /usr/local/lib/librabbitmq.* 1> /dev/null 2>&1 ;
then
echo "Rabbitmq already setup"
else
git clone https://github.com/alanxz/rabbitmq-c
mkdir rabbitmq-c/build && cd rabbitmq-c/build
cmake ..
cmake --build .
sudo cp librabbitmq/*.a /usr/local/lib/
sudo cp librabbitmq/*.so* /usr/local/lib/
fi

cd /tmp/
if ls /usr/local/libSimpleAmqpClient.* 1> /dev/null 2>&1 || [ -d /usr/local/include/SimpleAmqpClient ];
then
echo "SimpleAmqpClient already setup"
else
git clone https://github.com/alanxz/SimpleAmqpClient
mkdir SimpleAmqpClient/build && cd SimpleAmqpClient/build
cmake -DRabbitmqc_INCLUDE_DIR=../../rabbitmq-c/librabbitmq -DRabbitmqc_LIBRARY=../../rabbitmq-c/build/librabbitmq ..
make
sudo mkdir /usr/local/include/SimpleAmqpClient
sudo cp *.so* /usr/local/lib/
sudo cp ../src/SimpleAmqpClient/*.h /usr/local/include/SimpleAmqpClient
fi
