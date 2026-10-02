/*
    Lab3 - Port initialization, Delay, LED control

    Navigate to the led_control.c to finish the SetOrToggleLED() function.
    Finish the main function and the PortF initialization.
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

        sw1 = ((GPIO_PORTF_DATA_R & 0x10) >> 4);

        Delay100ms(1);

        out = SetOrToggleLED(sw1, GPIO_PORTF_DATA_R);

        GPIO_PORTF_DATA_R = out;
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
*/void PortFInit(void) {
    volatile uint32_t delay;

    // Turn on the clock for Port F
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;

    // Allow time for clock to start
    delay = SYSCTL_RCGC2_R;

    // Disable analog on PF4 and PF2
    GPIO_PORTF_AMSEL_R &= ~0x14;

    // Configure PF4 and PF2 as GPIO
    GPIO_PORTF_PCTL_R &= ~0x000F0F00;

    // PF4 input
    GPIO_PORTF_DIR_R &= ~0x10;

    // PF2 output
    GPIO_PORTF_DIR_R |= 0x04;

    // Disable alternate functions
    GPIO_PORTF_AFSEL_R &= ~0x14;

    // Activate pull-up resistor on PF4
    GPIO_PORTF_PUR_R |= 0x10;

    // Enable digital I/O
    GPIO_PORTF_DEN_R |= 0x14;

    // LED initially ON
    GPIO_PORTF_DATA_R |= 0x04;
}

#define DELAY_100MS 160000 // ~100ms

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
