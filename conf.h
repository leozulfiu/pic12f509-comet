/* 
 * File:   conf.h
 * Author: Leo Zulfiu
 *
 * Created on 13. Januar 2016, 22:59
 */

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config OSC = IntRC      // Oscillator Selection bits (internal RC oscillator)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection off)
#pragma config MCLRE = OFF      // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is digital input, MCLR internally tied to VDD)