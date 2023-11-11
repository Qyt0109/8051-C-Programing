#include "main.h"

byte code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

void setup()
{
	// setup code here, to run once:
}

void displayRandomValueTo7SegmentLed(unsigned char value)
{
	SEVEN_SEGMENT_LED_DATA_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[value % 6 + 1];	// Random 1 - 6
}

void checkButtonToRandomValue()
{
	unsigned char random_value;
	BUTTON_PIN = LOW;
  if(BUTTON_PIN == HIGH)
  {
  	while(BUTTON_PIN == HIGH)
  	{
  		// Waiting for button to be released
			random_value++;
  	}
		displayRandomValueTo7SegmentLed(random_value);
  }
}

void loop()
{
	// code section to run repeatedly:
	checkButtonToRandomValue();
}

void main()
{
	setup();
	while(TRUE)
	{
		loop();
	}
}