#!/usr/bin/env bash
if [ "$(id -u)" != "0" ]; then
    echo "Permission Denied. Please run as root"
    exit 1
fi
echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list -y && sudo apt-get update -y && sudo apt-get install rabbitmq-server -y
sudo apt-get install cmake libboost-dev openssl libssl-dev libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev software-properties-common build-essential mesa-common-dev libgl1-mesa-dev -y
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

if [ ! -d "hooks" ]; then
	echo "You do not have the hooks folder. This is impossible. Something broke. How you do."
	exit 1
fi
(
	#git hooks for automatic astyle and some other stuff if we want
	git config core.hooksPath hooks
)