#include "main.h"
/*
		COL0 COL1 COL2 COL3   
		 0		1		 2		4		ROW0
		 5		6		 7		8		ROW0
		 9	 10		11	 12		ROW0
		13	 14		15	 16		ROW0
*/

byte code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

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
	while(TRUE)
	{
		loop();
	}
}