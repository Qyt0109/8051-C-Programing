#include "main.h"

void setup()
{
	// setup code here, to run once:
	button_pull_down = LOW;
	button_pull_up = HIGH;
	led_pull_down = LOW;
	led_pull_up = LOW;
}

void loop()
{
	// code section to run repeatedly:
	led_pull_down = button_pull_down == HIGH;
	led_pull_up = button_pull_up == LOW;
}

void main()
{
	setup();
	while(TRUE)
	{
		loop();
	}
}