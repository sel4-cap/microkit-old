# Build sdk
sudo rm -r tmp_build
curl --output compiler.xz https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-a/10.2-2020.11/binrel/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf.tar.xz
tar -xvf compiler.xz
rm -r compiler.xz
export PATH=${PWD}/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin:$PATH
python3 build_sdk.py --sel4 ../seL4
# Build picolibc
sudo rm -rf ../picolibc/picolibc-microkit/
sudo mkdir ../picolibc/picolibc-microkit/
cd ../picolibc/picolibc-microkit/
mkdir ../../picolibc_build
sudo ../scripts/do-aarch64-configure-nocrt -Dprefix=${PWD}/../../picolibc_build
sudo ninja 
sudo ninja install