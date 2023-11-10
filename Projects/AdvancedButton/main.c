#include "main.h"

void setup()
{
	// setup code here, to run once:
	button_pull_up = HIGH;	// Init logic High for Low Active button
	led_pull_up = LOW;	// Init led off
}

// Advanced Button checking
void checkPressedToToogleLed()
{
	// Init logic High before checking if Low Active button is pressed
	button_pull_up = HIGH;
	if(button_pull_up == LOW)
	{
		delay_ms(20);	// Chong doi phim
		if(button_pull_up == LOW)
		{
			led_pull_up = !led_pull_up;
			while(button_pull_up == LOW);	// Wait for button release
		}
	}
}

void loop()
{
	// code section to run repeatedly:
	checkPressedToToogleLed();
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}