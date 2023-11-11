#include "matrix_keyboard_4x4.h"
#include "..\Common\common.h"
#include "port.h"

char checkPressedButtonMatrixKeyboard4x4()
{
	char key = -1;
	// Checking ROW 0
	MATRIX_KEYBOARD_4X4_ROW_0_PIN = LOW;
	if(MATRIX_KEYBOARD_4X4_COL_0_PIN == LOW)
		key = 0;
	if(MATRIX_KEYBOARD_4X4_COL_1_PIN == LOW)
		key = 1;
	if(MATRIX_KEYBOARD_4X4_COL_2_PIN == LOW)
		key = 2;
	if(MATRIX_KEYBOARD_4X4_COL_3_PIN == LOW)
		key = 3;
	MATRIX_KEYBOARD_4X4_ROW_0_PIN = HIGH;
	// Checking ROW 1
	MATRIX_KEYBOARD_4X4_ROW_1_PIN = LOW;
	if(MATRIX_KEYBOARD_4X4_COL_0_PIN == LOW)
		key = 4;
	if(MATRIX_KEYBOARD_4X4_COL_1_PIN == LOW)
		key = 5;
	if(MATRIX_KEYBOARD_4X4_COL_2_PIN == LOW)
		key = 6;
	if(MATRIX_KEYBOARD_4X4_COL_3_PIN == LOW)
		key = 7;
	MATRIX_KEYBOARD_4X4_ROW_1_PIN = HIGH;
	// Checking ROW 2
	MATRIX_KEYBOARD_4X4_ROW_2_PIN = LOW;
	if(MATRIX_KEYBOARD_4X4_COL_0_PIN == LOW)
		key = 8;
	if(MATRIX_KEYBOARD_4X4_COL_1_PIN == LOW)
		key = 9;
	if(MATRIX_KEYBOARD_4X4_COL_2_PIN == LOW)
		key = 10;
	if(MATRIX_KEYBOARD_4X4_COL_3_PIN == LOW)
		key = 11;
	MATRIX_KEYBOARD_4X4_ROW_2_PIN = HIGH;
	// Checking ROW 3
	MATRIX_KEYBOARD_4X4_ROW_3_PIN = LOW;
	if(MATRIX_KEYBOARD_4X4_COL_0_PIN == LOW)
		key = 12;
	if(MATRIX_KEYBOARD_4X4_COL_1_PIN == LOW)
		key = 13;
	if(MATRIX_KEYBOARD_4X4_COL_2_PIN == LOW)
		key = 14;
	if(MATRIX_KEYBOARD_4X4_COL_3_PIN == LOW)
		key = 15;
	MATRIX_KEYBOARD_4X4_ROW_3_PIN = HIGH;
	
	return key;
}