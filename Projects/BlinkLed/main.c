#include "main.h"

sbit LED_PIN = P0^0;

void main()
{
	while(1)
	{
		LED_PIN = !LED_PIN;
		delay_ms(500);
	}
}