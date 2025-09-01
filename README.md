# BESLabs

## Basics of Embedded Systems Labs catalogue

In this repository you will find all of the labs that are required for completion during the IAS0230 course in TalTech.

## Requirements
Linux (or WSL), VS Code, openOCD, ARM compilers (arm-none-eabi), Cortex Debug VS Code extension is required to run and debug these labs. Place the whole labs catalogue folder under Tivaware/examples/. For additional information regarding installation see [Installation guide](EK-TM4C123GXL%20Tools%20Setup%20Guide.pdf) (start from step 6 if using class computers).

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

### Lab contents (each has a unit test and a grader if not said otherwise)
1. [Simple I/O](lab1)
2. [Functions in C](lab2) (**No grader**)
3. [Port init, delay, LED control](lab3)
4. [Loop sequence, subroutines](lab4)
5. [Breadboard circuit building](lab5)
6. [µC debugging](lab6)
7. [Interrupts and buzzer](lab7) (**No unit tests**)
8. [FSM](lab8) (**No unit tests**)
9. [UART, OLED display](lab9) (**No grader**)
10. [DAC](lab10) (**Unit tests as grader**)
11. [ADC, slide potentiometer](lab11) (**Unit tests as grader**)
12. [Low power mode](lab12) (**No unit tests**)
13. [Final game project](lab_final) (**No unit tests or grader**)

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