#include "matrix_led_5x7.h"
#include "main.h"

void MATRIX_LED_5X7_loadRowData(unsigned char row_data)
{
	MATRIX_LED_5X7_ROW_0 = row_data & 0x01;
	MATRIX_LED_5X7_ROW_1 = row_data & 0x02;
	MATRIX_LED_5X7_ROW_2 = row_data & 0x04;
	MATRIX_LED_5X7_ROW_3 = row_data & 0x08;
	MATRIX_LED_5X7_ROW_4 = row_data & 0x10;
	MATRIX_LED_5X7_ROW_5 = row_data & 0x20;
	MATRIX_LED_5X7_ROW_6 = row_data & 0x40;
}

#define MATRIX_LED_5X7_DELAY_MS 1

void MATRIX_LED_5X7_fastDisplay(unsigned char *p_code_arr, unsigned char off_set, unsigned char spacing)
{
	unsigned char code_index, row_data;
	code_index = 0;
	row_data = (code_index + off_set) % (5 + spacing) < 5 ? *(p_code_arr + (code_index + off_set) % (5 + spacing)) : 0x7F;
	MATRIX_LED_5X7_loadRowData(row_data);
	MATRIX_LED_5X7_COL_0 = HIGH;
	delay_ms(MATRIX_LED_5X7_DELAY_MS);
	MATRIX_LED_5X7_COL_0 = LOW;
	
	code_index++;
	row_data = (code_index + off_set) % (5 + spacing) < 5 ? *(p_code_arr + (code_index + off_set) % (5 + spacing)) : 0x7F;
	MATRIX_LED_5X7_loadRowData(row_data);
	MATRIX_LED_5X7_COL_1 = HIGH;
	delay_ms(MATRIX_LED_5X7_DELAY_MS);
	MATRIX_LED_5X7_COL_1 = LOW;
	
	code_index++;
	row_data = (code_index + off_set) % (5 + spacing) < 5 ? *(p_code_arr + (code_index + off_set) % (5 + spacing)) : 0x7F;
	MATRIX_LED_5X7_loadRowData(row_data);
	MATRIX_LED_5X7_COL_2 = HIGH;
	delay_ms(MATRIX_LED_5X7_DELAY_MS);
	MATRIX_LED_5X7_COL_2 = LOW;
	
	code_index++;
	row_data = (code_index + off_set) % (5 + spacing) < 5 ? *(p_code_arr + (code_index + off_set) % (5 + spacing)) : 0x7F;
	MATRIX_LED_5X7_loadRowData(row_data);
	MATRIX_LED_5X7_COL_3 = HIGH;
	delay_ms(MATRIX_LED_5X7_DELAY_MS);
	MATRIX_LED_5X7_COL_3 = LOW;
	
	code_index++;
	row_data = (code_index + off_set) % (5 + spacing) < 5 ? *(p_code_arr + (code_index + off_set) % (5 + spacing)) : 0x7F;
	MATRIX_LED_5X7_loadRowData(row_data);
	MATRIX_LED_5X7_COL_4 = HIGH;
	delay_ms(MATRIX_LED_5X7_DELAY_MS);
	MATRIX_LED_5X7_COL_4 = LOW;
}