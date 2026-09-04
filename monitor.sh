#!/usr/bin/env bash

# Find first available serial device and run tio serial monitor

PORT=$(ls /dev/ttyACM* /dev/ttyUSB* /dev/cu.usbmodem* /dev/cu.usbserial* 2> /dev/null | head -n 1)

if [ -n "$PORT" ]; then
    echo "Detected MCU on $PORT..."
    tio "$PORT"
else
    echo "Error: No serial device (/dev/ttyACM* or /dev/cu.usbmodem*) found!"
    exit 1
fi
