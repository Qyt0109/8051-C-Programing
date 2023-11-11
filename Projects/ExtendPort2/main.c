#include "main.h"

byte code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

void setup()
{
	// setup code here, to run once:
	
}

unsigned char code_index;

void loop()
{
	// code section to run repeatedly:
	byte bytes_arr[3];
	unsigned char byte_index;
	for(byte_index = 0; byte_index < sizeof(bytes_arr)/sizeof(bytes_arr[0]); byte_index++)
	{
		bytes_arr[byte_index] = SEVEN_SEGMENT_LED_ANODE_CODES[(code_index + byte_index) % 10];
	}
	code_index += sizeof(bytes_arr);
	
	IC74595_pushBytes(bytes_arr, sizeof(bytes_arr));
	delay_ms(1000);
}

void main()
{
	setup();
	while(TRUE)
	{
		loop();
	}
}