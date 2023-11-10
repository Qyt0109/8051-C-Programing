#ifndef IC74595_H
#define IC74595_H

/* Example port.h
sbit IC74595_SH_CP_PIN = P2^0;	// Shift
sbit IC74595_DS_PIN = P2^1;			// Bit data
sbit IC74595_ST_CP_PIN = P2^2;	// Set output
*/

void IC74595_pushByte(unsigned char byte_value);

void IC74595_pushBytes(unsigned char *p_bytes_arr, unsigned char number_of_bytes);

#endif