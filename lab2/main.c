/*
    Lab2 - Functions in C

    Navigate to the calc_area.c to finish the CalcArea() function.

    To launch the UART serial connection, open the terminal and run:
    'picocom -b 115200 -d 8 -p 1 -y n /dev/ttyACM0'.
    Don't forget to restart the launch board!
*/

#include "calc_area.h"
#include "verify.h"

#define BUF_SIZE 100

int main(void) {
    uint32_t length, width, area;
    char input_str[BUF_SIZE];
    ConfigureUART();
    UARTprintf("\nThis program calculates areas of rectangular rooms.\n");
    while (true) {
        UARTprintf("\nGive length: "); 
        UARTgets(input_str, BUF_SIZE);
        length = atoi(input_str);
        UARTprintf("\nGive width: ");  
        UARTgets(input_str, BUF_SIZE);
        width = atoi(input_str);
        area = CalcArea(length, width); // student submitted function
        UARTprintf("\nArea of the room = %d\n", area);
    }
}
