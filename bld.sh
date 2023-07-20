#!/bin/bash
FILE_LOCATION="/var/lib/tftpboot/loader-josh.img"
export SEL4CP_SDK="$HOME/cp/sel4cp/release/sel4cp-sdk-1.2.6"
export PATH="$HOME/cp/compiler_download/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin:$PATH"
rm -r $HOME/cp/sel4cp/tmp_build
$HOME/cp/pyenv/bin/python3.9 dev_build.py --board=maaxboard --example=xhci_stub
echo 
if [ $? -gt 0 ]; then
    echo "Error(s) $? detected, file not copied"
else
    sudo cp $HOME/cp/sel4cp/tmp_build/loader.img $FILE_LOCATION
    echo Copied image file to "$FILE_LOCATION".
fi
