#include "led_control.h"

uint32_t SetOrToggleLED(uint32_t sw, uint32_t led_val) {

    if(sw == 0){
        led_val ^= 0x04;
    }
    else{
        led_val |= 0x04;
    }

    return led_val;
}
