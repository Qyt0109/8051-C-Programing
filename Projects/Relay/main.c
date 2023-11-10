#include "main.h"

void setup()
{
	// setup code here, to run once:
	BUTTON_PIN = LOW;	// Active high
	RELAY_PIN = HIGH;	// Active low
}

void loop()
{
	// code section to run repeatedly:
	BUTTON_PIN = LOW;
	if(BUTTON_PIN == HIGH)
	{
		delay_ms(20);
		if(BUTTON_PIN == HIGH)
		{
			RELAY_PIN = !RELAY_PIN;
			while(BUTTON_PIN == HIGH);
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