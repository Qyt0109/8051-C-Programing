/*
#define FREQ_OSC 12000000
Hz				MHz
12000000	12
11059200	11.0592
8000000		8
*/

#ifndef DELAY_H
// {
	#define DELAY_H
	
	#include "settings.h"
	
	// FREQ_OSC
	#define FREQ_12MHZ 12000000
	#define FREQ_11_0592MHZ 11059200
	#define FREQ_8MHZ 8000000

	// DELAY_MODE
	#define DELAY_USING_TIMER_0 0x00
	#define DELAY_USING_TIMER_1 0x01
	#define DELAY_USING_FOR_LOOP 0x02
	
	void delay_ms(unsigned int t_delay_ms);
	
	void delay_us(unsigned int t_delay_us);
// }
#endif