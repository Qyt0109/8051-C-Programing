#ifndef MATRIX_LED_5X7_H
#define MATRIX_LED_5X7_H

/* Example port.h
sbit MATRIX_LED_5X7_COL_0 = P2^0;
sbit MATRIX_LED_5X7_COL_1 = P2^1;
sbit MATRIX_LED_5X7_COL_2 = P2^2;
sbit MATRIX_LED_5X7_COL_3 = P2^3;
sbit MATRIX_LED_5X7_COL_4 = P2^4;

sbit MATRIX_LED_5X7_ROW_0 = P3^0;
sbit MATRIX_LED_5X7_ROW_1 = P3^1;
sbit MATRIX_LED_5X7_ROW_2 = P3^2;
sbit MATRIX_LED_5X7_ROW_3 = P3^3;
sbit MATRIX_LED_5X7_ROW_4 = P3^4;
sbit MATRIX_LED_5X7_ROW_5 = P3^5;
sbit MATRIX_LED_5X7_ROW_6 = P3^6;
*/

void MATRIX_LED_5X7_loadRowData(unsigned char row_data);
#define MATRIX_LED_5X7_DELAY_MS 1

void MATRIX_LED_5X7_fastDisplay(unsigned char *p_code_arr, unsigned char off_set, unsigned char spacing);

#endif