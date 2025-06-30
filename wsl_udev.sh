sudo service udev restart
sudo udevadm control --reload
sudo udevadm trigger
sudo modprobe vhci-hcd # To fix usbipd: error: WSL kernel is not USBIP capable; update with 'wsl --update'.
