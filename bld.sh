export SEL4CP_SDK="$HOME/cp/sel4cp/release/sel4cp-sdk-1.2.6"
export PATH="$HOME/cp/compiler_download/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin:$PATH"
rm -r $HOME/cp/sel4cp/tmp_build
$HOME/cp/pyenv/bin/python3.9 dev_build.py --board=maaxboard --example=xhci_stub
sudo cp $HOME/cp/sel4cp/tmp_build/loader.img /var/lib/tftpboot/loader-matt.img
echo 
echo Copied image file to "/var/lib/tftpboot/loader-matt.img".