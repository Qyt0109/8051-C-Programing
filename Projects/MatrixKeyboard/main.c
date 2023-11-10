#include "main.h"
/*
		COL0 COL1 COL2 COL3   
		 0		1		 2		4		ROW0
		 5		6		 7		8		ROW0
		 9	 10		11	 12		ROW0
		13	 14		15	 16		ROW0
*/

unsigned char code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
unsigned char code SEVEN_SEGMENT_LED_CATHODE_CODES[] 	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void setup()
{
	// setup code here, to run once:
}


unsigned char display_key;

void loop()
{
	// code section to run repeatedly:
	char key_pressed = checkPressedButtonMatrixKeyboard4x4();
	if(key_pressed != -1)
		display_key = key_pressed;
	SEVEN_SEGMENT_LED_DATA_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[display_key];
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}