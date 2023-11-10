#include "main.h"

unsigned char MATRIX_LED_5X7_CODES[16][5]  = {{0xC1, 0xAE, 0xB6, 0xBA, 0xC1},		// 0
																							{0x7F, 0xBD, 0x00, 0xBF, 0x7F},		// 1
																							{0x1D, 0x2E, 0x36, 0x36, 0x39},		// 2
																							{0x5D, 0x3E, 0x36, 0x36, 0x49},		// 3
																							{0x67, 0x6B, 0x6D, 0x00, 0x6F},		// 4
																							{0x50, 0x36, 0x36, 0x36, 0x4E},		// 5
																							{0x41, 0x36, 0x36, 0x36, 0x4D},		// 6
																							{0x7E, 0x7E, 0x0E, 0x76, 0x78},		// 7
																							{0x49, 0x36, 0x36, 0x36, 0x49},		// 8
																							{0x59, 0x36, 0x36, 0x36, 0x41},		// 9
																							{0x01, 0x76, 0x76, 0x76, 0x01},		// A
																							{0x00, 0x36, 0x36, 0x36, 0x49},		// B
																							{0x41, 0x3E, 0x3E, 0x3E, 0x5D},		// C
																							{0x00, 0xBE, 0xBE, 0xBE, 0x41},		// D
																							{0x00, 0x36, 0x36, 0x36, 0x3E},		// E
																							{0x00, 0x76, 0x76, 0x76, 0x7E}};	// F

#define NUMBER_OF_MATRIX_LEDS 4
#define OFFSET 0
#define SPACING 5
																							
void printMatrixLed5x7_ColData(unsigned char col_data)
{
	unsigned char bit_index;
	for(bit_index = 0; bit_index < 7; bit_index++)
	{
		IC74595_DS_ROW_PIN = col_data & (0x40 >> bit_index);	// Push bit 0 1 2 3 4 5 6 7 in queue order
		IC74595_SH_CP_ROW_PIN = LOW;		// Shift latch pulse
		IC74595_SH_CP_ROW_PIN = HIGH;
	}
}

void printMatrixLed5x7_ColDataAtColIndex(unsigned char col_index, unsigned char *p_col_data_codes)
{
	unsigned char col_data = *(p_col_data_codes + (col_index % 5));
	printMatrixLed5x7_ColData(col_data);
}

void printMatrixLed5x7_ColAtColIndex(unsigned char col_index, unsigned char number_of_matrix_leds)
{
	unsigned int index;
	for(index = 0; index < 5 * number_of_matrix_leds; index++)
	{
		IC74595_DS_COL_PIN = !((index + col_index + 1) % 5);	// Push bit 0 1 2 3 4 5 6 7 in queue order
		IC74595_SH_CP_COL_PIN = LOW;		// Shift latch pulse
		IC74595_SH_CP_COL_PIN = HIGH;
	}
}

void printMatrixLed5x7_OutputAll()
{
	IC74595_ST_CP_PIN = LOW;		// Output all
	IC74595_ST_CP_PIN = HIGH;
}

void printMatrixLed5x7(unsigned char *p_codes, unsigned char number_of_matrix_leds, unsigned char offset, unsigned char spacing)
{
	// col_data = arr[code_index][col_index];
	// col_data = *(arr + code_index * 5 + col_index);
	unsigned char col_data, code_index, col_index;
	for(col_index = 0; col_index < 5; col_index++)
	{
		for(code_index = 0; code_index < number_of_matrix_leds; code_index++)
		{
			printMatrixLed5x7_ColDataAtColIndex(col_index, p_codes + code_index * 5);
		}
		printMatrixLed5x7_ColAtColIndex(col_index, number_of_matrix_leds);
		printMatrixLed5x7_OutputAll();
		//delay_ms(1000);
	}
}

void printMatrixLed5x7_col_index(unsigned char *p_codes_arr, unsigned char col_index, unsigned char number_of_matrix_leds, unsigned char offset, unsigned char spacing)
{
	unsigned char code_data, bit_index, space;
	code_data = *(p_codes_arr + col_index);
	printMatrixLed5x7_ColData(code_data);
	printMatrixLed5x7_OutputAll();
}


void setup()
{
	// setup code here, to run once:
}

void loop()
{
	// code section to run repeatedly:
	/*
	unsigned char col_index;
	for(col_index = 0; col_index < 5; col_index++)
	{
		printMatrixLed5x7_col_index(MATRIX_LED_5X7_CODES[0x05], col_index, NUMBER_OF_MATRIX_LEDS, OFFSET, SPACING);
		delay_ms(2000);
	}
	//*/
	unsigned char codes[4][5] =  {MATRIX_LED_5X7_CODES[0x04],
																MATRIX_LED_5X7_CODES[0x03],
																MATRIX_LED_5X7_CODES[0x0A],
																MATRIX_LED_5X7_CODES[0x0F]};
	printMatrixLed5x7(codes, NUMBER_OF_MATRIX_LEDS, OFFSET, SPACING);
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}