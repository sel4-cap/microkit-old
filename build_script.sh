# Build SDK
sudo rm -r tmp_build
curl --output compiler.xz https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-a/10.2-2020.11/binrel/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf.tar.xz
tar -xvf compiler.xz
rm -r compiler.xz
export PATH=${PWD}/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin:$PATH
python3 build_sdk.py --sel4 ../seL4
# Build picolibc
rm -rf ../picolibc/picolibc-microkit/
mkdir ../picolibc/picolibc-microkit/
cd ../picolibc/picolibc-microkit/
rm -rf ../../picolibc_build
mkdir ../../picolibc_build
../scripts/do-aarch64-configure-nocrt -Dprefix=${PWD}/../../picolibc_build
ninja 
ninja install
# Build application 
cd ../../microkit
rm -rf example/maaxboard/uboot-driver-example/build
mkdir example/maaxboard/uboot-driver-example/build
rm -rf example/maaxboard/uboot-driver-example/hello-build
mkdir example/maaxboard/uboot-driver-example/hello-build
cd example/maaxboard/uboot-driver-example/build
cmake .. 
make 