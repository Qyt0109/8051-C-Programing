#include "main.h"

byte code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

void setup()
{
	// setup code here, to run once:
	
}

void loop()
{
	// code section to run repeatedly:
	IC74595_pushByte(SEVEN_SEGMENT_LED_ANODE_CODES[6]);
	delay_ms(500);
	IC74595_pushByte(SEVEN_SEGMENT_LED_ANODE_CODES[9]);
	delay_ms(500);
}

void main()
{
	setup();
	while(TRUE)
	{
		loop();
	}
}