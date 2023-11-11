#include "main.h"

#define LED_DELAY 500

void main()
{
	while(TRUE)
	{
		LED_PIN = !LED_PIN;
		delay_ms(LED_DELAY);
	}
}