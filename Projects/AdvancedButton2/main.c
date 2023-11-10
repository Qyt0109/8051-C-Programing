#include "main.h"

void setup()
{
	// setup code here, to run once:
	BUTTON_PIN = LOW;		// Active high button
	LED_PIN = LOW;			// Active high led
}

void loop()
{
	// code section to run repeatedly:
	BUTTON_PIN = LOW;
	if(BUTTON_PIN == HIGH)
	{
		delay_ms(20);
		LED_PIN = !LED_PIN;
		while(BUTTON_PIN == HIGH)
		{
			// Waiting for button to be released
		}
	}
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}