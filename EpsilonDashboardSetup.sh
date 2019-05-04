#!/usr/bin/env bash

echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list && sudo apt-get update && sudo apt-get install rabbitmq-server
sudo apt-get install cmake libboost-dev openssl libssl-dev libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev software-properties-common build-essential mesa-common-dev libgl1-mesa-dev
(
	cd /tmp/
	git clone https://github.com/UCSolarCarTeam/Development-Resources.git
	cd Development-Resources/InstallScripts
  	./rabbitmq-setup.sh 
  	./googletest-setup.sh 
)

(
  mkdir -p ./build/.lib 
  cp /usr/local/lib/libgmock.a ./build/.lib
)