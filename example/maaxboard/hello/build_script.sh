#!/bin/bash

export PATH=/host/mk-manifest/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin:$PATH
sudo rm -rf build
sudo mkdir build
sudo rm -rf hello-build
sudo mkdir hello-build
cd build
sudo cmake ..
sudo make 
