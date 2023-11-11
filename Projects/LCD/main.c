#include "main.h"

void setup()
{
	// setup code here, to run once:
	LCD_RW = LOW; // Write
	LCD_turn_screen(ON);
	LCD_print_string("Hello world 123123");
	delay_ms(1000);
	LCD_turn_screen(OFF);
	LCD_print_char('X');
	delay_ms(1000);
	LCD_turn_screen_on_with_cursor(OFF);
}

void loop()
{
	// code section to run repeatedly:
	//P3 = 0;
}

void main()
{
	setup();
	while(TRUE)
	{
		loop();
	}
}