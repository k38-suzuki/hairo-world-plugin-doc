#! /bin/sh

DIR="cnoid_ws"
DIR2="choreonoid"
DIR3="hairo-world-plugin"
DIR4="build"

sudo apt -y update
sudo apt -y install git

cd ~

if [ ! -d $DIR ]; then
  mkdir $DIR
fi

cd $DIR

if [ ! -d $DIR2 ]; then
  git clone https://github.com/choreonoid/choreonoid.git
fi

cd $DIR2

./misc/script/install-requisites-ubuntu-20.04.sh

cd ext

if [ ! -d $DIR3 ]; then
  git clone https://github.com/k38-suzuki/hairo-world-plugin.git
fi

cd ..

if [ ! -d $DIR4 ]; then
  mkdir $DIR4
fi

cd $DIR4

cmake ..
make -j8
