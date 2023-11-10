#include "main.h"

#define LED_PORT P0

#define t_ms 500


void main()
{
	while(1)
	{
		unsigned char x;
		LED_PORT = 0xAA;
		for(x = 0; x < 8; x++)
		{
			delay_ms(t_ms);
			LED_PORT = ~LED_PORT;
		}
		LED_PORT = 0xFF;
		for(x = 0; x < 8; x++)
		{
			delay_ms(t_ms);
			LED_PORT = ~LED_PORT;
		}
		LED_PORT = 0x0F;
		for(x = 0; x < 4; x++)
		{
			delay_ms(t_ms);
			LED_PORT <<= 1;
		}
		for(x = 0; x < 5; x++)
		{
			delay_ms(t_ms);
			LED_PORT >>= 1;
		}
		LED_PORT = 0x07;
		for(x = 0; x < 5; x++)
		{
			delay_ms(t_ms);
			LED_PORT <<= 1;
		}
		for(x = 0; x < 6; x++)
		{
			delay_ms(t_ms);
			LED_PORT >>= 1;
		}
	}
}