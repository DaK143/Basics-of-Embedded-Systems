#!/bin/bash

# Script for allowing WSL to recognize the connected EK-TM4C123GXL board.
# Must be run once when WSL is run after Windows boot/reboot.
# In Windows: https://learn.microsoft.com/en-us/windows/wsl/connect-usb
sudo service udev restart
sudo udevadm control --reload
sudo udevadm trigger
sudo modprobe vhci-hcd # To fix usbipd: error: WSL kernel is not USBIP capable; update with 'wsl --update'.