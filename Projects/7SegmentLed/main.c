#include "main.h"

unsigned char code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
unsigned char code SEVEN_SEGMENT_LED_CATHODE_CODES[] 	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void setup()
{
	// setup code here, to run once:
	ANODE_SEVEN_SEGMENT_LED_EN_PIN = HIGH;
	CATHODE_SEVEN_SEGMENT_LED_EN_PIN = LOW;
}

void loop()
{
	// code section to run repeatedly:
	unsigned char index;
	for(index = 0; index <= 0x0F; index++)
	{
		ANODE_SEVEN_SEGMENT_LED_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[index];
		CATHODE_SEVEN_SEGMENT_LED_PORT = SEVEN_SEGMENT_LED_CATHODE_CODES[index];
		ANODE_SEVEN_SEGMENT_LED_EN_PIN = HIGH;
		CATHODE_SEVEN_SEGMENT_LED_EN_PIN = LOW;
		delay_ms(1000);
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