#include "delay_ms.h"
#include "main.h"

#if(FREQ_OSC == 12000000)
#define TIME_SCALE 123
#elif(FREQ_OSC == 11059200)
#define TIME_SCALE 113
#elif(FREQ_OSC == 8000000)
#define TIME_SCALE 218
#else
#error "No any delay_ms for that FREQ_OSC"
#endif

void delay_ms(unsigned int t_delay_ms)
{
	unsigned int i_x, y;
	for(i_x = 0; i_x < t_delay_ms; i_x++)
	{
		for(y = 0; y < TIME_SCALE; y++)
		{
			// Khong lam gi ca
		}
	}
}