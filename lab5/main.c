/*
    Lab5 - Breadboard circuit building

    Navigate to the led_interface.c to finish the SetOrToggleLED() function.
    Finish main function and PortE initialization.
*/

#include "led_interface.h"
#include "verify.h"

#define GPIO_PORTE_DATA_R       (*((volatile uint32_t *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile uint32_t *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile uint32_t *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile uint32_t *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile uint32_t *)0x4002451C))
#define GPIO_PORTE_AMSEL_R      (*((volatile uint32_t *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile uint32_t *)0x4002452C))
#define SYSCTL_RCGC2_R          (*((volatile uint32_t *)0x400FE108))
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control

void PortEInit(void);
void Delay100ms(uint32_t times);

int main(void){
    PortEInit(); // Student submitted subroutine
    BESGrader();
    uint32_t sw;   // input from PE0
    uint32_t out;  // output for PE1
    while (true) {
        // Complete this functionality!
    }
}

/* 
    \brief Subroutine to initialize port E pins for input and output.
    PE0 is switch input.
    PE1 is output to the LED.

    \param None
    \return None
    \note Set the LED to be initially ON at the end of the initialization. Bit setting
    doesn't affect other bits.
*/
void PortEInit(void) {
    // Complete this function!
    volatile uint32_t delay;
    // Turn on the clock for Port E
	// Allow time for clock to start
	// Disable analog on PE1 and PE0 AMSEL
	// Clear PE1 and PE0 bit fields PCTL to configure as GPIO
	// PE0 in, PE1 out
	// Clear PE1 and PE0 bits AFSEL to disable alternate functions
	// Clear PE1 and PE0 PUR
	// Set PE1 and PE0 bits DEN to enable digital
	// Set PE1 so LED is initially ON      
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
