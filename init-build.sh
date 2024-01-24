#!/bin/bash


# Assign the first argument to a variable
string_argument="$1"

# Check if the string argument is provided
if [ -z "$string_argument" ]; then
    echo "No argument provided. Please provide a string argument."
    exit 1
else
    echo "The provided string argument is: $string_argument"
    # Add your code here that should run with the string argument
fi


# Build SDK
EXTRACTED_DIR="gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf"
if [ ! -d "$EXTRACTED_DIR" ]; then
    curl --output compiler.xz https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-a/10.2-2020.11/binrel/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf.tar.xz
    tar -xvf compiler.xz
    rm -r compiler.xz
fi
export PATH=${PWD}/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin:$PATH
echo "Do you want to build the sdk? (yes/no)"
read user_input

# Convert the input to lowercase (optional, for more flexible input handling)
user_input=$(echo "$user_input" | tr '[:upper:]' '[:lower:]')
if [ "$user_input" = "yes" ]; then
    python3 build_sdk.py --sel4 ../seL4
fi

# Build picolibc
echo "Do you want to build picolibc? (yes/no)"
read user_input1

# Convert the input to lowercase (optional, for more flexible input handling)
user_input1=$(echo "$user_input1" | tr '[:upper:]' '[:lower:]')

if [ "$user_input1" = "yes" ]; then
    rm -rf ../picolibc/picolibc-microkit/
    mkdir ../picolibc/picolibc-microkit/
    cd ../picolibc/picolibc-microkit/
    rm -rf ../../picolibc_build
    mkdir ../../picolibc_build
    ../scripts/do-aarch64-configure-nocrt -Dprefix=${PWD}/../../picolibc_build
    ninja 
    ninja install
fi

# Build application 
cd ../../microkit
rm -rf example/maaxboard/$string_argument/build
mkdir example/maaxboard/$string_argument/build
rm -rf example/maaxboard/$string_argument/hello-build
mkdir example/maaxboard/$string_argument/hello-build
cd example/maaxboard/$string_argument/build
cmake .. 
make 