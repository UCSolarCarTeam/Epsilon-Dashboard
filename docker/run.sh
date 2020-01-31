#!/bin/bash
CWD="$(cd "$(dirname "$0")" ; pwd -P )"
DIR_OUT="$CWD"/build
DIR_IN="$(dirname "$CWD")"

(cd ../src; make distclean); cd "CWD"
docker run --rm --privileged multiarch/qemu-user-static:register --reset 
docker run --rm -it -v $DIR_IN:/input -v $DIR_OUT:/output ucsolarcar/epsilon-rpi:ubuntu-bionic
