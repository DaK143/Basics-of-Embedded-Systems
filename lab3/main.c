/*
    Lab3 - Port initialization, Delay, LED control

    Navigate to the led_control.c to finish the SetOrToggleLED() function.

    To launch the UART serial connection, open the terminal and run:
    'sudo picocom -b 115200 -d 8 -p 1 -y n /dev/ttyACM0'.
    Don't forget to restart the launch board!
*/

#include "led_control.h"
#include "verify.h"

#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile uint32_t *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile uint32_t *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // Port F Clock Gating Control

void PortFInit(void);
void Delay100ms(uint32_t times);

int main(void){
    PortFInit(); // Student submitted subroutine
    BESGrader();
    uint32_t sw1;  // input from PF4
    uint32_t out;  // output for PF2
    while (true) {
        // Complete this functionality!
    }
}

/* 
    \brief Subroutine to initialize port F pins for input and output.
    PF4 is SW1 input.
    PF2 is output to the LED.

    \param None
    \return None
    \note Set the LED to be initially ON at the end of the initialization. Bit setting
    doesn't affect other bits.
*/
void PortFInit(void) {
    // Complete this function!
    volatile uint32_t delay;
    // Turn on the clock for Port F
    // Allow time for clock to start
    // Disable analog on PF4 and PF2 AMSEL
    // Clear PF4 and PF2 bit fields PCTL to configure as GPIO
    // PF4 input, PF2 output
    // Clear PF4 and PF2 bits AFSEL to disable alternate functions
    // Set PF4 PUR to activate an internal pullup resistor
    // Set PF4 and PF2 bits DEN to enable digital
    // Set PF2 DATA so LED is initially ON
}

#define DELAY_100MS 146500 // ~100ms

/*
    \brief Subroutine to delay 100 milliseconds N times
    \param times Number of times to delay 100 ms
    \return None
    \note Assumes 16 MHz clock
*/
void Delay100ms(uint32_t times) {
    for (; times > 0; times--) {
        for (volatile uint32_t i = DELAY_100MS; i > 0; i--) {}
    }
}
