#include "delay.h"

/* Example settings.h
#ifndef SETTINGS_H
// {
	#define SETTINGS_H
	
	...
	#define FREQ_OSC FREQ_12MHZ
	#define DELAY_MODE DELAY_USING_FOR_LOOP
	...
// }
#endif
*/

#ifndef FREQ_OSC
// {
	#error "FREQ_OSC not defined!"
// }
#endif

#ifndef DELAY_MODE
// {
	#error "DELAY_MODE not defined!"
// }
#endif


#if (defined(FREQ_OSC) && defined(DELAY_MODE))
// {
	#if (DELAY_MODE == DELAY_USING_FOR_LOOP)
	// {
		#if (FREQ_OSC == FREQ_12MHZ)
		// {
			#define TIME_SCALE 123
		// }
		#elif (FREQ_OSC == FREQ_11_0592MHZ)
		// {
			#define TIME_SCALE 113
		// }
		#elif (FREQ_OSC == FREQ_8MHZ)
		// {
			#define TIME_SCALE 218
		// }
		#else
		// {
			#error "No delay for that FREQ_OSC"
		// }
		#endif
		
		#ifdef TIME_SCALE
		// {
			void delay_ms(unsigned int t_delay_ms)
			{
				unsigned int x, y;
				for (x = 0; x < t_delay_ms; x++)
				{
					for (y = 0; y < TIME_SCALE; y++)
					{
						// Do nothing
					}
				}
			}
		// }
		#endif
	// }
	#elif (DELAY_MODE == DELAY_USING_TIMER_0)
	// {
	
	// }
	#elif (DELAY_MODE == DELAY_USING_TIMER_1)
	// {
	
	// }
	#else
	// {
		#error "Invalid DELAY_MODE!"
	// }
	#endif
// }
#endif