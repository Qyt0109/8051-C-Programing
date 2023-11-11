#include "..\Common\common.h"
#include "port.h"
#include "ic74595.h"

void IC74595_pushByte(byte byte_value)
{
	unsigned char bit_index;
	for(bit_index = 0; bit_index < 8; bit_index++)
	{
		IC74595_DS_PIN = byte_value & (0x80 >> bit_index);	// Push bit
		IC74595_SH_CP_PIN = LOW;		// Shift latch pulse
		IC74595_SH_CP_PIN = HIGH;
	}
	IC74595_ST_CP_PIN = LOW;	// Output latch pulse
	IC74595_ST_CP_PIN = HIGH;
}

void IC74595_pushBytes(byte *p_bytes_arr, unsigned char number_of_bytes)
{
	unsigned char byte_index;
	for(byte_index = 0; byte_index < number_of_bytes; byte_index++)
	{
		byte byte_value = *(p_bytes_arr + byte_index);
		unsigned char bit_index;
		for(bit_index = 0; bit_index < 8; bit_index++)
		{
			IC74595_DS_PIN = byte_value & (0x80 >> bit_index);	// Push bit
			IC74595_SH_CP_PIN = LOW;		// Shift latch pulse
			IC74595_SH_CP_PIN = HIGH;
		}
	}
	IC74595_ST_CP_PIN = LOW;	// Output latch pulse
	IC74595_ST_CP_PIN = HIGH;
}