#!/usr/bin/env bash

# Attaches device to WSL2 using usbipd-win

HWID=$(usbipd.exe list | tr -d '\r' | awk '/Connected:/{flag=1; next} /Persisted:/{flag=0} flag' | grep -i "Stellaris" | awk '{print $2}' | head -n 1)
if [[ -n "$HWID" ]]; then
    echo "Found target device with Hardware ID: $HWID"
    echo "Attaching to WSL..."
    usbipd.exe attach -w -i "$HWID"
else
    echo "Error: Target board not detected. Ensure it is plugged in."
    exit 1
fi
