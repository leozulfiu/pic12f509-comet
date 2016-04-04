/* 
 * File:   main.c
 * Author: Leo Zulfiu
 *
 * Created on 13. Januar 2016, 23:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "conf.h"

#define _XTAL_FREQ 4000000     // oscillator frequency for _delay()

void play_single();
void my_delay_ms(int n);

typedef struct {
    int pulse_width;
    int period;
    int level_counter;
    int max_level;
} Led_state;

int main(int argc, char** argv) {
    int pulse_width = 0;
    int period = 10;
    int level_counter = 0;
    OPTION = 0xDF;
    TRISGPIO = 0b001000;
    GPIO = 0b000000;
    
    while(1) {
        GPIObits.GP0 = 0;
        my_delay_ms(period - pulse_width);
        GPIObits.GP0 = 1;
        my_delay_ms(pulse_width);
        level_counter++;
        if (level_counter == 10) {
            level_counter = 0;
            pulse_width++;
            if (pulse_width == period) {
                pulse_width = 0;
            }
        }
    }
    return (EXIT_SUCCESS);
}

Led_state create_new_led() {
    Led_state led_state;
    led_state.level_counter = 0;
    led_state.period = 10;
    led_state.level_counter = 0;
    led_state.max_level = 10;
}

void update_led_state(Led_state led_state) {
    
}

void my_delay_ms(int n) {
 while(n--) {
  __delay_ms(1);
 }
}

/*
void play_single() {
    GPIObits.GP0 = 1;
    __delay_ms(200);
    GPIObits.GP0 = 0;
    GPIObits.GP1 = 1;
    __delay_ms(200);
    GPIObits.GP1 = 0;
    GPIObits.GP2 = 1;
    __delay_ms(200);
    GPIObits.GP2 = 0;
    GPIObits.GP4 = 1;
    __delay_ms(200);
    GPIObits.GP4 = 0;
    GPIObits.GP5 = 1;
    __delay_ms(200);
    GPIObits.GP5 = 0;
}
*/
