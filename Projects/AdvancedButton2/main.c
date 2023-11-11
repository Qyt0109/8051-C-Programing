#include "main.h"

void setup()
{
	// setup code here, to run once:
	
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
	while(TRUE)
	{
		loop();
	}
}