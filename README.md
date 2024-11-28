# BESLabs

## Basics of Embedded Systems Labs catalogue

In this repository you will find all of the labs that are required for completion during the IAS0230 course in TalTech.

## Requirements
Linux (or WSL), VS Code, openOCD, ARM compilers (arm-none-eabi), Cortex Debug VS Code extension is required to run and debug these labs. Place the whole labs catalogue folder under Tivaware/examples/. For additional information go to the [Moodle wiki](https://moodle.taltech.ee/mod/wiki/view.php?id=622173).

## Usage
Open the folder of any lab in VS Code. Open the terminal and type:  
```make```  
To build the lab code and  
```../flash.sh```  
to flash the code on to the board.

To run the tests, navigate to
```cd test```
in any lab and then build the unit tests
```make```

This will build the function that would be tested and there is no need to build the whole lab in order to test.

To establish UART connection, run
```../uart.sh```
from the lab folder.

## Lab assistance
Anton Jaštšuk: ajasts@taltech.ee  
Uljana Reinsalu: uljana.reinsalu@taltech.ee

## Authors and acknowledgment
Anton Jaštšuk  
Uljana Reinsalu  
Nazrul Nazeer  
Tatsuki Ishikawa  

Jonathan Valvano  
Daniel Valvano  
Ramesh Yerraballi